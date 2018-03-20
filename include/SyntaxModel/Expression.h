#pragma once
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"

namespace SyntaxModel {

    struct Expression : public Instruction {
        virtual ~Expression() = default;
    };

    struct VariableUsage final : public Expression {
        VariableUsage(const Identifier& name);
        virtual ~VariableUsage() = default;

        const Identifier name;
    };
}