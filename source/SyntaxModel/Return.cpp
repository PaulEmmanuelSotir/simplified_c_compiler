#include "SyntaxModel/Return.h"

namespace SyntaxModel {

    Return::Return(const Expression* expression)
        : expression(expression)
    {
    }

    Return::~Return()
    {
        delete expression;
    }
}
