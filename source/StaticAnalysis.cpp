#include <iostream>

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

    StaticAnalyser::~StaticAnalyser() { delete _ast; }

    void StaticAnalyser::Analyse()
    {
        // Make a set of all variables, variables for which there is a usage will be removed from this set
        std::set<Variable> unused_globals(_global_variables.begin(), _global_variables.end());

        FindGlobals(_ast->definitions, unused_globals);

        for (const auto* func : _ast->functions) {
            DefineFunctionVariables(func);
            FindFuncVarUsage(func, unused_globals);
        }

        for (const auto& var : unused_globals)
            error<false>("Global variable '", var.name.text, "'is unused.");
    }

    void StaticAnalyser::FindGlobals(const std::list<const SyntaxModel::Definition*>& defs, std::set<Variable>& unused_globals)
    {
        for (const auto* def : defs) {
            // Add declaration's variables to set
            for (size_t i = 0; i < def->names.size(); ++i) {
                // We make sure we didn't already declared this variable before adding it in global variables vector
                auto var = Variable(*def, i);
                if (std::find(_global_variables.begin(), _global_variables.end(), var) != _global_variables.end())
                    error<true>("Global variable '", var.name.text, "' have already been declared.");
                _global_variables.push_back(var);
            }

            // We search for variables usages in initialization expression
            for (const auto& init_expr : def->init_values) {
                for (const auto& var_usage : init_expr->getAllChildrenOfType<SyntaxModel::VariableUsage>()) {
                    Variable dummy_var(var_usage->name, nullptr);
                    auto global_it = std::find(_global_variables.begin(), _global_variables.end(), dummy_var);
                    if (global_it != _global_variables.end()) {
                        _var_usage_resolution.emplace(var_usage, *global_it);
                        unused_globals.erase(*global_it);
                    } else
                        error<true>("Global variable '", var_usage->name.text, "' not declared.");
                }
            }
        }
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
        _function_variables.emplace(func->id, vars);
    }

    void StaticAnalyser::FindFuncVarUsage(const SyntaxModel::Function* func, std::set<Variable>& unused_globals)
    {
        auto& func_locals = (*_function_variables.find(func->id)).second;
        std::set<Variable> unused_locals(func_locals.begin(), func_locals.end());

        for (auto var_usage : func->getAllChildrenOfType<SyntaxModel::VariableUsage>()) {
            Variable dummy_var(var_usage->name, nullptr);
            auto global_it = std::find(_global_variables.begin(), _global_variables.end(), dummy_var);
            auto local_it = std::find(func_locals.begin(), func_locals.end(), dummy_var);
            if (global_it != _global_variables.end()) {
                _var_usage_resolution.emplace(var_usage, *global_it);
                unused_globals.erase(*global_it);
            } else if (local_it == func_locals.end()) {
                _var_usage_resolution.emplace(var_usage, *local_it);
                unused_locals.erase(*local_it);
            } else
                error<true>("Variable '", var_usage->name.text, "' not declared.");
        }

        // make sure we found at least one usage for each local variable
        for (const auto& var : unused_locals)
            error<false>("Local variable '", var.name.text, "'is unused in function '", func->id.text, "'.");
    }
}
