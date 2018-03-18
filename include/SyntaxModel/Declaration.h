#pragma once

#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Declaration final : public Instruction {
    public:
        Declaration(const Identifier& id);
        virtual ~Declaration() = default;

    private:
        const Identifier _id;
    };
}
