#include "SyntaxModel/BinaryOp.h"
#include "SyntaxModel/PrimitiveType.h"

namespace SyntaxModel {

    BinaryOp::BinaryOp(const antlr4::misc::Interval& source_interval, const Expression* leftExpression, const Expression* rightExpression, const Op op)
        : Expression(source_interval, { leftExpression, rightExpression })
        , leftExpression(leftExpression)
        , rightExpression(rightExpression)
        , op(op)
    {
    }

    std::ostream& BinaryOp::toString(std::ostream& os) const
    {
        os << *(leftExpression) << " op" << static_cast<std::underlying_type<BinaryOp::Op>::type>(op) << " " << *(rightExpression);
        return os;
    }

    Type BinaryOp::getExprType(const StaticAnalysis::StaticAnalyser* analyser) const
    {
        // Returns type according to sub expressions, implicit cast rules and operator type rules
        auto left_type = leftExpression->getExprType(analyser);
        auto right_type = leftExpression->getExprType(analyser);

        if (left_type.isArray || right_type.isArray)
            // TODO: make an alias for pointer type depending on target architecture
            return Type(source_interval, PrimitiveType::INT64_T, false); // BinaryOps interprets arrays as pointers (INT64_T);

        if (op == Op::AND || op == Op::OR || op == Op::SUP || op == Op::SUP_EQ || op == Op::INF || op == Op::INF_EQ || op == Op::DIFFERENT || op == Op::EQUAL)
            return Type(source_interval, PrimitiveType::INT32_T, false); // Implicit cast to boolean (INT32_T)
        else {
            if (left_type.type == PrimitiveType::INT64_T || right_type.type == PrimitiveType::INT64_T)
                return Type(source_interval, PrimitiveType::INT64_T, false);
            return Type(source_interval, PrimitiveType::INT32_T, false);
        }
    }

    IR::ExecutionBlock* BinaryOp::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t dest) const
    {
        IR::symbol_t leftExpressionReg = cfg.GetFreeRegister(8);
        IR::symbol_t rightExpressionReg = cfg.GetFreeRegister(8);
        eb = leftExpression->generateIR(cfg, eb, leftExpressionReg);
        eb = rightExpression->generateIR(cfg, eb, rightExpressionReg);

        switch (op) {
        case Op::PLUS:
        case Op::MINUS:
            eb = eb->AppendInstruction(IR::Instruction((op == Op::PLUS ? IR::Instruction::ADDQ : IR::Instruction::SUBQ), rightExpressionReg, leftExpressionReg));
            eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, leftExpressionReg, dest));
            break;
        case Op::MULT:
            /*Type t = getExprType(cfg.static_analyser);
            if (t.type != Type::PrimitiveType::INT64_T) {
                if (t.type == Type::PrimitiveType::INT32_T)
                    eb->AppendInstruction(IR::Instruction(IR::Instruction::IMULL, subExprReg1, subExprReg2));
                else if (t.type == Type::PrimitiveType::CHAR)
                    eb->AppendInstruction(IR::Instruction(IR::Instruction::IMULL, subExprReg1, subExprReg2, subExprReg2));
                else
                    throw new CompilerException("Expesssion type not supported");
            } else {*/
            //TODO: make sure I don't need IMULQ here instead of IMULL
            eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::IMULL, leftExpressionReg, rightExpressionReg, rightExpressionReg));
            eb = eb->AppendInstruction(IR::Instruction(IR::Instruction::MOVQ, rightExpressionReg, dest));
            break;
        case Op::MODULO:
        case Op::DIV: {
            eb = IR::Instruction::divide_64bits(eb, op == Op::MODULO, leftExpressionReg, rightExpressionReg, dest);
            break;
        }
        case Op::EQUAL:

            break;
        case Op::DIFFERENT:
            break;
        case Op::SUP:
            break;
        case Op::SUP_EQ:
            break;
        case Op::INF:
            break;
        case Op::INF_EQ:
            break;
        case Op::AND:
            break;
        case Op::OR:
            break;
        }
        return eb;
    }
}
