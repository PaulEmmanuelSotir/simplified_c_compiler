#include "SyntaxModel/Return.h"
#include "SyntaxModel/Function.h"

namespace SyntaxModel {

    Return::Return(const antlr4::misc::Interval& source_interval, const Expression* expression)
        : Instruction(source_interval, { expression })
        , expression(expression)
    {
    }

    std::ostream& Return::toString(std::ostream& os) const
    {
        os << "return" << std::endl;
        return os;
    }

    IR::ExecutionBlock* Return::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t result_register) const
    {
        // Generate IR instructions to compute return expression
        if (expression != nullptr)
            eb = expression->generateIR(cfg, eb, "%rax");

        // Generate function call epilogue
        const auto* func = SyntaxNodeBase::getFirstParentOfType<SyntaxModel::Function>(this);
        if (func != nullptr)
            func->generateIREpilogue(cfg, eb, func->getARStackSize());
        else
            throw new CompilerException("Return statement outside of any function definition");
        return eb;
    }
}
