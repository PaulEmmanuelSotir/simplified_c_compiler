#pragma once

#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Expression : public Instruction {
    public:
        Expression();
        virtual ~Expression() = default;
    };
}