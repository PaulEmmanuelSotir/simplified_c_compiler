#pragma once
#include <iostream>
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {

    struct Expression : public Instruction {
        virtual ~Expression() = default;
        virtual ostream& toString(ostream& os) const override;
    };

    struct VariableUsage final : public Expression {
        VariableUsage(const Identifier& name);
        virtual ~VariableUsage() = default;
        virtual ostream& toString(ostream& os) const override;

        const Identifier name;
    };
}
