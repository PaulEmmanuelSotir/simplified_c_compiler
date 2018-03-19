#pragma once

#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/AtomicType.h"

namespace SyntaxModel {

    class Declaration final : public Instruction {
    public:
        Declaration(const Identifier& id);
        virtual ~Declaration() = default;

    private:
        Identifier _nom;
        AtomicType _type;
    };
}
