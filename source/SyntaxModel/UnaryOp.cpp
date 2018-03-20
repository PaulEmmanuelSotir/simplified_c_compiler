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
}
