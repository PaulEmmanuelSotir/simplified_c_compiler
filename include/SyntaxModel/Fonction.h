#pragma once
#include <iostream>

#include "Declaration.h"
#include "Identificateur.h"
#include "Instruction.h"
#include "Type.h"
#include "Arg.h"

namespace SyntaxModel {

    class Fonction final {
    public:
        Fonction();
        virtual ~Fonction() = default;

    private:
        std::list<Declaration> _declarations;
        std::list<Instruction> _instructions;
        std::list<Arg> _arguments;
        Type _typeRetour;
        Identificateur _nom;
    };
}
