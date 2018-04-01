#include "SyntaxModel/While.h"

namespace SyntaxModel {

    While::While(const antlr4::misc::Interval& source_interval, const Expression* condition, const std::list<const Instruction*>& instructions)
        : Structure(source_interval, condition, instructions)
    {
    }

    std::ostream& While::toString(std::ostream& os) const
    {
        os << "while(" << *condition << ") {" << std::endl;
        for (auto instr : instructions)
            os << *instr;
        os << "}" << std::endl;
        return os;
    }

    IR::ExecutionBlock* While::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const
    {
        /* 
        auto* loop_block = cfg.CreateExecutionBlock(eb, "loop");
        auto* condition_block = cfg.CreateExecutionBlock(loop_block, "loop_condition");
        // TODO: put jump instructions into Execution blocks?
        eb->AppendInstruction(IR::Instruction(IR::Instruction::JMP, condition_block->label));

        // Loop instructions
        for (auto* instr : instructions)
            loop_block = instr->generateIR(cfg, loop_block);

        IR::symbol_t cond_reg = cfg->CreatenewReg();
        condition_block = condition->generateIR(cfg, condition_block, cond_reg);
        eb->AppendInstruction(IR::Instruction(IR::Instruction::CMPQ, 0, IR::ControlFlowGraph::CreateConstant(0), cond_reg));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::JUMP_NE, loop_block->label));

        return condition_block;*/
        return eb;
    }
}
