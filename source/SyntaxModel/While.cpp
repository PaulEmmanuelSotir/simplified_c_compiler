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
        auto cond_reg = cfg.GetFreeRegister(8);

        IR::symbol_t while_body_label = cfg.CreateLabel("while_body", this);
        eb->AppendInstruction(IR::Instruction(IR::Instruction::JMP, while_body_label));

        auto* while_body = cfg.CreateExecutionBlock(while_body_label, eb);
        while_body = condition->generateIR(cfg, while_body, cond_reg);

        IR::symbol_t while_end_label = cfg.CreateLabel("while_end", this);
        auto* while_end = cfg.CreateExecutionBlock(while_end_label, while_body);

        while_body->AppendInstruction(IR::Instruction(IR::Instruction::CMPQ, IR::ControlFlowGraph::CreateConstant(0), cond_reg));
        while_body->AppendInstruction(IR::Instruction(IR::Instruction::JE, while_end_label));

        for (auto* instr : instructions)
            while_body = instr->generateIR(cfg, while_body, "");
        while_body->AppendInstruction(IR::Instruction(IR::Instruction::JMP, while_body_label));

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
        return while_end;
    }
}
