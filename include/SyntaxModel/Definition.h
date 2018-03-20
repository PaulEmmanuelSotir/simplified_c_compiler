#pragma once
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    class Definition final : public Instruction {
    public:
        Definition(const Identifier& id, const Type& type);
        virtual ~Definition() = default;

    private:
        const Identifier _id;
        const Type _type;
    };
}
