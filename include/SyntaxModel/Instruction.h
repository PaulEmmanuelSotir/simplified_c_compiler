#pragma once
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Instruction : public SyntaxNodeBase {
        Instruction(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children = std::list<const SyntaxNodeBase*>())
            : SyntaxNodeBase(source_interval, children)
        {
        }
        virtual ~Instruction() = default;
    };

    struct Break final : public Instruction {
        Break(const antlr4::misc::Interval& source_interval)
            : Instruction(source_interval)
        {
        }
        virtual ~Break() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Break, Instruction>::typenames(); }
    };

    struct Continue final : public Instruction {
        Continue(const antlr4::misc::Interval& source_interval)
            : Instruction(source_interval)
        {
        }
        virtual ~Continue() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Continue, Instruction>::typenames(); }
    };
}
