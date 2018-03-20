#include "SyntaxModel/BinaryOp.h"

namespace SyntaxModel {

    BinaryOp::BinaryOp(const antlr4::misc::Interval& source_interval, const Expression* leftExpression, const Expression* rightExpression, const Op op)
        : Expression(source_interval, { leftExpression, rightExpression })
        , leftExpression(leftExpression)
        , rightExpression(rightExpression)
        , op(op)
    {
    }
}
