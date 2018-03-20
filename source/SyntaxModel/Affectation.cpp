#include "SyntaxModel/Affectation.h"

namespace SyntaxModel {
    UnaryAffectation::UnaryAffectation(const antlr4::misc::Interval& source_interval, const Op op, const Identifier& var, const Expression* array_indice)
        : Expression(source_interval, { array_indice })
        , op(op)
        , var(var)
        , array_indice(array_indice)
    {
    }

    BinaryAffectation::BinaryAffectation(const antlr4::misc::Interval& source_interval, const Op op, const Identifier& var, const Expression* affected_value, const Expression* array_indice)
        : Expression(source_interval, { affected_value, array_indice })
        , op(op)
        , var(var)
        , affected_value(affected_value)
        , array_indice(array_indice)
    {
    }
}
