#pragma once

#include "Identifier.h"
#include "Instruction.h"
#include "AtomicType.h"

namespace SyntaxModel {

    class Declaration final : public Instruction {
    public:
        Declaration(const Identifier& id, const AtomicType& type);
        virtual ~Declaration() = default;

    private:
        Identifier _nom;
        AtomicType _type;
    };
}
