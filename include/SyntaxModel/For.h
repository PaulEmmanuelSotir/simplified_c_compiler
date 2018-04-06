#pragma once
#include <list>

#include "SyntaxModel/Structure.h"

namespace SyntaxModel {

    struct For final : public Structure {
        For(const antlr4::misc::Interval& source_interval, const SyntaxNodeBase* init, const Expression* condition, const Expression* iteration_expression, const std::list<const Instruction*>& instructions);
        virtual ~For() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<For, Structure, Instruction>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;
        IR::ExecutionBlock* generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const;

        const SyntaxNodeBase* init;
        const Expression* iteration_expression;
    };
}
