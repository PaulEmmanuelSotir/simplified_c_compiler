#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions)
        : Structure(source_interval, condition, instructions)
    {
    }

    std::ostream& While::toString(std::ostream& os) const
    {
        os << "while(" << *condition << ") {" << std::endl;
        for (auto instr : instructions)
            os << *instr;
        os << "}" << std::endl;
        return os;
    }
}
