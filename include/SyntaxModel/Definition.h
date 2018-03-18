#pragma once

#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Definition final : public Instruction {
    public:
        Definition(const Identifier& id);
        virtual ~Definition() = default;

    private:
        const Identifier _id;
    };
}
