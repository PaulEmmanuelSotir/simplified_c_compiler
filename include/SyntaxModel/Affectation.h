#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    struct UnaryAffectation final : public Expression {
        enum class Op { POST_INC,
            POST_DEC,
            PRE_INC,
            PRE_DEC };

        UnaryAffectation(const Op op, const Identifier& var, const Expression* array_indice);
        virtual ~UnaryAffectation();

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

        BinaryAffectation(const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice);
        virtual ~BinaryAffectation();

        const Op op;
        const Identifier& var;
        const Expression* affected_value;
        const Expression* array_indice;
    };
}
