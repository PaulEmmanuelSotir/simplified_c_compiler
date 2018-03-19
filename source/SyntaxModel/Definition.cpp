#include "SyntaxModel/Definition.h"

namespace SyntaxModel {

    Definition::Definition(const Identifier& id, const Type& type)
        : _id(id)
        , _type(type)
    {
    }
}
