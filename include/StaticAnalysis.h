#pragma once
#include <exception>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "SyntaxModel/SyntaxModel.h"

namespace StaticAnalysis {

    struct SemanticError : std::exception {
        // TODO: add informations like TerminalInfo
    };

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
        ~StaticAnalyser();
        void Analyse();

        std::vector<Variable> getGlobalVariables() { return _global_variables; }
        std::vector<Variable> getLocalVariables(const SyntaxModel::Identifier& func_id) { return _function_variables.find(func_id)->second; }
        Variable getVariableOfUsage(const SyntaxModel::VariableUsage* usage) { return _var_usage_resolution.find(usage)->second; }

    private:
        void FindGlobals(const std::list<const SyntaxModel::Definition*>& defs, std::set<Variable>& unused_globals);
        void DefineFunctionVariables(const SyntaxModel::Function* func);
        void FindFuncVarUsage(const SyntaxModel::Function* func, std::set<Variable>& unused_globals);

        // Program syntaxic tree
        const SyntaxModel::Program* _ast;
        // Global variables
        std::vector<Variable> _global_variables;
        // Maps a function to its local variables
        std::map<SyntaxModel::Identifier, std::vector<Variable>> _function_variables;
        // Maps VariableUsages with their respective Variables
        std::map<const SyntaxModel::VariableUsage*, Variable> _var_usage_resolution;
    };

    namespace {
        inline void _throw_error(const SemanticError* e)
        {
            if (e != nullptr)
                throw e;
            else
                throw new SemanticError();
        }
    }

    template <bool Warn, typename... Args>
    void error(const SemanticError* e, const std::string& message, Args&&... args)
    {
        const bool THROW_ON_ERROR = false; // TODO: make it a cmd option
        const bool THROW_ON_WARNING = false; // TODO: make it a cmd option
        std::cout << (Warn ? "ERROR: " : "WARNING: ") << message;
        using expander = int[];
        (void)expander{ 0, (void(std::cout << ',' << std::forward<Args>(args)), 0)... };
        if ((Warn ? THROW_ON_ERROR : THROW_ON_WARNING))
            _throw_error(e);
    }

    template <bool Warn, typename... Args>
    void error(const std::string& message, Args&&... args)
    {
        error<Warn>(nullptr, message, std::forward<Args>(args)...);
    }
}
