#pragma once
#include <iostream>

#include "Declaration.h"
#include "Identificateur.h"
#include "Instruction.h"

namespace SyntaxModel {

    class Fonction final {
    public:
        Fonction();
        virtual ~Fonction() = default;

    private:
        std::list<Declaration> _declarations;
        std::list<Instruction> _instructions;
        Identificateur _nom;
    };
}
