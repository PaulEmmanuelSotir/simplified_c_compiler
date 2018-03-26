#include "SyntaxModel/Affectation.h"

namespace SyntaxModel {
    Affectation::Affectation(const antlr4::misc::Interval& source_interval, const Op op, const Identifier& var, const Expression* array_indice, const Expression* affected_value)
        : Expression(source_interval, { affected_value, array_indice })
        , op(op)
        , var(var)
        , array_indice(array_indice)
        , affected_value(affected_value)
    {
    }
}
