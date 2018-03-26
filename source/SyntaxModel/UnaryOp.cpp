#include "SyntaxModel/UnaryOp.h"

namespace SyntaxModel {

    UnaryOp::UnaryOp(const antlr4::misc::Interval& source_interval, const Expression* expression, const Op op)
        : Expression(source_interval, { expression })
        , expression(expression)
        , op(op)
    {
    }

    std::ostream& UnaryOp::toString(std::ostream& os) const
    {
        os << "op" << static_cast<std::underlying_type<UnaryOp::Op>::type>(op) << *expression << std::endl;
        return os;
    }

    Type UnaryOp::getExprType(const StaticAnalysis::StaticAnalyser* analyser) const
    {
        // Returns type according to sub expression, implicit cast rules and operator type rules
        auto expr_type = expression->getExprType(analyser);

        if (expr_type.isArray)
            // TODO: make an alias for pointer type depending on target architecture
            return Type(source_interval, Type::PrimitiveType::INT64_T, false); // BinaryOps interprets arrays as pointers (INT64_T);

        if (op == Op::MINUS) {
            if (expr_type.type == Type::PrimitiveType::CHAR)
                return Type(source_interval, Type::PrimitiveType::INT32_T, false); // Implicit cast to INT32_T
            return expr_type;
        } else // if (op == Op::NOT)
            return Type(source_interval, Type::PrimitiveType::INT32_T, false); // Implicit cast to boolean (INT32_T)
    }
}
