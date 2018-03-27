#pragma once
#include <exception>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "SyntaxModel/SyntaxModel.h"

namespace StaticAnalysis {

    struct Variable {
        Variable(SyntaxModel::Identifier name, SyntaxModel::Type* type, SyntaxModel::Definition::size_constant* array_size = nullptr, SyntaxModel::Expression* init_value = nullptr);
        Variable(const SyntaxModel::Definition& def, const size_t index = 0);
        const SyntaxModel::Identifier name;
        const SyntaxModel::Type* type;
        const SyntaxModel::Definition::size_constant* array_size;
        const SyntaxModel::Expression* init_value;
        friend inline bool operator<(const Variable& lhs, const Variable& rhs) { return lhs.name < rhs.name; }
        friend inline bool operator==(const Variable& lhs, const Variable& rhs) { return lhs.name == rhs.name; }
    };

    class StaticAnalyser final {
    public:
        using FunctionVarScope = std::vector<const SyntaxModel::Instruction*>;

        StaticAnalyser(const SyntaxModel::Program* ast);
        void Analyse();

        std::vector<Variable> getGlobalVariables() const { return _global_variables; }
        std::vector<Variable> getLocalVariables(const SyntaxModel::Function* const func) const { return _function_variables.find(func->unique_id)->second; }
        Variable getVariableOfUsage(const SyntaxModel::VariableUsage* const usage) const { return _var_usage_resolution.find(usage->unique_id)->second; }
        Variable getVariableOfAffectation(const SyntaxModel::Affectation* const affectation) const { return _affectation_resolution.find(affectation->unique_id)->second; }
        const SyntaxModel::Function* getFunctionDef(const SyntaxModel::FunctionCall* const func_call) const { return _function_call_resolution.find(func_call->unique_id)->second; }
        bool raisedWarnings() const { return _raisedWarnings; };
        bool raisedErrors() const { return _raisedErrors; };

    private:
        std::set<Variable> FindGlobals(const std::list<const SyntaxModel::Definition*>& defs);
        void DefineFunctionVariables(const SyntaxModel::Function* func);
        void FindFuncVarUsages(const SyntaxModel::Function* func, std::set<Variable>& unused_globals);
        void ResolveFunctionCalls();

        template <bool Fatal, typename... Args>
        void error(const std::string& message, Args&&... args)
        {
            if (Fatal)
                _raisedErrors = true;
            else
                _raisedWarnings = true;
            std::cout << (Fatal ? "ERROR: " : "WARNING: ") << message;
            using expander = int[];
            (void)expander{ 0, (void(std::cout << std::forward<Args>(args)), 0)... };
            std::cout << std::endl;
        }

        template <typename T>
        void ResolveVarUsage(std::map<size_t, Variable>& var_resolution_map, const T* var_usage, const SyntaxModel::Identifier& var_id, std::set<Variable>& unused_globals, std::set<Variable>* unused_locals = nullptr, const std::vector<Variable>* func_locals = nullptr)
        {
            Variable dummy_var(var_id, nullptr);
            auto global_it = std::find(_global_variables.cbegin(), _global_variables.cend(), dummy_var);
            if (global_it != _global_variables.cend()) {
                var_resolution_map.emplace(var_usage->unique_id, *global_it);
                unused_globals.erase(*global_it);
            } else if (func_locals != nullptr && unused_locals != nullptr) {
                auto local_it = std::find(func_locals->cbegin(), func_locals->cend(), dummy_var);
                if (local_it != func_locals->cend()) {
                    var_resolution_map.emplace(var_usage->unique_id, *local_it);
                    unused_locals->erase(*local_it);
                }
            } else
                error<false>("Variable '", var_id.text, "' not declared.");
        }

        bool _raisedWarnings = false;
        bool _raisedErrors = false;
        // Program syntaxic tree
        const SyntaxModel::Program* _ast;
        // Global variables
        std::vector<Variable> _global_variables;
        // Maps a function to its local variables
        std::map<size_t, std::vector<Variable>> _function_variables;
        // Maps VariableUsages with their respective Variables
        std::map<size_t, Variable> _var_usage_resolution;
        // Maps UnaryAffectation with their respective Variables
        std::map<size_t, Variable> _affectation_resolution;
        // Maps function calls to their respective function definition
        std::map<size_t, const SyntaxModel::Function*> _function_call_resolution;
    };
}
