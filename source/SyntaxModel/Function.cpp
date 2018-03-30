#include "SyntaxModel/Function.h"
#include "SyntaxModel/PrimitiveType.h"
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

    IR::ExecutionBlock* Function::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb) const
    {
        const std::string rbp = "%rbp", rsp = "%rsp";
        eb = cfg.CreateExecutionBlock(id.text, eb);

        // Generate prologue: Reserve function stack size and update rsp and rbp registers
        size_t reserved_size = arguments->names.size() * 8;
        for (auto* def : definitions)
            reserved_size += def->names.size() * 8;
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::PUSH, rbp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::MOV, rsp, rbp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::SUB, cfg.CreateConstant(reserved_size), rbp));

        //eb = args->generateIR(cfg, eb);
        //for (auto* decl : declarations)
        //    eb = decl->generateIR(cfg, eb);
        //for (auto* instr : instructions)
        //    eb = instr->generateIR(cfg, eb);
        // TODO: handle return statement type (make a variable for return value?)

        // Generate epilogue
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::ADD, cfg.CreateConstant(reserved_size), rbp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::POP, rbp));
        eb->AppendInstruction(IR::Instruction(IR::Instruction::Op::RET));
        return eb;
    }

    IR::ExecutionBlock* Args::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* const eb) const
    {
        return nullptr;
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
