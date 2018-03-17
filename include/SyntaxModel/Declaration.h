#pragma once

#include "SyntaxModel/Identificateur.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Declaration final : public Instruction {
    public:
        Declaration();
        virtual ~Declaration() = default;

    private:
        Identificateur _nom;
    };
}
