#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const Expression* condition, const std::vector<const Instruction*>& instructions)
        : Structure(condition, instructions)
    {
    }
}