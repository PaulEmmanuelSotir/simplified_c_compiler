#include "SyntaxModel/Definition.h"

namespace SyntaxModel {

    Definition::Definition(const Identifier& id, const Type& type)
        : _id(id)
        , _type(type)
    {
    }

    Declaration::Declaration(const Identifier& id, const Type& type, const Expression* init_value)
        : Definition(id, type)
        , _init_value(init_value)
    {
    }

    Declaration::~Declaration()
    {
        delete _init_value;
    }
}
