#include "IR/IR.h"
#include "StaticAnalysis.h"
#include "SyntaxModel/Definition.h"

namespace IR {
    Instruction::Instruction(Op op, symbol_t dest, symbol_t x, symbol_t y)
        : op(op)
        , dest(dest)
        , x(x)
        , y(y)
    {
    }

    ExecutionBlock::ExecutionBlock(const std::string& label)
        : _label(label)
    {
    }

    IRVariable::IRVariable(const symbol_t& symbol, const SyntaxModel::PrimitiveType type, const bool isTemp, const size_t size, const size_t offset)
        : symbol(symbol)
        , type(type)
        , isTemporary(isTemp)
        , size(size)
        , offset(offset)
    {
    }

    ControlFlowGraph::ControlFlowGraph(const SyntaxModel::Program* ast, const StaticAnalysis::StaticAnalyser* anaylser)
    {
        ast->generateIR(*this, nullptr);
        /*
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
        }*/
    }

    ControlFlowGraph::~ControlFlowGraph()
    {
        for (auto p : _blocks)
            delete p.second;
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
