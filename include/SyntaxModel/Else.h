#pragma once
#include <list>

#include "SyntaxModel/Instruction.h"

namespace SyntaxModel {

    struct Else final : public SyntaxNodeBase {
        Else(const antlr4::misc::Interval& source_interval, const std::list<const Instruction*>& instructions);
        virtual ~Else() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Else>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

        const std::list<const Instruction*> instructions;
    };
}
