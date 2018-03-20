#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    class UnaryAffectation final : public Expression {
    public:
        enum class Op { POST_INC,
            POST_DEC,
            PRE_INC,
            PRE_DEC };

        UnaryAffectation(const Op op, const Identifier& var, const Expression* array_indice);
        virtual ~UnaryAffectation();

    private:
        const Op _operator;
        const Identifier& _var;
        const Expression* _array_indice;
    };

    class BinaryAffectation final : public Expression {
    public:
        enum class Op { EQ,
            PLUS_EQ,
            MIN_EQ,
            DIV_EQ,
            MULT_EQ,
            MODULO_EQ };

        BinaryAffectation(const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice);
        virtual ~BinaryAffectation();

    private:
        const Op _operator;
        const Identifier& _var;
        const Expression* _affected_value;
        const Expression* _array_indice;
    };
}
