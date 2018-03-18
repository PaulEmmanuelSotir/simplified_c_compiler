#include "SyntaxModel/Program.h"

namespace SyntaxModel {

    Program::Program(const std::vector<utils::TerminalInfo>& includes, const std::vector<const Function*>& functions, const std::vector<const Declaration*>& declarations, const std::vector<const Definition*>& definitions)
        : _includes(includes)
        , _functions(functions)
        , _declarations(declarations)
        , _definitions(definitions)
    {
    }

    Program::~Program()
    {
        for (auto* func : _functions)
            delete func;
        for (auto* decl : _declarations)
            delete decl;
        for (auto* def : _definitions)
            delete def;
    }
}
