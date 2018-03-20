#pragma once
#include "SyntaxModel/Expression.h"

namespace SyntaxModel {
    struct BinaryOp final : public Expression {
        enum class Op { PLUS,
            MINUS,
            MULT,
            DIV,
            MODULO,
            EQUAL,
            DIFFERENT,
            SUP,
            SUP_EQ,
            INF,
            INF_EQ,
            AND,
            OR
        };
        BinaryOp(const Expression* leftExpression, const Expression* rightExpression, const Op op);
        virtual ~BinaryOp();

        const Expression* leftExpression;
        const Expression* rightExpression;
        const Op op;
    };
}
