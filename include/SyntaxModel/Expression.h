#pragma once
#include <iostream>
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/Terminals.h"

using namespace std;

namespace SyntaxModel {

    struct Expression : public Instruction {
        virtual ~Expression() = default;
        ostream& toString(ostream& os) const;
    };

    struct VariableUsage final : public Expression {
        VariableUsage(const Identifier& name);
        virtual ~VariableUsage() = default;
        ostream& toString(ostream& os) const;

        const Identifier name;
    };
}
