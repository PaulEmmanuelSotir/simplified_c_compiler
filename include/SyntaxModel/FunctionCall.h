#pragma once
#include <list>

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"

namespace SyntaxModel {
    struct FunctionCall final : public Expression {
        FunctionCall(const antlr4::misc::Interval& source_interval, const std::list<const Expression*>& args, const Identifier& func_name);
        virtual ~FunctionCall() = default;
        virtual std::unordered_set<std::string> getTypenames() const override { return TN<Instruction, Expression, FunctionCall>::typenames(); }
        virtual std::ostream& toString(std::ostream& os) const override;
        virtual Type getExprType(const StaticAnalysis::StaticAnalyser* analyser) const override;

        const std::list<const Expression*> args;
        const Identifier func_name;
    };
}
