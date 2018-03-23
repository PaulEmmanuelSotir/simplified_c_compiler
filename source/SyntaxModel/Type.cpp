#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    Type::Type(const PrimitiveType type, const bool isArray)
        : type(type)
        , isArray(isArray)
    {
    }

    ostream& operator<<(ostream& os, const Type& t)
    {
        os << static_cast<int>(t.type);
        if(t.isArray) {
            os << "[]";
        }
        return os;
    }
}
