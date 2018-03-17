#pragma once
#include <iostream>
#include <vector>

#include "SyntaxModel/Declaration.h"
#include "SyntaxModel/Identificateur.h"
#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    class Fonction final {
    public:
        Fonction();
        virtual ~Fonction() = default;

    private:
        std::vector<Declaration> _declarations;
        std::vector<Instruction> _instructions;
        Identificateur _nom;
    };
}
