#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {
    class Variable : public Expression {
    public:
        Variable(const Identifier& name);
        virtual ~Variable() = default;

    private:
        Identifier _name;
    };

    class ArrayVariable final : public Variable {
    public:
        ArrayVariable(const Identifier& name, size_t length);
        virtual ~ArrayVariable() = default;

    private:
        size_t _length; // (définition) ou indice (accès à une case) et type si déclaration ou definition, comment savoir??
    };
}
