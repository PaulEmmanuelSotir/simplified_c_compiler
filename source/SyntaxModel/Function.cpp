#include <iostream>

#include "SyntaxModel/Function.h"

namespace SyntaxModel {

    Function::Function(const std::vector<Declaration>& declarations, const std::vector<Instruction>& instructions, const Identifier& id)
        : _declarations(declarations)
        , _instructions(instructions)
        , _id(id)
    {
    }
}
