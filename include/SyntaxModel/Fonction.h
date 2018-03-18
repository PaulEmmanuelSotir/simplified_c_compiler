#pragma once
#include <iostream>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Type.h"
#include "SyntaxModel/Arg.h"

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
        Identifier _nom;
    };
}
