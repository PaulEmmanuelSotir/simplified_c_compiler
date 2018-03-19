#pragma once
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {
    class Continue final : public Instruction {
    public:
        virtual ~Continue() = default;
    };
}
