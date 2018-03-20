#pragma once
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    class Expression : public Instruction {
    public:
        virtual ~Expression() = default;
    };

    class VariableUsage final : public Expression {
    public:
        VariableUsage(const Identifier& name);
        virtual ~VariableUsage() = default;

    private:
        const Identifier _name;
    };
}