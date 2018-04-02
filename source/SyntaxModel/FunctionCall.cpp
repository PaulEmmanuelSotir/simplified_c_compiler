#include <array>

#include "CompilerException.h"
#include "StaticAnalysis.h"
#include "SyntaxModel/FunctionCall.h"
#include "utils.h"

namespace SyntaxModel {
    FunctionCall::FunctionCall(const antlr4::misc::Interval& source_interval, const list<const Expression*>& args, const Identifier& func_name)
        : Expression(source_interval, utils::container_cast(args))
        , args(args)
        , func_name(func_name)
    {
    }

    std::ostream& FunctionCall::toString(std::ostream& os) const
    {
        os << func_name << "(";
        for (auto arg : args)
            os << *arg;
        os << ")";
        return os;
    }

    Type FunctionCall::getExprType(const StaticAnalysis::StaticAnalyser* analyser) const
    {
        // Returns called function return type
        auto function = analyser->getFunctionDef(this);
        return *(function->returnType);
    }

    IR::ExecutionBlock* FunctionCall::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const
    {
        //  Generate IR instructions for arguments expressions
        if (IR::ControlFlowGraph::args_registers.size() < args.size())
            throw new CompilerException("function can't have more than " + std::to_string(IR::ControlFlowGraph::args_registers.size()) + " arguments due to assembly function call convention");
        for (size_t idx = 0; idx < args.size(); ++idx)
            eb = (*utils::get_at(args, idx))->generateIR(cfg, eb, IR::ControlFlowGraph::args_registers[idx]);

        // Call function
        const auto* function = cfg.static_analyser->getFunctionDef(this);
        const auto* func_args = function->arguments;
        if (func_args != nullptr && func_args->names.size() != args.size())
            throw new CompilerException("function '" + func_name.text + "' called with the wrong number of arguments");
        eb->AppendInstruction(IR::Instruction(IR::Instruction::CALL, func_name.text));
        if (dest != "")
            eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, "%rax", dest));
        return eb;
    }
}
