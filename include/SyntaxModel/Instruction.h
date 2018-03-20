#pragma once
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    struct Instruction {
        virtual ~Instruction() = default;
    };

    struct Break final : public Instruction {
        virtual ~Break() = default;
    };

    struct Continue final : public Instruction {
        virtual ~Continue() = default;
    };
}
