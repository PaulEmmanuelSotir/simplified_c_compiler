#include "SyntaxModel/If.h"

namespace SyntaxModel {

    If::If(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions, const Else* else_clause)
        : Structure(source_interval, condition, instructions, { else_clause })
        , else_clause(else_clause)
    {
    }
}
