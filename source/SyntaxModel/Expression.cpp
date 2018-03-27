#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"

#include "StaticAnalysis.h"

namespace SyntaxModel {

    Expression::Expression(const antlr4::misc::Interval& source_interval, const std::list<const SyntaxNodeBase*>& children)
        : Instruction(source_interval, children)
    {
    }

    VariableUsage::VariableUsage(const antlr4::misc::Interval& source_interval, const Identifier& name)
        : Expression(source_interval)
        , name(name)
    {
    }

    std::ostream& Expression::toString(std::ostream& os) const
    {
        os << "expression" << std::endl;
        return os;
    }

    std::ostream& VariableUsage::toString(std::ostream& os) const
    {
        os << name;
        return os;
    }

    Type VariableUsage::getExprType(const StaticAnalysis::StaticAnalyser* analyser) const
    {
        auto var = analyser->getVariableOfUsage(this);
        return *(var.type);
    }
}
