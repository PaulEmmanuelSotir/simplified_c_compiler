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

    IR::ExecutionBlock* If::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const
    {
        return eb;
        /*
        auto* if_block = cfg.CreateExecutionBlock("if", if_block);
        IRVariable cond_reg = cfg->CreateTempIRVar();
        auto* eb = condition->generateIR(cfg, eb, { cond_reg }); // TODO: split condition expression on && and || binary operator in order to avoid evaluating unescessary expressions
        // TODO: put jump instructions into Execution blocks?
        eb->AppendInstruction(IR::Instruction(IR::Instruction::CMPQ, 0, IR::ControlFlowGraph::CreateConstant(0), cond_reg));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::JMP_NE, if_block->label));

        for (auto* instr : instructions)
            eb = instr->generateIR(cfg, eb);


        if (else_clause != nullptr)
            return else_clause->generateIR(cfg, eb);
        else
            return if_block;*/
    }
}
