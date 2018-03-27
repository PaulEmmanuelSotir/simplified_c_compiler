#include "IR/IR.h"

namespace IR {
    Instruction::Instruction(Op op, symbol_t dest, symbol_t x, symbol_t y)
        : op(op)
        , dest(dest)
        , x(x)
        , y(y)
    {
    }

    ExecutionBlock::ExecutionBlock(const std::string& label, const std::list<Instruction>& instructions)
        : _label(label)
        , _instructions(instructions)
    {
    }

    ControlFlowGraph::ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser)
    {
        for (const auto& func : ast->functions) {
            if (func->id.text == "main") {
                std::list<Instruction> instrs;
                auto rbp = CreatenewReg();
                auto rsp = CreatenewReg();
                instrs.emplace_back(Instruction::Op::PUSH, rbp);
                instrs.emplace_back(Instruction::Op::MOV, rsp, rbp);

                if (func->instructions.size() == 0)
                    instrs.emplace_back(Instruction::Op::NOP);

                instrs.emplace_back(Instruction::Op::POP, rbp);
                instrs.emplace_back(Instruction::Op::RET);
                _last_block = ExecutionBlock(func->id.text, instrs);
            }
        }
    }

    ControlFlowGraph::~ControlFlowGraph()
    {
        for (auto p : _blocks)
            delete p->second;
    }

    size_t ControlFlowGraph::CreatenewReg()
    {
        static size_t count = 0;
        return ++count;
    }

    void ControlFlowGraph::AppendExecutionBlock(const std::string& label, const std::list<Instruction>& instructions)
    {
        auto block = _makeExecutionBlock(label, instructions);
    }

    ExecutionBlock* ControlFlowGraph::_makeExecutionBlock(const std::string& label, const std::list<Instruction>& instructions)
    {
        auto b = new ExecutionBlock(label, instructions);
        _blocks.emplace(label, b);
        return b;
    }
}
