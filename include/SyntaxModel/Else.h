#pragma once
#include <vector>

#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Else final {
    public:
        Else(const std::vector<const Instruction*>& instructions);
        ~Else();

    private:
        const std::vector<const Instruction*> _instructions;
    };
}
