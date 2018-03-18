
#pragma once
#include <vector>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Structure : public Instruction {
    public:
        Structure(const Expression* condition, const std::vector<const Instruction*>& instructions);
        virtual ~Structure();

    private:
        const Expression* _condition;
        const std::vector<const Instruction*> _instructions;
    };
}
