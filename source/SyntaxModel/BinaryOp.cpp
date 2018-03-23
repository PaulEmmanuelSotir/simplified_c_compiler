#include "SyntaxModel/BinaryOp.h"

namespace SyntaxModel {

    BinaryOp::BinaryOp(const Expression* leftExpression, const Expression* rightExpression, const Op op)
        : leftExpression(leftExpression)
        , rightExpression(rightExpression)
        , op(op)
    {
    }

    BinaryOp::~BinaryOp()
    {
        delete leftExpression;
        delete rightExpression;
    }

    ostream& BinaryOp::toString(ostream& os) const
    {
        os << *(leftExpression) << " op" << static_cast<std::underlying_type<BinaryOp::Op>::type>(op) << " " << *(rightExpression);
        return os;
    }
}
