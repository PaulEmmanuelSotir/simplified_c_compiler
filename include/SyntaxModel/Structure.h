
#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Structure : public Instruction {
    public:
        Structure();
        virtual ~Structure() = default;

    private:
        Expression _condition;
        std::vector<Instruction> _instructions;
    };
}
