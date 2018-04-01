#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"
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

    IR::ExecutionBlock* VariableUsage::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const
    {
        StaticAnalysis::Variable var = cfg.static_analyser->getVariableOfUsage(this);
        auto func = getFirstParentOfType<Function>();
        if (func != nullptr) {
            auto stack_defs_it = func->stackVariables.find(var.def_unique_id);
            if (stack_defs_it != func->stackVariables.end()) {
                for (const IR::StackVariable& stack_var : stack_defs_it->second) {
                    if (stack_var.name.text == name.text)
                        return eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, stack_var.toAddressOperandSyntax(), dest));
                }
            }
            throw new CompilerException("Couldn't find stack variable from a local variable definition (got from its VariableUsage)");
        }
        // TODO: handle globals here
        return eb;
    }
}
