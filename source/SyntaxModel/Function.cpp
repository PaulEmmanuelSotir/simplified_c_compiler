#include "SyntaxModel/Function.h"

namespace SyntaxModel {

    Function::Function(const std::vector<const Definition*>& declarations, const std::vector<const Definition*>& definitions, const std::vector<const Instruction*>& instructions, const vector<const Arg*>& arguments, const Identifier& id, const Type& returnType)
        : _declarations(declarations)
        , _definitions(definitions)
        , _instructions(instructions)
        , _arguments(arguments)
        , _id(id)
        , _returnType(returnType)
    {
    }

    Function::~Function()
    {
        for (auto* decl : _declarations)
            delete decl;
        for (auto* instr : _instructions)
            delete instr;
        for (auto* arg : _arguments)
            delete arg;
        for (auto* def : _definitions)
            delete def;
    }
}
