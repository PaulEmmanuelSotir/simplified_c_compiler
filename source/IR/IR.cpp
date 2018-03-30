#include "IR/IR.h"
#include "StaticAnalysis.h"
#include "SyntaxModel/Definition.h"

namespace IR {
    Instruction::Instruction(Op op, symbol_t x, symbol_t y, symbol_t dest)
        : op(op)
        , x(x)
        , y(y)
        , dest(dest)
    {
    }

    void Instruction::GenerateAssembly(std::ostringstream& stream) const
    {
        stream << "\t";
        switch (op) {
        case Op::RET:
            stream << "retq";
            break;
        case Op::ADD:
            stream << "addq " << x << ", " << y;
            break;
        case Op::SUB:
            stream << "subq " << x << ", " << y;
            break;
        case Op::PUSH:
            stream << "pushq " << x;
            break;
        case Op::POP:
            stream << "popq " << x;
            break;
        case Op::CALL:
            break;
        case Op::MOV:
            stream << "movq " << x << ", " << y;
            break;
        case Op::NOP:
            break;
        case Op::JUMP_NE:
            break;
        case Op::CMP:
            break;
        }
        stream << std::endl;
    }

    ExecutionBlock::ExecutionBlock(const std::string& label)
        : _label(label)
    {
    }

    void ExecutionBlock::GenerateAssembly(std::ostringstream& stream) const
    {
        stream << _label << ":" << std::endl;

        for (auto instr : _instructions)
            instr.GenerateAssembly(stream);
    }

    void ExecutionBlock::AppendInstruction(const Instruction& instr)
    {
        _instructions.push_back(instr);
    }

    IRVariable::IRVariable(const symbol_t& symbol, const SyntaxModel::PrimitiveType type, const bool isTemp, const size_t size, const size_t offset)
        : symbol(symbol)
        , type(type)
        , isTemporary(isTemp)
        , size(size)
        , offset(offset)
    {
    }

    ControlFlowGraph::ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser, const std::string& target)
        : _target(target)
    {
        ast->generateIR(*this, nullptr);
        GenerateAssembly();
    }

    ControlFlowGraph::~ControlFlowGraph()
    {
        for (auto p : _blocks)
            delete p.second;
    }

    void ControlFlowGraph::GenerateAssembly() const
    {
        // Generate Prolog
        std::ostringstream stream;
        stream << ".glob main" << std::endl;
        stream << ".type main, @function" << std::endl;

        // Generate core assembly
        auto* eb = _first_block;
        while (eb != nullptr) {
            eb->GenerateAssembly(stream);
            eb = eb->_next_eb;
        }

        std::cout << stream.str() << std::endl;
    }

    symbol_t ControlFlowGraph::CreateIRVar(const SyntaxModel::Definition* varDef) const
    {
        if (varDef == nullptr) {
            // TODO: throw error
        }

        //IRVariable(varDef->name.text, varDef->type->type, )

        static size_t count = 0;
        return std::to_string(++count);
    }

    std::string ControlFlowGraph::CreateLabel(const std::string& prefix)
    {
        static size_t count = 0;
        return prefix + "_" + std::to_string(++count);
    }

    ExecutionBlock* ControlFlowGraph::CreateExecutionBlock(const std::string& label, ExecutionBlock* const eb_to_queue_on)
    {
        auto eb = _makeExecutionBlock(label);
        if (_first_block == nullptr)
            _first_block = eb;
        if (eb_to_queue_on != nullptr) {
            if (eb_to_queue_on->_next_eb != nullptr) {
                // TODO: throw error (this execution block already have a pointer to its next block)
            }
            eb_to_queue_on->_next_eb = eb;
        }
        return eb;
    }

    ExecutionBlock* ControlFlowGraph::_makeExecutionBlock(const std::string& label)
    {
        auto b = new ExecutionBlock(label);
        _blocks.emplace(label, b);
        return b;
    }
}
