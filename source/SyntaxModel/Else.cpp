#include "SyntaxModel/Else.h"

namespace SyntaxModel {

    Else::Else(const std::vector<const Instruction*>& instructions)
        : _instructions(instructions)
    {
    }

    Else::~Else()
    {
        for (auto* instr : _instructions)
            delete instr;
    }
}
