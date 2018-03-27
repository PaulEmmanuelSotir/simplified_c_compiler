#pragma once
#include <list>
#include <string>

#include "SyntaxModel/SyntaxModel.h"

namespace IR {
    class BasicBlock;
    using symbol_t = size_t;

    struct Instruction {
        enum class Op {
            RET,
            PUSH,
            POP,
            CALL,
            MOV,
            NOP
        };

        Instruction(Op op = Op::NOP, symbol_t dest = 0, symbol_t x = 0, symbol_t y = 0);

        const Op op;
        const symbol_t dest;
        const symbol_t x;
        const symbol_t y;
    };

    class ControlFlowGraph;

    class ExecutionBlock {
    private:
        ExecutionBlock(const std::string& label, const std::list<Instruction>& instructions);
        friend ExecutionBlock* ControlFlowGraph::_makeExecutionBlock(const std::string& label, const std::list<Instruction>& instructions);
        ExecutionBlock* _next_true = nullptr;
        ExecutionBlock* _next_false = nullptr;
        const std::string _label;
        const std::list<Instruction> _instructions;
    };

    class ControlFlowGraph final {
    public:
        ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser);
        ~ControlFlowGraph();
        symbol_t CreatenewReg();
        void AppendExecutionBlock(const std::string& label, const std::list<Instruction>& instructions);

    private:
        ExecutionBlock* _makeExecutionBlock(const std::string& label, const std::list<Instruction>& instructions);

        std::unordered_map<symbol_t, ExecutionBlock*> _blocks;
        ExecutionBlock* _global_block;
        ExecutionBlock* _last_block;
    };
}
