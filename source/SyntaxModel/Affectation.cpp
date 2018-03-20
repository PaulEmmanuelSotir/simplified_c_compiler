#include "SyntaxModel/Affectation.h"

namespace SyntaxModel {
    UnaryAffectation::UnaryAffectation(const Op op, const Identifier& var, const Expression* array_indice)
        : op(op)
        , var(var)
        , array_indice(array_indice)
    {
    }

    UnaryAffectation::~UnaryAffectation()
    {
        delete array_indice;
    }

    BinaryAffectation::BinaryAffectation(const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice)
        : op(op)
        , var(var)
        , affected_value(affected_value)
        , array_indice(array_indice)
    {
    }

    BinaryAffectation::~BinaryAffectation()
    {
        delete affected_value;
        delete array_indice;
    }
}
