#include "SyntaxModel/Variable.h"

namespace SyntaxModel {
    Variable::Variable(const Identifier& name)
        : _name(name)
    {
    }
    ArrayVariable::ArrayVariable(const Identifier& name, size_t length)
        : Variable(name)
        , _length(length)
    {
    }
}
