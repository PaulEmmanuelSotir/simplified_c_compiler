
#pragma once
#include <list>

#include "Expression.h"
#include "Instruction.h"

namespace SyntaxModel {

    class Structure : public Instruction {
    public:
        Structure();
        ~Structure() = default;

    private:
        Expression _condition;
        std::list<Instruction> _instructions;
    };
}
