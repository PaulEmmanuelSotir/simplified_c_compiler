#include "SyntaxModel/Affectation.h"

namespace SyntaxModel {

    Affectation::Affectation(const Op op, const Expression* expression, const Identifier& var)
        : _operator(op)
        , _expression(expression)
        , _var(var)
    {
    }

    Affectation::~Affectation()
    {
        delete _expression;
    }
}
