#include "SyntaxModel/Function.h"
#include "SyntaxModel/PrimitiveType.h"
#include "SyntaxModel/Return.h"
#include "utils.h"

namespace SyntaxModel {

    Args::Args(const antlr4::misc::Interval& source_interval, const std::list<const Type*>& types, const std::vector<Identifier>& names)
        : SyntaxNodeBase(source_interval, utils::container_cast(types))
        , types(types)
        , names(names)
    {
    }

    Function::Function(const antlr4::misc::Interval& source_interval, const std::list<const Definition*>& definitions, const std::list<const Instruction*>& instructions, const Args* arguments, const Identifier& id, const Type* returnType)
        : SyntaxNodeBase(source_interval, utils::children_list(definitions, instructions, arguments, returnType))
        , definitions(definitions)
        , instructions(instructions)
        , arguments(arguments)
        , id(id)
        , returnType(returnType)
        , stackVariables(computeARStack(arguments, definitions))
    {
    }

    static const antlr4::misc::Interval _dummy_interval;

    Putchar::Putchar()
        : Function(_dummy_interval, {}, {}, new Args(_dummy_interval, { new Type(_dummy_interval, PrimitiveType::INT32_T, false) }, { Identifier("character") }), Identifier("putchar"), new Type(_dummy_interval, PrimitiveType::INT32_T, false))
    {
    }

    std::ostream& Function::toString(std::ostream& os) const
    {
        if (returnType == nullptr)
            os << "void ";
        else
            os << *(returnType) << " ";
        os << id;
        os << "(";
        if (arguments != nullptr)
            os << *(arguments);
        os << ") {" << endl;
        for (auto dec : definitions)
            os << *dec;
        for (auto instr : instructions)
            os << *instr;
        os << "}" << endl;
        return os;
    }

    void Function::generateIREpilogue(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, size_t reservedStackSize) const
    {
        const std::string rbp = "%rbp", rsp = "%rsp";
        if (reservedStackSize > 0)
            eb->AppendInstruction(IR::Instruction(IR::Instruction::ADDQ, cfg.CreateConstant(reservedStackSize), rsp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::POPQ, rbp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::RETQ));
    }

    IR::ExecutionBlock* Function::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb) const
    {
        if (!this->is<Putchar>()) {
            const std::string rbp = "%rbp", rsp = "%rsp", rax = "%rax";
            eb = cfg.CreateExecutionBlock(id.text, eb);

            // Generate prologue: Reserve function stack size and update rsp and rbp registers
            size_t reservedStackSize = getARStackSize();
            eb->AppendInstruction(IR::Instruction(IR::Instruction::PUSHQ, rbp));
            eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, rsp, rbp));
            if (reservedStackSize > 0)
                eb->AppendInstruction(IR::Instruction(IR::Instruction::SUBQ, cfg.CreateConstant(reservedStackSize), rsp));
            pullArgsFromRegisters(eb, rbp);

            for (auto* def : definitions) {
                auto stack_var_it = stackVariables.find(def->unique_id);
                eb = def->generateIR(cfg, eb, stack_var_it->second);
            }
            for (auto* instr : instructions) {
                eb = instr->generateIR(cfg, eb, "");
                if (instr->is<Return>())
                    return eb;
            }

            // If we reach the end of eb, it means we didn't executed any main return statements (thus we return 0)
            if (id.text == "main")
                eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, IR::ControlFlowGraph::CreateConstant(0), rax));

            // Generate epilogue
            generateIREpilogue(cfg, eb, reservedStackSize);
        }
        return eb;
    }

    size_t Function::getARStackSize() const
    {
        size_t reserved_size = (arguments != nullptr ? arguments->names.size() * 8 : 0);
        for (const auto* def : definitions)
            reserved_size += def->names.size() * 8;
        return reserved_size+8;  // Avoid segmentation fault
    }

    void Function::pullArgsFromRegisters(IR::ExecutionBlock* eb, std::string rbp) const
    {
        if (arguments != nullptr) {
            for (size_t r_idx = 0; r_idx < arguments->names.size(); ++r_idx)
                eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, IR::ControlFlowGraph::args_registers[r_idx], "-" + std::to_string(8 * r_idx) + "(" + rbp + ")"));
        }
    }

    std::unordered_map<size_t, std::vector<IR::StackVariable>> Function::computeARStack(const Args* args, const std::list<const Definition*>& defs)
    {
        std::unordered_map<size_t, std::vector<IR::StackVariable>> stackVariables;
        int64_t offset = 0;
        for (auto* def : defs) {
            std::vector<IR::StackVariable> vars;
            vars.reserve(def->names.size());
            for (auto n : def->names) {
                offset -= 8;
                vars.emplace_back(offset, 8, n);
            }
            stackVariables.emplace(def->unique_id, vars);
        }
        return stackVariables;
    }

    IR::ExecutionBlock* Args::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb) const
    {
        return eb;
    }

    std::ostream& Args::toString(std::ostream& os) const
    {
        int i = 0;
        for (auto type : types) {
            os << *type << names[i];
            if (types.size() > 1)
                os << ", ";
            i++;
        }
        return os;
    }
}
