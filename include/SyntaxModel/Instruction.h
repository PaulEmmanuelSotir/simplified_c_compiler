#pragma once
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Instruction : public SyntaxNodeBase {
        Instruction(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children = {})
            : SyntaxNodeBase(source_interval, children)
        {
        }
        virtual ~Instruction() = default;
        virtual IR::ExecutionBlock* generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const = 0;
    };

    struct Break final : public Instruction {
        Break(const antlr4::misc::Interval& source_interval)
            : Instruction(source_interval)
        {
        }
        virtual ~Break() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Break, Instruction>::typenames(); }
        virtual IR::ExecutionBlock* generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const override
        {
            return eb;
        }

        virtual std::ostream& toString(std::ostream& os) const override
        {
            os << "break" << std::endl;
            return os;
        }
    };

    struct Continue final : public Instruction {
        Continue(const antlr4::misc::Interval& source_interval)
            : Instruction(source_interval)
        {
        }
        virtual ~Continue() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Continue, Instruction>::typenames(); }
        virtual IR::ExecutionBlock* generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const override
        {
            return eb;
        }

        virtual std::ostream& toString(std::ostream& os) const override
        {
            os << "continue" << std::endl;
            return os;
        }
    };
}
