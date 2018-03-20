#pragma once
#include "SyntaxModel/Expression.h"

namespace SyntaxModel {
    struct UnaryOp final : public Expression {
        enum class Op { MINUS,
            NOT };
        UnaryOp(const Expression* expression, const Op op);
        virtual ~UnaryOp();

        const Expression* expression;
        const Op op;
    };
}
