#pragma once
#include "SyntaxModel/Expression.h"

namespace SyntaxModel {
    struct UnaryOp final : public Expression {
        enum class Op { MINUS,
            NOT };
        UnaryOp(const Expression* expression, const Op op);
        virtual ~UnaryOp();
        ostream& toString(ostream& os) const {
            os << "unary op" << endl;
            return os;
        }

        const Expression* expression;
        const Op op;
    };
}
