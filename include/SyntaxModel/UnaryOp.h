#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct UnaryOp final : public Expression {
        enum class Op { MINUS,
            NOT };
        UnaryOp(const antlr4::misc::Interval& source_interval, const Expression* expression, const Op op);
        virtual ~UnaryOp() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<UnaryOp>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

        const Expression* expression;
        const Op op;
    };
}
