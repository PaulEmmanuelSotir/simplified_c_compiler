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

    /*IR::ExecutionBlock* While::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* const eb) const
    {
        auto loop_label = cfg.CreateLabel("loop");
        auto loop_condition_label = cfg.CreateLabel("loop_condition");
        eb->AppendInstruction(Jump(condition_block));

        // Loop instructions
        auto* loop_block = cfg.CreateExecutionBlock(eb, loop_label);
        for (auto* instr : instructions)
            loop_block = instr->generateIR(cfg, loop_block);

        auto* condition_block = cfg.CreateExecutionBlock(loop_block, loop_condition_label);
        IR::symbol_t cond_reg = cfg->CreatenewReg();
        condition_block = condition->generateIR(cfg, condition_block, cond_reg);
        condition_block->AppendInstruction(Jump(cond_reg, loop_label));

        return condition_block;
    }*/
}
