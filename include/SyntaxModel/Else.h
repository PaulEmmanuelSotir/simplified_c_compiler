#pragma once
#include <vector>

#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Else final {
    public:
        Else();

    private:
        std::vector<Instruction> _instructions;
    };
}
