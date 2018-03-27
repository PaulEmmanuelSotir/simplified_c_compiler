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

        BinaryOp(const antlr4::misc::Interval& source_interval, const Expression* leftExpression, const Expression* rightExpression, const Op op);
        virtual ~BinaryOp() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, BinaryOp>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;
        virtual Type getExprType(const StaticAnalysis::StaticAnalyser* analyser) const override;

        const Expression* leftExpression;
        const Expression* rightExpression;
        const Op op;
    };
}
