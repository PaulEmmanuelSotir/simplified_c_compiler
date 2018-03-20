#include <string>
#include <vector>

#include "SyntaxModel/SyntaxModel.h"
#include "visitor.h"

// TODO: add checks for nullptr
// TODO: replace static_cast with dynamic_cast?

antlrcpp::Any visitor::visitProgram(GramCompParser::ProgramContext* ctx)
{
    std::vector<SyntaxModel::Include> includes;
    for (auto* inc : ctx->INCLUDE()) {
        includes.push_back(SyntaxModel::Include(inc));
    }

    auto declarations = visit_all<SyntaxModel::Definition>(ctx->declaration());
    auto definitions = visit_all<SyntaxModel::Definition>(ctx->definition());
    auto functions = visit_all<SyntaxModel::Function>(ctx->function());

    return new SyntaxModel::Program(includes, functions, declarations, definitions);
}

antlrcpp::Any visitor::visitFucntioncall(GramCompParser::FucntioncallContext* ctx)
{
    auto args = visit_all<SyntaxModel::Expression>(ctx->expression());
    auto func_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
    return new SyntaxModel::FunctionCall(args, func_name);
}

antlrcpp::Any visitor::visitFunction(GramCompParser::FunctionContext* ctx)
{
    auto id = SyntaxModel::Identifier(ctx->IDENTIFIER());
    auto args = visit_single<SyntaxModel::Args>(ctx->args());
    auto definitions = visit_all<SyntaxModel::Definition>(ctx->function_init());
    auto instructions = visit_all<SyntaxModel::Instruction>(ctx->instruction());
    auto return_type = visit_single<SyntaxModel::Type>(ctx->type());
    return new SyntaxModel::Function(definitions, instructions, args, id, return_type);
}

antlrcpp::Any visitor::visitDeclare(GramCompParser::DeclareContext* ctx)
{
    auto type = visit_single<SyntaxModel::Type>(ctx->type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    return new SyntaxModel::Definition(type, names);
}

antlrcpp::Any visitor::visitDefine(GramCompParser::DefineContext* ctx)
{
    auto type = visit_single<SyntaxModel::Type>(ctx->type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto init_values = visit_all<SyntaxModel::Expression>(ctx->expression());
    return new SyntaxModel::Definition(type, names, init_values);
}

antlrcpp::Any visitor::visitReturn(GramCompParser::ReturnContext* ctx)
{
    auto returned_expr = visit_single<SyntaxModel::Expression>(ctx->expression());
    return new SyntaxModel::Return(returned_expr);
}

antlrcpp::Any visitor::visitBreak(GramCompParser::BreakContext* ctx)
{
    return new SyntaxModel::Break();
}

antlrcpp::Any visitor::visitContinue(GramCompParser::ContinueContext* ctx)
{
    return new SyntaxModel::Continue();
}

antlrcpp::Any visitor::visitInfequal(GramCompParser::InfequalContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::INF_EQ);
}

antlrcpp::Any visitor::visitDifferent(GramCompParser::DifferentContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::DIFFERENT);
}

antlrcpp::Any visitor::visitPlus(GramCompParser::PlusContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::PLUS);
}
antlrcpp::Any visitor::visitMult(GramCompParser::MultContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::MULT);
}
antlrcpp::Any visitor::visitMinus(GramCompParser::MinusContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::MINUS);
}
antlrcpp::Any visitor::visitInf(GramCompParser::InfContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::INF);
}
antlrcpp::Any visitor::visitDiv(GramCompParser::DivContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::DIV);
}
antlrcpp::Any visitor::visitEqual(GramCompParser::EqualContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::EQUAL);
}
antlrcpp::Any visitor::visitSup(GramCompParser::SupContext* ctx)
{
    return visitBinaryOp(ctx->expression(), SyntaxModel::BinaryOp::Op::SUP);
}

antlrcpp::Any visitor::visitNot(GramCompParser::NotContext* ctx)
{
    auto expr = visit_single<SyntaxModel::Expression>(ctx->expression());
    return SyntaxModel::UnaryOp(expr, SyntaxModel::UnaryOp::Op::NOT);
}

antlrcpp::Any visitor::visitUnary_minus(GramCompParser::Unary_minusContext* ctx)
{
    auto expr = visit_single<SyntaxModel::Expression>(ctx->expression());
    return SyntaxModel::UnaryOp(expr, SyntaxModel::UnaryOp::Op::MINUS);
}

antlrcpp::Any visitor::visitInteger(GramCompParser::IntegerContext* ctx)
{
    auto terminal = utils::TerminalInfo(ctx->INTEGER());
    // Parse int64_t from token (we assume here this is int64_t, if int32_t is needed an implicit cast will be performed unless optimized away)
    int64_t value = std::stol(terminal.text);
    return new SyntaxModel::Constant<SyntaxModel::Type::PrimitiveType::INT64_T>(value);
}

