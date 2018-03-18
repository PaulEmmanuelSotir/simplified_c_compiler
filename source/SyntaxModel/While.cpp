#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const Expression& condition, const std::vector<Instruction>& instructions)
        : Structure(condition, instructions)
    {
    }
}