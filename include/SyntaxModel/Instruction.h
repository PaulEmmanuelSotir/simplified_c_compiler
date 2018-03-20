#pragma once
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    class Instruction {
    public:
        virtual ~Instruction() = default;
    };

    class Break final : public Instruction {
    public:
        virtual ~Break() = default;
    };

    class Continue final : public Instruction {
    public:
        virtual ~Continue() = default;
    };
}
