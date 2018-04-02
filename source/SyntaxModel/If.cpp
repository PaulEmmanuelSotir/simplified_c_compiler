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
        auto cond_reg = cfg.GetFreeRegister(8);
        eb = condition->generateIR(cfg, eb, cond_reg); // TODO: split condition expression on && and || binary operator in order to avoid evaluating unescessary expressions
        IR::symbol_t end_if_then_label = cfg.CreateLabel("end_if", this);

        eb->AppendInstruction(IR::Instruction(IR::Instruction::CMPQ, IR::ControlFlowGraph::CreateConstant(0), cond_reg));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::JE, end_if_then_label));

        for (auto* instr : instructions)
            eb = instr->generateIR(cfg, eb, "");
        auto* end_if_then = cfg.CreateExecutionBlock(end_if_then_label, eb);

        if (else_clause != nullptr) {
            IR::symbol_t end_else_label = cfg.CreateLabel("end_else", this);
            eb->AppendInstruction(IR::Instruction(IR::Instruction::JMP, end_else_label));
            end_if_then = else_clause->generateIR(cfg, end_if_then);
            return cfg.CreateExecutionBlock(end_else_label, end_if_then);
        }
        return end_if_then;
    }
}
