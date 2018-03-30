#pragma once
#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct Return final : public Instruction {
        Return(const antlr4::misc::Interval& source_interval, const Expression* expression);
        virtual ~Return() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Return>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;
        virtual IR::ExecutionBlock* generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t result_register) const override;

        const Expression* expression;
    };
}
