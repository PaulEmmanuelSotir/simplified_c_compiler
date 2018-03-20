#include "SyntaxModel/UnaryOp.h"

namespace SyntaxModel {

    UnaryOp::UnaryOp(const Expression* expression, const Op op)
        : _expression(expression)
        , _operator(op)
    {
    }

    UnaryOp::~UnaryOp()
    {
        delete _expression;
    }
}
