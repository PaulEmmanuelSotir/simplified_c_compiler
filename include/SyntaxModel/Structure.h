
#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Structure : public Instruction {
    public:
        Structure(const Expression& condition, const std::vector<Instruction>& instructions);
        virtual ~Structure() = default;

    private:
        const Expression _condition;
        const std::vector<Instruction> _instructions;
    };
}
