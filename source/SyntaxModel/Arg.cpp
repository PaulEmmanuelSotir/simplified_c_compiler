#include "SyntaxModel/Arg.h"

namespace SyntaxModel {

    Arg::Arg(const Type& type, const Identifier& id)
        : _type(type)
        , _id(id)
    {
    }
}
