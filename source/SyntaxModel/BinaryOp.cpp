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

    IR::ExecutionBlock* BinaryOp::generateIR(IR::ControlFlowGraph& cfg, IR::ExecutionBlock* eb, IR::symbol_t result_register) const
    {
        return eb;
    }
}
