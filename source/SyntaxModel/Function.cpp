#include "SyntaxModel/Function.h"

namespace SyntaxModel {

    Function::Function(const std::vector<const Declaration*>& declarations, const std::vector<const Definition*>& definitions, const std::vector<const Instruction*>& instructions, const Identifier& id)
        : _declarations(declarations)
        , _definitions(definitions)
        , _instructions(instructions)
        , _id(id)
    {
    }

    Function::~Function()
    {
        for (auto* decl : _declarations)
            delete decl;
        for (auto* instr : _instructions)
            delete instr;
        for (auto* def : _definitions)
            delete def;
    }
}
