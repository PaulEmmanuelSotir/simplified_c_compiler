#pragma once
#include <list>

#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Instruction.h"
#include "SyntaxModel/SyntaxNode.h"
#include "SyntaxModel/Type.h"

namespace SyntaxModel {

    struct Args final : public SyntaxNodeBase {
        Args(const antlr4::misc::Interval& source_interval, const std::list<const Type*>& types, const std::vector<Identifier>& names);
        virtual ~Args() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Args>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;

        const std::list<const Type*> types;
        const std::vector<Identifier> names;
    };

    struct Function final : public SyntaxNodeBase {
        Function(const antlr4::misc::Interval& source_interval, const std::list<const Definition*>& definitions, const std::list<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType);
        virtual ~Function() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Function>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;
        friend inline bool operator<(const Function& lhs, const Function& rhs) { return lhs.id < rhs.id; }

        const std::list<const Definition*> definitions;
        const std::list<const Instruction*> instructions;
        const Args* arguments;
        const Identifier id;
        const Type* returnType;
    };
}
