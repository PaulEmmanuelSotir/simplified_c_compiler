#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {
    class Return final : public Instruction {
    public:
        Return(const Expression* expression);
        virtual ~Return();

    private:
        const Expression* _expression;
    };
}