antlrcpp::Any visitor::visitChar_literal(GramCompParser::Char_literalContext* ctx)
{
    // Take text from literal token and remove quotes and eventual escaping backslash
    auto text = utils::TerminalInfo(ctx->QUOTED_CHAR_LITERAL()).text;
    char char_literal = (text[1] == '\\') ? text[2] : text[1];
    return new SyntaxModel::Constant<SyntaxModel::Type::PrimitiveType::CHAR>(char_literal);
}

/*antlrcpp::Any visitString_literal(GramCompParser::String_literalContext* ctx)
{
    auto text = utils::TerminalInfo(ctx->STRING_LITERAL()).text;
    // TODO: remove escaping backslashs (e.g. regex "[^\\]?\\(.)|([^\\])" )
    auto string_literal = substr(1, terminal.text.length() - 2);
    // TODO: StringLiteral class?
    return new SyntaxModel::;
}*/

antlrcpp::Any visitor::visitIf(GramCompParser::IfContext* ctx)
{
    auto condition = visit_single<SyntaxModel::Expression>(ctx->expression());
    auto instructions = visit_all<SyntaxModel::Instruction>(ctx->instruction());
    auto else_clause = visit_single<SyntaxModel::Else>(ctx->else_structure());
    return new SyntaxModel::If(condition, instructions, else_clause);
}

antlrcpp::Any visitor::visitVariable_usage(GramCompParser::Variable_usageContext* ctx)
{
    auto var_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
    return new SyntaxModel::VariableUsage(var_name);
}

antlrcpp::Any visitor::visitWhile(GramCompParser::WhileContext* ctx)
{
    auto condition = visit_single<SyntaxModel::Expression>(ctx->expression());
    auto instructions = visit_all<SyntaxModel::Instruction>(ctx->instruction());
    return new SyntaxModel::While(condition, instructions);
}

antlrcpp::Any visitor::visitElse(GramCompParser::ElseContext* ctx)
{
    auto instructions = visit_all<SyntaxModel::Instruction>(ctx->instruction());
    return new SyntaxModel::Else(instructions);
}

antlrcpp::Any visitor::visitPre_inc(GramCompParser::Pre_incContext* ctx) { return visitUnaryAffectation(SyntaxModel::UnaryAffectation::Op::PRE_INC, ctx); }
antlrcpp::Any visitor::visitPre_dec(GramCompParser::Pre_decContext* ctx) { return visitUnaryAffectation(SyntaxModel::UnaryAffectation::Op::PRE_DEC, ctx); }
antlrcpp::Any visitor::visitPost_inc(GramCompParser::Post_incContext* ctx) { return visitUnaryAffectation(SyntaxModel::UnaryAffectation::Op::POST_INC, ctx); }
antlrcpp::Any visitor::visitPost_dec(GramCompParser::Post_decContext* ctx) { return visitUnaryAffectation(SyntaxModel::UnaryAffectation::Op::POST_DEC, ctx); }
antlrcpp::Any visitor::visitAffect_eq(GramCompParser::Affect_eqContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::EQ, ctx); }
antlrcpp::Any visitor::visitPlus_equal(GramCompParser::Plus_equalContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::PLUS_EQ, ctx); }
antlrcpp::Any visitor::visitMinus_equal(GramCompParser::Minus_equalContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::MIN_EQ, ctx); }
antlrcpp::Any visitor::visitDiv_equal(GramCompParser::Div_equalContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::DIV_EQ, ctx); }
antlrcpp::Any visitor::visitMult_equal(GramCompParser::Mult_equalContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::MULT_EQ, ctx); }
antlrcpp::Any visitor::visitModulo_equal(GramCompParser::Modulo_equalContext* ctx) { return visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op::MODULO_EQ, ctx); }

/*
antlrcpp::Any visitor::visitDefine(GramCompParser::DefineContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitDeftable(GramCompParser::DeftableContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitDeclare(GramCompParser::DeclareContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitDecltable(GramCompParser::DecltableContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitArray_expr(GramCompParser::Array_exprContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitConst_expr(GramCompParser::Const_exprContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitAtomic_type(GramCompParser::Atomic_typeContext* ctx) { return new SyntaxModel::; }
antlrcpp::Any visitor::visitType(GramCompParser::TypeContext* ctx) { return new SyntaxModel::; }
*/

antlrcpp::Any visitor::visitBinaryOp(auto exprs, SyntaxModel::BinaryOp::Op op)
{
    auto left_expr = visit_single<SyntaxModel::Expression>(exprs[0]);
    auto right_expr = visit_single<SyntaxModel::Expression>(exprs[1]);
    return new SyntaxModel::BinaryOp(left_expr, right_expr, op);
}

std::vector<utils::TerminalInfo> visitor::make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts)
{
    std::vector<utils::TerminalInfo> syntax_nodes;
    for (auto* ctx : contexts) {
        syntax_nodes.emplace_back(ctx);
    }
    return syntax_nodes;
}
