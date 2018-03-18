#pragma once
#include <vector>

#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Else final {
    public:
        Else(const std::vector<Instruction>& instructions);

    private:
        const std::vector<Instruction> _instructions;
    };
}
