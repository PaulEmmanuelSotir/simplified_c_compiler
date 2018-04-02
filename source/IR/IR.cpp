#include "IR/IR.h"
#include "CompilerException.h"
#include "StaticAnalysis.h"
#include "SyntaxModel/Definition.h"
#include "SyntaxModel/Function.h"

namespace IR {
    const std::array<const IR::symbol_t, 6> ControlFlowGraph::args_registers = { "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };

    const symbol_t Instruction::RETQ = "retq";
    const symbol_t Instruction::PUSHQ = "pushq";
    const symbol_t Instruction::POPQ = "popq";
    const symbol_t Instruction::CALL = "call";
    const symbol_t Instruction::MOVQ = "movq";
    const symbol_t Instruction::MOVZBQ = "movzbq";
    const symbol_t Instruction::MOVABSQ = "movabsq";
    const symbol_t Instruction::NOP = "nop";
    const symbol_t Instruction::JNE = "jne";
    const symbol_t Instruction::JE = "je";
    const symbol_t Instruction::JMP = "jmp";
    const symbol_t Instruction::CMPQ = "cmpq";
    const symbol_t Instruction::SETE = "sete";
    const symbol_t Instruction::ADDQ = "addq";
    const symbol_t Instruction::NEGQ = "negq";
    const symbol_t Instruction::IMULL = "imull";
    const symbol_t Instruction::IDIVQ = "idivq";
    const symbol_t Instruction::SUBQ = "subq";
    const symbol_t Instruction::CQO = "cqo";

    Instruction::Instruction(symbol_t op, symbol_t x, symbol_t y, symbol_t dest)
        : op(op)
        , x(x)
        , y(y)
        , dest(dest)
    {
    }

    size_t Instruction::OperandCount() const
    {
        if (x != "" && y != "" && dest != "")
            return 3;
        else if (x != "" && y != "")
            return 2;
        else if (x != "")
            return 1;
        else if (x == "" && y == "" && dest == "")
            return 0;

        throw new CompilerException("Invalid IR instruction operands.");
    }

    void Instruction::GenerateAssembly(std::ostringstream& stream) const
    {
        size_t op_count = OperandCount();
        stream << "\t" << op;
        if (op_count >= 1)
            stream << " " << x;
        if (op_count >= 2)
            stream << ", " << y;
        if (op_count >= 3)
            stream << ", " << dest;
        stream << std::endl;
    }

    IR::ExecutionBlock* Instruction::divide_64bits(IR::ExecutionBlock* eb, bool getRemainder, IR::symbol_t x, IR::symbol_t y, IR::symbol_t dest)
    {
        //TODO: make sure this couldn't be simplified into using IDIV
        const IR::symbol_t rax = "%rax", rdx = "%rdx", rbx = "%rbx"; // TODO: remove it
        eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, x, rax));
        eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, y, rbx));
        eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::CQO));
        eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::IDIVQ, rbx));
        if (getRemainder)
            eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, rdx, dest));
        else
            eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, rax, dest));
        return eb;
    }

    ExecutionBlock::ExecutionBlock(const std::string& label)
        : _label(label)
    {
    }

    void ExecutionBlock::GenerateAssembly(std::ostringstream& stream, std::function<void(const Instruction&)> onInstrGeneration) const
    {
        stream << _label << ":" << std::endl;

        for (auto instr : _instructions) {
            onInstrGeneration(instr);
            instr.GenerateAssembly(stream);
        }
    }

    ExecutionBlock* ExecutionBlock::AppendInstruction(const Instruction& instr)
    {
        _instructions.push_back(instr);
        return this;
    }

    ControlFlowGraph::ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser, const std::string& target)
        : static_analyser(anaylser)
        , _target(target)
    {
        try {
            ast->generateIR(*this, nullptr);
            GenerateAssembly();
        } catch (const CompilerException* e) {
            std::cout << "ERROR: " << e->what() << std::endl;
        }
    }

    ControlFlowGraph::~ControlFlowGraph()
    {
        for (auto p : _blocks)
            delete p.second;
    }

    void ControlFlowGraph::GenerateAssembly()
    {
        // Generate Prolog
        std::ostringstream stream;
        stream << ".glob main" << std::endl;
        stream << ".type main, @function" << std::endl;

        // Generate core assembly
        auto* eb = _first_block;
        while (eb != nullptr) {
            eb->GenerateAssembly(stream, [this](auto instr) {
                _register_counter = 0;
            });
            eb = eb->_next_eb;
        }

        std::cout << stream.str() << std::endl;
    }

    symbol_t ControlFlowGraph::GetFreeRegister(size_t size)
    {
        return "!tmp" + std::to_string(++_register_counter);
    }

    StackVariable::StackVariable(int64_t offset, size_t size, const utils::TerminalInfo& name)
        : offset(offset)
        , size(size)
        , name(name)
    {
    }

    symbol_t StackVariable::toAddressOperandSyntax() const
    {
        return AddressOperandSyntax("%rsp", offset);
    }

    std::string ControlFlowGraph::CreateLabel(std::string prefix, const SyntaxModel::SyntaxNodeBase* node)
    {
        static std::unordered_map<std::string, size_t> label_counters;

        if (node != nullptr) {
            // Append function name to label if given node is a children of a function
            auto* func = node->getFirstParentOfType<SyntaxModel::Function>();
            if (func != nullptr)
                prefix = func->id.text + "." + prefix;
        }

        // If we already created a label with the same name, we increment its counter
        if (label_counters.find(prefix) != label_counters.end()) {
            size_t count = ++label_counters[prefix];
            prefix += "_" + std::to_string(count);
        } else
            label_counters.emplace(prefix, 0);
        return prefix;
    }

    ExecutionBlock* ControlFlowGraph::CreateExecutionBlock(const std::string& label, ExecutionBlock* const eb_to_queue_on)
    {
        auto eb = _makeExecutionBlock(label);
        if (_first_block == nullptr)
            _first_block = eb;
        if (eb_to_queue_on != nullptr) {
            if (eb_to_queue_on->_next_eb != nullptr)
                throw new CompilerException("'eb_to_queue_on' execution block already have a pointer to its next block");
            eb_to_queue_on->_next_eb = eb;
        }
        return eb;
    }

    std::experimental::optional<StackVariable> ControlFlowGraph::getStackVariableFromVariable(const StaticAnalysis::Variable& var, const SyntaxModel::SyntaxNodeBase* node)
    {
        auto func = node->getFirstParentOfType<SyntaxModel::Function>();
        if (func != nullptr) {
            auto stack_defs_it = func->stackVariables.find(var.def_unique_id);
            if (stack_defs_it != func->stackVariables.end()) {
                for (const IR::StackVariable& stack_var : stack_defs_it->second) {
                    if (stack_var.name.text == var.name.text)
                        return stack_var;
                }
            }
            throw new CompilerException("Couldn't find stack variable from a local variable");
        }
        return std::experimental::nullopt;
    }

    ExecutionBlock* ControlFlowGraph::_makeExecutionBlock(const std::string& label)
    {
        auto b = new ExecutionBlock(label);
        _blocks.emplace(label, b);
        return b;
    }
}
