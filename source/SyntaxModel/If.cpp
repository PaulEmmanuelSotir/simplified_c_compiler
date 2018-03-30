#include "SyntaxModel/If.h"

namespace SyntaxModel {

    If::If(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions, const Else* else_clause)
        : Structure(source_interval, condition, instructions, { else_clause })
        , else_clause(else_clause)
    {
    }

    std::ostream& If::toString(std::ostream& os) const
    {
        os << "if(" << *condition << ") {" << std::endl;
        for (auto instr : instructions)
            os << *instr;
        os << "}" << std::endl;
        if (else_clause != nullptr)
            os << *else_clause;
        return os;
    }

    /*IR::ExecutionBlock* If::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* const eb) const
    {
        auto if_label = cfg.CreateLabel("if");
        IRVariable cond_reg = cfg->CreateTempIRVar();
        auto* eb = condition->generateIR(cfg, eb, { cond_reg });
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::CMP, 0, IR::ControlFlowGraph::CreateConstant(0), cond_reg));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::JUMP_NE));

        for (auto* instr : instructions)
            eb = instr->generateIR(cfg, eb);

        auto* if_block = cfg.CreateExecutionBlock(if_label, if_block);

        if (else_clause != nullptr)
            return else_clause->generateIR(cfg, eb);
        else
            return if_block;
    }*/
}
