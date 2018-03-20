#include "SyntaxModel/Return.h"

namespace SyntaxModel {

    Return::Return(const Expression* expression)
        : _expression(expression)
    {
    }

    Return::~Return()
    {
        delete _expression;
    }
}
