#pragma once
#include <list>
#include <string>
#include <unordered_map>

#include "SyntaxModel/PrimitiveType.h"

namespace StaticAnalysis {
    class StaticAnalyser;
}

namespace SyntaxModel {
    struct Program;
    struct Definition;
}

namespace IR {
    using symbol_t = std::string;

    struct Instruction {
        enum class Op {
            RET,
            PUSH,
            POP,
            CALL,
            MOV,
            NOP,
            JUMP_NE,
            CMP
        };

        Instruction(Op op = Op::NOP, symbol_t x = "", symbol_t y = "", symbol_t dest = "");
        void GenerateAssembly(std::ostringstream& stream) const;

        const Op op;
        const symbol_t x;
        const symbol_t y;
        const symbol_t dest;
    };

    class ControlFlowGraph;

    class ExecutionBlock {
    public:
        void AppendInstruction(const Instruction& instr);

    private:
        void GenerateAssembly(std::ostringstream& stream) const;
        ExecutionBlock(const std::string& label);
        ExecutionBlock* _next_eb = nullptr;
        const std::string _label;
        std::list<Instruction> _instructions;

        friend class ControlFlowGraph;
    };

    struct IRVariable {
        IRVariable(const symbol_t& symbol, const SyntaxModel::PrimitiveType type, const bool isTemp = false, const size_t size = 8, const size_t offset = 0);

        const symbol_t symbol;
        const SyntaxModel::PrimitiveType type;
        const bool isTemporary;
        const size_t size;
        const size_t offset;
    };

    class ControlFlowGraph final {
    public:
        ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser, const std::string& target);
        ~ControlFlowGraph();
        void GenerateAssembly() const;

        template <typename T>
        static inline symbol_t CreateConstant(const T& value) { return "$" + std::to_string(value); }

        symbol_t CreateIRVar(const SyntaxModel::Definition* varDef) const;
        IRVariable CreateTempIRVar() const;
        std::string CreateLabel(const std::string& prefix);
        ExecutionBlock* CreateExecutionBlock(const std::string& label, ExecutionBlock* const eb_to_queue_on);

    private:
        ExecutionBlock* _makeExecutionBlock(const std::string& label);
        ExecutionBlock* _first_block = nullptr;
        std::unordered_map<std::string, ExecutionBlock*> _blocks;
        const std::string& _target;
    };
}
