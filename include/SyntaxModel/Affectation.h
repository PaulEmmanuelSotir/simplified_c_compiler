#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct UnaryAffectation final : public Expression {
        enum class Op { POST_INC,
            POST_DEC,
            PRE_INC,
            PRE_DEC };

        UnaryAffectation(const antlr4::misc::Interval& source_interval, const Op op, const Identifier& var, const Expression* array_indice);
        virtual ~UnaryAffectation() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, UnaryAffectation>::typenames(); }

        const Op op;
        const Identifier& var;
        const Expression* array_indice;
    };

    struct BinaryAffectation final : public Expression {
        enum class Op { EQ,
            PLUS_EQ,
            MIN_EQ,
            DIV_EQ,
            MULT_EQ,
            MODULO_EQ };

        BinaryAffectation(const antlr4::misc::Interval& source_interval, const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice);
        virtual ~BinaryAffectation() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, BinaryAffectation>::typenames(); }

        const Op op;
        const Identifier& var;
        const Expression* affected_value;
        const Expression* array_indice;
    };
}
