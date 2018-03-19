#pragma once
#include "SyntaxModel/Expression.h"

namespace SyntaxModel {
    class BinaryOp final : public Expression {
    public:
        enum class Op { PLUS,
            MINUS,
            MULT,
            DIV,
            MODULO,
            EQUAL,
            DIFFERENT,
            GREATER_THAN,
            GREATER_THAN_OR_EQ,
            LESS_THAN,
            LESS_THAN_OR_EQ,
            AND,
            OR
        };
        BinaryOp(const Expression* leftExpression, const Expression* rightExpression, const Op op);
        virtual ~BinaryOp();

    private:
        const Expression* _leftExpression;
        const Expression* _rightExpression;
        const Op _operator;
    };
}
