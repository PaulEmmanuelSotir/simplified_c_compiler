#include "SyntaxModel/Return.h"

namespace SyntaxModel {

    Return::Return(const antlr4::misc::Interval& source_interval, const Expression* expression)
        : Instruction(source_interval, { expression })
        , expression(expression)
    {
    }
}
