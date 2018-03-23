#include "SyntaxModel/UnaryOp.h"

namespace SyntaxModel {

    UnaryOp::UnaryOp(const Expression* expression, const Op op)
        : expression(expression)
        , op(op)
    {
    }

    UnaryOp::~UnaryOp()
    {
        delete expression;
    }

    ostream& UnaryOp::toString(ostream& os) const {
        os << "op" << static_cast<std::underlying_type<UnaryOp::Op>::type>(op) << *expression << endl;
        return os;
    }
}
