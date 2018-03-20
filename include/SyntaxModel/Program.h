#pragma once
#include <list>
#include <vector>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {

    struct Program final : public SyntaxNodeBase {
        Program(const antlr4::misc::Interval& source_interval, const std::vector<Include>& includes, const std::list<const Function*>& functions, const std::list<const Definition*>& definitions);
        virtual ~Program() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Program>::typenames(); }

        const std::vector<Include> includes;
        const std::list<const Function*> functions;
        const std::list<const Definition*> definitions;
    };
}
