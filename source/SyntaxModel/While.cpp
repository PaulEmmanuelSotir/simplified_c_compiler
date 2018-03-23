#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : Structure(condition, instructions)
    {
    }

    virtual ostream& toString(ostream& os) const override {
        os << "while(" << *condition << ")" << endl;
        for(auto instr : instructions) {
            os << *instr;
        }
        return os;
    }
}
