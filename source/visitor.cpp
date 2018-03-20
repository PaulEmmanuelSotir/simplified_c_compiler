#include <cstdint>
#include <string>
#include <vector>

#include "SyntaxModel/SyntaxModel.h"
#include "visitor.h"

// TODO: add checks for nullptr
// TODO: replace static_cast with dynamic_cast?

namespace SM = SyntaxModel;
using PT = SyntaxModel::Type::PrimitiveType;

antlrcpp::Any visitor::visitProgram(GramCompParser::ProgramContext* ctx)
{
    std::vector<SM::Include> includes;
    for (auto* inc : ctx->INCLUDE()) {
        includes.push_back(SM::Include(inc));
    }

    auto declarations = visit_all<SM::Definition>(ctx->declaration());
    auto definitions = visit_all<SM::Definition>(ctx->definition());
    auto functions = visit_all<SM::Function>(ctx->function());

    return new SM::Program(includes, functions, declarations, definitions);
}

antlrcpp::Any visitor::visitFucntioncall(GramCompParser::FucntioncallContext* ctx)
{
    auto args = visit_all<SM::Expression>(ctx->expression());
    auto func_name = SM::Identifier(ctx->IDENTIFIER());
    return new SM::FunctionCall(args, func_name);
}

antlrcpp::Any visitor::visitFunction(GramCompParser::FunctionContext* ctx)
{
    auto id = SM::Identifier(ctx->IDENTIFIER());
    auto args = visit_single<SM::Args>(ctx->args());
    auto definitions = visit_all<SM::Definition>(ctx->function_init());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    auto return_type = visit_single<SM::Type>(ctx->type());
    return new SM::Function(definitions, instructions, args, id, return_type);
}

antlrcpp::Any visitor::visitDeclare(GramCompParser::DeclareContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    return new SM::Definition(type, names);
}

const std::vector<const SM::Definition::size_constant*> visitor::parseArraySizes(auto integers)
{
    // Parse array sizes from their tokens to build Constant<INT32_T> instances
    std::vector<const SM::Definition::size_constant*> sizes(integers.size());
    for (auto* ctx : integers) {
        sizes.push_back(SM::make_constant_from_terminal<PT::INT32_T>(ctx));
    }
    return sizes;
}

antlrcpp::Any visitor::visitDecltable(GramCompParser::DecltableContext* ctx)
{
    auto* type = visit_single<SM::Type>(ctx->atomic_type());
    auto* array_type = new SM::Type(type->type, true);
    delete type;
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto sizes = parseArraySizes(ctx->INTEGER());
    return new SM::Definition(array_type, names, sizes);
}

antlrcpp::Any visitor::visitDeftable(GramCompParser::DeftableContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto array_type = new SM::Type(type->type, true);
    delete type;
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto sizes = parseArraySizes(ctx->INTEGER());
    auto init_arrays = visit_all<SM::Expression>(ctx->expression());
    return new SM::Definition(array_type, names, sizes, init_arrays);
}

antlrcpp::Any visitor::visitDefine(GramCompParser::DefineContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto init_values = visit_all<SM::Expression>(ctx->expression());
    return new SM::Definition(type, names, init_values);
}

antlrcpp::Any visitor::visitReturn(GramCompParser::ReturnContext* ctx)
{
    auto returned_expr = visit_single<SM::Expression>(ctx->expression());
    return new SM::Return(returned_expr);
}

antlrcpp::Any visitor::visitBreak(GramCompParser::BreakContext* ctx)
{
    return new SM::Break();
}

antlrcpp::Any visitor::visitContinue(GramCompParser::ContinueContext* ctx)
{
    return new SM::Continue();
}

antlrcpp::Any visitor::visitInfequal(GramCompParser::InfequalContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::INF_EQ);
}

antlrcpp::Any visitor::visitDifferent(GramCompParser::DifferentContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::DIFFERENT);
}

antlrcpp::Any visitor::visitPlus(GramCompParser::PlusContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::PLUS);
}
antlrcpp::Any visitor::visitMult(GramCompParser::MultContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::MULT);
}
antlrcpp::Any visitor::visitMinus(GramCompParser::MinusContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::MINUS);
}
antlrcpp::Any visitor::visitInf(GramCompParser::InfContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::INF);
}
antlrcpp::Any visitor::visitDiv(GramCompParser::DivContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::DIV);
}
antlrcpp::Any visitor::visitEqual(GramCompParser::EqualContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::EQUAL);
}
antlrcpp::Any visitor::visitSup(GramCompParser::SupContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SM::BinaryOp::Op::SUP);
}

antlrcpp::Any visitor::visitNot(GramCompParser::NotContext* ctx)
{
    auto expr = visit_single<SM::Expression>(ctx->expression());
    return SM::UnaryOp(expr, SM::UnaryOp::Op::NOT);
}

antlrcpp::Any visitor::visitUnary_minus(GramCompParser::Unary_minusContext* ctx)
{
    auto expr = visit_single<SM::Expression>(ctx->expression());
    return SM::UnaryOp(expr, SM::UnaryOp::Op::MINUS);
}

