#pragma once

#include "SyntaxModel/Structure.h"

namespace SyntaxModel {

    class While final : public Structure {
    public:
        While(const Expression& condition, const std::vector<Instruction>& instructions);
        virtual ~While() = default;
    };
}
