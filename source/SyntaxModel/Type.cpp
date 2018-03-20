#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    Type::Type(const antlr4::misc::Interval& source_interval, const PrimitiveType type, const bool isArray)
        : SyntaxNodeBase(source_interval)
        , type(type)
        , isArray(isArray)
    {
    }
}
