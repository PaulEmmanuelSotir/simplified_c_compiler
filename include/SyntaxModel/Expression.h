#pragma once

#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct Expression : public Instruction {
        Expression(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children = std::list<const SyntaxNodeBase*>());
        virtual ~Expression() = default;
    };

    struct VariableUsage final : public Expression {
        VariableUsage(const antlr4::misc::Interval& source_interval, const Identifier& name);
        virtual ~VariableUsage() = default;
        friend bool inline operator<(const VariableUsage& lhs, const VariableUsage& rhs) { return lhs.name < rhs.name; }
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, VariableUsage>::typenames(); }

        const Identifier name;
    };
}
