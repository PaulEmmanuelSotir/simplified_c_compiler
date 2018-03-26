#include <iostream>
#include <unordered_map>

#include "StaticAnalysis.h"

namespace StaticAnalysis {

    Variable::Variable(SyntaxModel::Identifier name, SyntaxModel::Type* type, SyntaxModel::Definition::size_constant* array_size, SyntaxModel::Expression* init_value)
        : name(name)
        , type(type)
        , array_size(array_size)
        , init_value(init_value)
    {
    }

    Variable::Variable(const SyntaxModel::Definition& def, const size_t index)
        : name(def.names[index])
        , type(def.type)
        , array_size((def.sizes.size() > index) ? *utils::get_at(def.sizes, index) : nullptr)
        , init_value((def.init_values.size() > index) ? *utils::get_at(def.init_values, index) : nullptr)
    {
    }

    StaticAnalyser::StaticAnalyser(const SyntaxModel::Program* ast)
        : _ast(ast)
    {
    }

    void StaticAnalyser::Analyse()
    {
        // Make a set of all variables, variables for which there is a usage will be removed from this set
        std::set<Variable> unused_globals = FindGlobals(_ast->definitions);

        for (const auto* func : _ast->functions) {
            DefineFunctionVariables(func);
            FindFuncVarUsages(func, unused_globals);
        }

        for (const auto& var : unused_globals)
            error<false>("Global variable '", var.name.text, "' is unused.");

        ResolveFunctionCalls();
    }

    std::set<Variable> StaticAnalyser::FindGlobals(const std::list<const SyntaxModel::Definition*>& defs)
    {
        std::set<Variable> unused_globals;
        for (const auto* def : defs) {
            // Add declaration's variables to set
            for (size_t i = 0; i < def->names.size(); ++i) {
                // We make sure we didn't already declared this variable before adding it in global variables vector
                auto var = Variable(*def, i);
                if (std::find(_global_variables.begin(), _global_variables.end(), var) != _global_variables.end())
                    error<true>("Global variable '", var.name.text, "' have already been declared.");
                _global_variables.push_back(var);
                unused_globals.insert(var);
            }

            // We search for variables usages in initialization expression
            for (const auto& init_expr : def->init_values) {
                for (const auto& var_usage : init_expr->getAllChildrenOfType<SyntaxModel::VariableUsage>())
                    ResolveVarUsage(_var_usage_resolution, var_usage, var_usage->name, unused_globals);
                for (const auto& affectation : init_expr->getAllChildrenOfType<SyntaxModel::Affectation>())
                    ResolveVarUsage(_affectation_resolution, affectation, affectation->var, unused_globals);
            }
        }
        return unused_globals;
    }

    void StaticAnalyser::DefineFunctionVariables(const SyntaxModel::Function* func)
    {
        std::vector<Variable> vars;
        vars.reserve(func->definitions.size());

        for (const auto* def : func->definitions) {
            for (size_t i = 0; i < def->names.size(); ++i) {
                auto var = Variable(*def, i);
                if (std::find(vars.begin(), vars.end(), var) != vars.end())
                    error<true>("Local variable '", var.name.text, "' have already been declared in function '", func->id.text, "'.");
                vars.push_back(var);
            }
        }
        _function_variables.emplace(func->unique_id, vars);
    }

    void StaticAnalyser::FindFuncVarUsages(const SyntaxModel::Function* func, std::set<Variable>& unused_globals)
    {
        auto* func_locals = new std::vector<Variable>((*_function_variables.find(func->unique_id)).second);
        auto* unused_locals = new std::set<Variable>(func_locals->cbegin(), func_locals->cend());

        for (auto var_usage : func->getAllChildrenOfType<SyntaxModel::VariableUsage>())
            ResolveVarUsage(_var_usage_resolution, var_usage, var_usage->name, unused_globals, unused_locals, func_locals);
        for (auto affectation : func->getAllChildrenOfType<SyntaxModel::Affectation>())
            ResolveVarUsage(_affectation_resolution, affectation, affectation->var, unused_globals, unused_locals, func_locals);

        // make sure we found at least one usage for each local variable
        for (const auto& var : *unused_locals)
            error<false>("Local variable '", var.name.text, "' is unused in function '", func->id.text, "'.");
    }

    void StaticAnalyser::ResolveFunctionCalls()
    {
        // Make a set of function ids in order to accelerate function lookup
        std::unordered_map<std::string, const SyntaxModel::Function*> func_lookup_table;
        for (const auto* func : _ast->functions)
            func_lookup_table.emplace(func->id.text, func);

        // Resolve function calls
        for (const auto* usage : _ast->getAllChildrenOfType<SyntaxModel::FunctionCall>()) {
            auto it = func_lookup_table.find(usage->func_name.text);
            if (it == func_lookup_table.end())
                error<true>("Function '", usage->func_name.text, "' not declared.");
            else
                _function_call_resolution.emplace(usage->unique_id, it->second);
        }
    }
}
