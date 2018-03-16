#pragma once

#include "Instruction.h"

namespace SyntaxModel {

    class Expression : public Instruction {
    public:
        Expression();
        virtual ~Expression() = default;
    };
}