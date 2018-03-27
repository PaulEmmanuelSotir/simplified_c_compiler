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

    std::ostream& Affectation::toString(std::ostream& os) const
    {
        os << var << " op" << static_cast<int>(op);
        if (affected_value != nullptr)
            os << " " << *affected_value;
        os << std::endl;
        return os;
    }
}
