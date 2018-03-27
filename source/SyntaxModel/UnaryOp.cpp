#include "SyntaxModel/UnaryOp.h"

namespace SyntaxModel {

    UnaryOp::UnaryOp(const antlr4::misc::Interval& source_interval, const Expression* expression, const Op op)
        : Expression(source_interval, { expression })
        , expression(expression)
        , op(op)
    {
    }

    std::ostream& UnaryOp::toString(std::ostream& os) const
    {
        os << "op" << static_cast<std::underlying_type<UnaryOp::Op>::type>(op) << *expression << std::endl;
        return os;
    }
}
