#pragma once
#include <list>

#include "SyntaxModel/Else.h"
#include "SyntaxModel/Structure.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct If final : public Structure {
        If(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions, const Else* else_clause);
        virtual ~If() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<If, Structure, Instruction>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

        const Else* else_clause;
    };
}
