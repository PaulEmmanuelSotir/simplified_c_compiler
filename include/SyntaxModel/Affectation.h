#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    class Affectation final : public Expression {
    public:
        enum class Op { INC,
            DEC,
            EQ,
            PLUS_EQ,
            MIN_EQ,
            DIV_EQ,
            MULT_EQ,
            MODULO_EQ };

        Affectation(const Op op, const Expression* expression, const Identifier& var);
        virtual ~Affectation();

    private:
        const Op _operator;
        const Expression* _expression;
        const Identifier& _var;
    };
}
