#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {
    VariableUsage::VariableUsage(const Identifier& name)
        : name(name)
    {
    }

    ostream& Expression::toString(ostream& os) const
    {
        os << "expression" <<endl;
        return os;
    }

    ostream& VariableUsage::toString(ostream& os) const
    {
        os << name;
        return os;
    }
}