antlrcpp::Any visitor::visitInteger(GramCompParser::IntegerContext* ctx)
{
    // Parse int64_t from token (we assume here this is int64_t, if int32_t is needed an implicit cast will be performed unless optimized away)
    return SM::make_constant_from_terminal<PT::INT64_T>(ctx->INTEGER());
}

antlrcpp::Any visitor::visitChar_literal(GramCompParser::Char_literalContext* ctx)
{
    return SM::make_constant_from_terminal<PT::CHAR>(ctx->QUOTED_CHAR_LITERAL());
}

antlrcpp::Any visitor::visitString_literal(GramCompParser::String_literalContext* ctx)
{
    return SM::make_array_const_from_string(ctx->STRING_LITERAL());
}

antlrcpp::Any visitor::visitIf(GramCompParser::IfContext* ctx)
{
    auto condition = visit_single<SM::Expression>(ctx->expression());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    auto else_clause = visit_single<SM::Else>(ctx->else_structure());
    return new SM::If(condition, instructions, else_clause);
}

antlrcpp::Any visitor::visitVariable_usage(GramCompParser::Variable_usageContext* ctx)
{
    auto var_name = SM::Identifier(ctx->IDENTIFIER());
    return new SM::VariableUsage(var_name);
}

antlrcpp::Any visitor::visitWhile(GramCompParser::WhileContext* ctx)
{
    auto condition = visit_single<SM::Expression>(ctx->expression());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return new SM::While(condition, instructions);
}

antlrcpp::Any visitor::visitElse(GramCompParser::ElseContext* ctx)
{
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return new SM::Else(instructions);
}

antlrcpp::Any visitor::visitArray_expr(GramCompParser::Array_exprContext* ctx)
{
    if (ctx->INTEGER().size() > 0) {
        return SM::make_array_const<PT::INT64_T>(ctx->INTEGER());
    } else if (ctx->QUOTED_CHAR_LITERAL().size() > 0) {
        return SM::make_array_const<PT::CHAR>(ctx->QUOTED_CHAR_LITERAL());
    } // TODO: error (else)!
}

antlrcpp::Any visitor::visitAtomic_type(GramCompParser::Atomic_typeContext* ctx)
{
    if (ctx->CHAR() != nullptr) {
        return SM::Type(PT::CHAR, false);
    } else if (ctx->INT32_T() != nullptr) {
        return SM::Type(PT::INT32_T, false);
    } else {
        return SM::Type(PT::INT64_T, false);
    }
}

antlrcpp::Any visitor::visitType(GramCompParser::TypeContext* ctx)
{
    auto is_array = [ctx](auto t) -> bool { return ctx->stop->getTokenIndex() != t; };
    if (ctx->CHAR() != nullptr) {
        return SM::Type(PT::CHAR, is_array(GramCompParser::CHAR));
    } else if (ctx->INT32_T() != nullptr) {
        return SM::Type(PT::INT32_T, is_array(GramCompParser::INT32_T));
    } else {
        return SM::Type(PT::INT64_T, is_array(GramCompParser::INT64_T));
    }
}

antlrcpp::Any visitor::visitPre_inc(GramCompParser::Pre_incContext* ctx) { return visitUnaryAffectation(SM::UnaryAffectation::Op::PRE_INC, ctx); }
antlrcpp::Any visitor::visitPre_dec(GramCompParser::Pre_decContext* ctx) { return visitUnaryAffectation(SM::UnaryAffectation::Op::PRE_DEC, ctx); }
antlrcpp::Any visitor::visitPost_inc(GramCompParser::Post_incContext* ctx) { return visitUnaryAffectation(SM::UnaryAffectation::Op::POST_INC, ctx); }
antlrcpp::Any visitor::visitPost_dec(GramCompParser::Post_decContext* ctx) { return visitUnaryAffectation(SM::UnaryAffectation::Op::POST_DEC, ctx); }
antlrcpp::Any visitor::visitAffect_eq(GramCompParser::Affect_eqContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::EQ, ctx); }
antlrcpp::Any visitor::visitPlus_equal(GramCompParser::Plus_equalContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::PLUS_EQ, ctx); }
antlrcpp::Any visitor::visitMinus_equal(GramCompParser::Minus_equalContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::MIN_EQ, ctx); }
antlrcpp::Any visitor::visitDiv_equal(GramCompParser::Div_equalContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::DIV_EQ, ctx); }
antlrcpp::Any visitor::visitMult_equal(GramCompParser::Mult_equalContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::MULT_EQ, ctx); }
antlrcpp::Any visitor::visitModulo_equal(GramCompParser::Modulo_equalContext* ctx) { return visitBinaryAffectation(SM::BinaryAffectation::Op::MODULO_EQ, ctx); }

antlrcpp::Any visitor::visitBinaryOp(auto exprs, SM::BinaryOp::Op op)
{
    auto left_expr = visit_single<SM::Expression>(exprs[0]);
    auto right_expr = visit_single<SM::Expression>(exprs[1]);
    return new SM::BinaryOp(left_expr, right_expr, op);
}

std::vector<utils::TerminalInfo> visitor::make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts)
{
    std::vector<utils::TerminalInfo> syntax_nodes;
    for (auto* ctx : contexts) {
        syntax_nodes.emplace_back(ctx);
    }
    return syntax_nodes;
}
