#include "SyntaxModel/Else.h"
#include "SyntaxModel/SyntaxNode.h"
#include "utils.h"

namespace SyntaxModel {

    Else::Else(const antlr4::misc::Interval& source_interval, const std::list<const Instruction*>& instructions)
        : SyntaxNodeBase(source_interval, utils::container_cast(instructions))
        , instructions(instructions)
    {
    }

    std::ostream& Else::toString(std::ostream& os) const
    {
        os << "else {" << std::endl;
        for (auto instr : instructions)
            os << *(instr);
        os << "}" << std::endl;
        return os;
    }
}
