#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {
    class ArrayIndexing final : public Expression {
    public:
        ArrayIndexing(const Identifier& name, const Expression* indice);
        virtual ~ArrayIndexing();

    private:
        const Identifier _name;
        const Expression* _indice; // ou taille (définition) ou indice (accès à une case) et type si déclaration ou definition, comment savoir??
    };
}
