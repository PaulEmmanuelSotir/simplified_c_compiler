#pragma once
#include "SyntaxModel/Expression.h"

namespace SyntaxModel {
    class UnaryOp final : public Expression {
    public:
        enum class Op { MINUS,
            NOT };
        UnaryOp(const Expression* expression, const Op op);
        virtual ~UnaryOp();

    private:
        const Expression* _expression;
        const Op _operator;
    };
}
