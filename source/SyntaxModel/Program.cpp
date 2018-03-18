#include <iostream>

#include "SyntaxModel/Program.h"

namespace SyntaxModel {

    Program::Program(const std::vector<Function>& functions, const std::vector<Declaration>& declarations)
        : _functions(functions)
        , _declarations(declarations)
    {
    }
}
