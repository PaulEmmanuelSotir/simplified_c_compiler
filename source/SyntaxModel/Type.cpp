#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    Type::Type(const PrimitiveType type, const bool isArray)
        : type(type)
        , isArray(isArray)
    {
    }
}
