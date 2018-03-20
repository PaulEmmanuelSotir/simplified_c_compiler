#include "SyntaxModel/If.h"

namespace SyntaxModel {

    If::If(const Expression* condition, const std::vector<const Instruction*>& instructions, const Else* else_clause)
        : Structure(condition, instructions)
        , else_clause(else_clause)
    {
    }

    If::~If()
    {
        delete else_clause;
    }
}
