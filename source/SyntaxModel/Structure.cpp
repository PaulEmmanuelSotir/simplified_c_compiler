#include <iostream>

#include "SyntaxModel/Structure.h"

namespace SyntaxModel {

    Structure::Structure(const Expression& condition, const std::vector<Instruction>& instructions)
        : _condition(condition)
        , _instructions(instructions)
    {
    }
}
