#pragma once
#include <array>
#include <list>
#include <string>
#include <unordered_map>

#include "SyntaxModel/PrimitiveType.h"
#include "optional.h"
#include "utils.h"

namespace StaticAnalysis {
    class StaticAnalyser;
    class Variable;
}

namespace SyntaxModel {
    struct Program;
    struct Definition;
}

namespace IR {
    using symbol_t = std::string;
    class ExecutionBlock;

    struct Instruction {
        static const symbol_t RETQ;
        static const symbol_t PUSHQ;
        static const symbol_t POPQ;
        static const symbol_t CALL;
        static const symbol_t MOVQ;
        static const symbol_t MOVZBQ;
        static const symbol_t MOVABSQ;
        static const symbol_t NOP;
        static const symbol_t JUMP_NE;
        static const symbol_t CMPQ;
        static const symbol_t SETE;
        static const symbol_t ADDQ;
        static const symbol_t NEGQ;
        static const symbol_t IMULL;
        static const symbol_t IDIVQ;
        static const symbol_t SUBQ;
        static const symbol_t CQO;

        Instruction(symbol_t op = NOP, symbol_t x = "", symbol_t y = "", symbol_t dest = "");
        void GenerateAssembly(std::ostringstream& stream) const;
        size_t OperandCount() const;
        static ExecutionBlock* divide_64bits(ExecutionBlock* eb, bool getRemainder, symbol_t x, symbol_t y, symbol_t dest);

        const symbol_t op;
        const symbol_t x;
        const symbol_t y;
        const symbol_t dest;
    };

    class ControlFlowGraph;

    class ExecutionBlock {
    public:
        ExecutionBlock* AppendInstruction(const Instruction& instr);

    private:
        void GenerateAssembly(std::ostringstream& stream, std::function<void(const Instruction&)> onInstrGeneration) const;
        ExecutionBlock(const std::string& label);
        ExecutionBlock* _next_eb = nullptr;
        const std::string _label;
        std::list<Instruction> _instructions;

        friend class ControlFlowGraph;
    };

    struct StackVariable {
        StackVariable(int64_t offset, size_t size, const utils::TerminalInfo& name);
        symbol_t toAddressOperandSyntax() const;
        const int64_t offset;
        const size_t size;
        const utils::TerminalInfo name;
    };

    class ControlFlowGraph final {
    public:
        ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser, const std::string& target);
        ~ControlFlowGraph();
        void GenerateAssembly();

        template <typename T>
        static inline symbol_t CreateConstant(const T& value) { return "$" + std::to_string(value); }

        symbol_t GetFreeRegister(size_t size);
        std::string CreateLabel(const std::string& prefix);
        ExecutionBlock* CreateExecutionBlock(const std::string& label, ExecutionBlock* const eb_to_queue_on);
        static std::experimental::optional<StackVariable> getStackVariableFromVariable(const StaticAnalysis::Variable& var, const SyntaxModel::SyntaxNodeBase* node);

        const StaticAnalysis::StaticAnalyser* const static_analyser;
        static const std::array<const IR::symbol_t, 6> args_registers;

    private:
        ExecutionBlock* _makeExecutionBlock(const std::string& label);
        std::unordered_map<std::string, ExecutionBlock*> _blocks;
        ExecutionBlock* _first_block = nullptr;
        size_t _register_counter = 0;
        const std::string& _target;
    };

    template <typename OffsetT>
    symbol_t AddressOperandSyntax(symbol_t reg, OffsetT offset = OffsetT(), symbol_t mult_offset = "")
    {
        std::stringstream st;
        if (offset == OffsetT())
            st << "(" << reg;
        else {
            if (std::is_same<OffsetT, int64_t>::value)
                st << offset << "(";
            else
                st << "(" << offset << ", ";
            st << reg;
        }
        if (mult_offset != "")
            st << ", " << mult_offset;
        st << ")";
        return st.str();
    }
}
