#include "SyntaxModel/Expression.h"
#include "SyntaxModel/SyntaxNode.h"

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
}
