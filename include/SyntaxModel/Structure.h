
#pragma once
#include <list>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Structure : public Instruction {
        Structure(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions, const std::list<const SyntaxNodeBase*>& additionnal_children = std::list<const SyntaxNodeBase*>());
        virtual ~Structure() = default;

        const Expression* condition;
        const std::list<const Instruction*> instructions;
    };
}
