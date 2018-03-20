#pragma once
#include "SyntaxModel/Structure.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct While final : public Structure {
        While(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions);
        virtual ~While() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Structure, Instruction, While>::typenames(); }
    };
}
