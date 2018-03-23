#pragma once
#include <iostream>
#include "SyntaxModel/Expression.h"
using namespace std;

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
        virtual ostream& toString(ostream& os) const override;

        const Expression* leftExpression;
        const Expression* rightExpression;
        const Op op;
    };
}
