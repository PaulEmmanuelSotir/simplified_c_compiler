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

    ostream& If::toString(ostream& os) const {
        os << "if(" << *condition << ")" << endl;
        for(auto instr : instructions) {
            os << *instr;
        }
        if(else_clause != nullptr) {
            os << *else_clause;
        }
        return os;
    }
}
