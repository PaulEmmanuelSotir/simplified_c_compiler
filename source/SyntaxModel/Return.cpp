#include "SyntaxModel/Return.h"

namespace SyntaxModel {

    Return::Return(const antlr4::misc::Interval& source_interval, const Expression* expression)
        : Instruction(source_interval, { expression })
        , expression(expression)
    {
    }

    std::ostream& Return::toString(std::ostream& os) const
    {
        os << "return" << std::endl;
        return os;
    }
}
