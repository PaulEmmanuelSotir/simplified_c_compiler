#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"
#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    class Definition : public Instruction {
    public:
        Definition(const Identifier& id, const Type& type);
        virtual ~Definition() = default;

    private:
        const Identifier _id;
        const Type _type;
    };

    class Declaration final : public Definition {
    public:
        Declaration(const Identifier& id, const Type& type, const Expression* init_value);
        virtual ~Declaration();

    private:
        const Expression* _init_value;
    };
}
