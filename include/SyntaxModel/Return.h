#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct Return final : public Instruction {
        Return(const antlr4::misc::Interval& source_interval, const Expression* expression);
        virtual ~Return() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Return>::typenames(); }

        const Expression* expression;
    };
}
