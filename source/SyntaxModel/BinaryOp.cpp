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
}
