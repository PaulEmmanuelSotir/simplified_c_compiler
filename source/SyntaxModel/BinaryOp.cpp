#include "SyntaxModel/BinaryOp.h"

namespace SyntaxModel {

    BinaryOp::BinaryOp(const Expression* leftExpression, const Expression* rightExpression, const Op op)
        : _leftExpression(leftExpression)
        , _rightExpression(rightExpression)
        , _operator(op)
    {
    }

    BinaryOp::~BinaryOp()
    {
        delete _leftExpression;
        delete _rightExpression;
    }
}
