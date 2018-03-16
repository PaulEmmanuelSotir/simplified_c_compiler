#pragma once

#include "Instruction.h"
#include <list>

namespace SyntaxModel {

    class Else final {
    public:
        Else();

    private:
        std::list<Instruction> _instructions;
    };
}
