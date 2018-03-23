#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : Structure(condition, instructions)
    {
    }

    ostream& While::toString(ostream& os) const {
        os << "while(" << *condition << ") {" << endl;
        for(auto instr : instructions) {
            os << *instr;
        }
        os << "}" <<endl;
        return os;
    }
}
