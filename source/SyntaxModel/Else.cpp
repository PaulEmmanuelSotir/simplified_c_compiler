#include "SyntaxModel/Else.h"
#include "utils.h"

namespace SyntaxModel {

    Else::Else(const std::vector<const Instruction*>& instructions)
        : instructions(instructions)
    {
    }

    Else::~Else()
    {
        utils::delete_all(instructions);
    }

    ostream& operator<<(ostream& os, const Else& e)
    {
        for(auto instr : e.instructions) {
            os << *(instr);
        }
        return os;
    }
}
