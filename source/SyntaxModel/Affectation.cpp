#include "SyntaxModel/Affectation.h"

namespace SyntaxModel {
    UnaryAffectation::UnaryAffectation(const Op op, const Identifier& var, const Expression* array_indice)
        : _operator(op)
        , _var(var)
        , _array_indice(array_indice)
    {
    }

    UnaryAffectation::~UnaryAffectation()
    {
        delete _array_indice;
    }

    BinaryAffectation::BinaryAffectation(const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice)
        : _operator(op)
        , _var(var)
        , _affected_value(affected_value)
        , _array_indice(array_indice)
    {
    }

    BinaryAffectation::~BinaryAffectation()
    {
        delete _affected_value;
        delete _array_indice;
    }
}
