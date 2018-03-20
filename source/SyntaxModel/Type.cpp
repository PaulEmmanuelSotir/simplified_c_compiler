#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    Type::Type(const PrimitiveType type, const bool isArray)
        : _type(type)
        , _isArray(isArray)
    {
    }
}
