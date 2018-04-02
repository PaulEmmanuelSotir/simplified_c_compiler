#include <cstdint>
#include <string>
#include <vector>

#include "SyntaxModel/SyntaxModel.h"
#include "Visitor.h"

// TODO: add checks for nullptr
// TODO: replace static_cast with dynamic_cast?

namespace SM = SyntaxModel;
using PT = SM::PrimitiveType;

antlrcpp::Any Visitor::visitProgram(GramCompParser::ProgramContext* ctx)
{
    std::vector<SM::Include> includes;
    for (auto* inc : ctx->INCLUDE())
        includes.push_back(SM::Include(inc));
    auto definitions = visit_all<SM::Definition>(ctx->decl_or_def());
    auto functions = visit_all<SM::Function>(ctx->function());
    functions.push_back(new SM::Putchar()); // We add putchar function which is defined by default
    return new SM::Program(ctx->getSourceInterval(), includes, functions, definitions);
}

antlrcpp::Any Visitor::visitFunctioncall(GramCompParser::FunctioncallContext* ctx)
{
    auto args = visit_all<SM::Expression>(ctx->expression());
    auto func_name = SM::Identifier(ctx->IDENTIFIER());
    return static_cast<SM::Expression*>(new SM::FunctionCall(ctx->getSourceInterval(), args, func_name));
}

antlrcpp::Any Visitor::visitFunction(GramCompParser::FunctionContext* ctx)
{
    auto id = SM::Identifier(ctx->IDENTIFIER());
    auto args = visit_single<SM::Args>(ctx->args());
    auto definitions = visit_all<SM::Definition>(ctx->decl_or_def());
    auto return_type = visit_single<SM::Type>(ctx->type());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return new SM::Function(ctx->getSourceInterval(), definitions, instructions, args, id, return_type);
}

antlrcpp::Any Visitor::visitArgs(GramCompParser::ArgsContext* ctx)
{
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto types = visit_all<SM::Type>(ctx->type());
    return new SM::Args(ctx->getSourceInterval(), types, names);
}

antlrcpp::Any Visitor::visitDeclare(GramCompParser::DeclareContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    return new SM::Definition(ctx->getSourceInterval(), type, names);
}

const std::list<const SM::Definition::size_constant*> Visitor::parseArraySizes(const std::vector<antlr4::tree::TerminalNode*>& integers)
{
    // Parse array sizes from their tokens to build Constant<INT32_T> instances
    std::list<const SM::Definition::size_constant*> sizes;
    for (auto* terminal : integers) {
        // Find source interval from terminal node and make a Constant<INT32_T> for each specified size
        auto interval = antlr4::misc::Interval(terminal->getSymbol()->getStartIndex(), terminal->getSymbol()->getStopIndex()); // TODO: make sure this is the right interval
        sizes.push_back(SM::make_constant_from_terminal<PT::INT32_T>(interval, terminal));
    }
    return sizes;
}

antlrcpp::Any Visitor::visitDecltable(GramCompParser::DecltableContext* ctx)
{
    auto* type = visit_single<SM::Type>(ctx->atomic_type());
    auto* array_type = new SM::Type(type->source_interval, type->type, true);
    delete type;
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto sizes = parseArraySizes(ctx->INTEGER());
    return new SM::Definition(ctx->getSourceInterval(), array_type, names, sizes);
}

antlrcpp::Any Visitor::visitDeftable(GramCompParser::DeftableContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto array_type = new SM::Type(type->source_interval, type->type, true);
    delete type;
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto sizes = parseArraySizes(ctx->INTEGER());
    auto init_arrays = visit_all<SM::Expression>(ctx->expression());
    return new SM::Definition(ctx->getSourceInterval(), array_type, names, sizes, init_arrays);
}

antlrcpp::Any Visitor::visitDefine(GramCompParser::DefineContext* ctx)
{
    auto type = visit_single<SM::Type>(ctx->atomic_type());
    auto names = make_all_terminals(ctx->IDENTIFIER());
    auto init_values = visit_all<SM::Expression>(ctx->expression());
    return new SM::Definition(ctx->getSourceInterval(), type, names, init_values);
}

antlrcpp::Any Visitor::visitReturn(GramCompParser::ReturnContext* ctx)
{
    auto returned_expr = visit_single<SM::Expression>(ctx->expression());
    return static_cast<SM::Instruction*>(new SM::Return(ctx->getSourceInterval(), returned_expr));
}

antlrcpp::Any Visitor::visitBreak(GramCompParser::BreakContext* ctx) { return static_cast<SM::Instruction*>(new SM::Break(ctx->getSourceInterval())); }
antlrcpp::Any Visitor::visitContinue(GramCompParser::ContinueContext* ctx) { return static_cast<SM::Instruction*>(new SM::Continue(ctx->getSourceInterval())); }

antlrcpp::Any Visitor::visitInfequal(GramCompParser::InfequalContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::INF_EQ); }
antlrcpp::Any Visitor::visitDifferent(GramCompParser::DifferentContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::DIFFERENT); }
antlrcpp::Any Visitor::visitPlus(GramCompParser::PlusContext* ctx)
{
    return visitBinaryOp(ctx, SM::BinaryOp::Op::PLUS);
}
antlrcpp::Any Visitor::visitMult(GramCompParser::MultContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::MULT); }
antlrcpp::Any Visitor::visitMinus(GramCompParser::MinusContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::MINUS); }
antlrcpp::Any Visitor::visitInf(GramCompParser::InfContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::INF); }
antlrcpp::Any Visitor::visitDiv(GramCompParser::DivContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::DIV); }
antlrcpp::Any Visitor::visitEqual(GramCompParser::EqualContext* ctx)
{
    return visitBinaryOp(ctx, SM::BinaryOp::Op::EQUAL);
}
antlrcpp::Any Visitor::visitSup(GramCompParser::SupContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::SUP); }
antlrcpp::Any Visitor::visitSupequal(GramCompParser::SupequalContext* ctx) { return visitBinaryOp(ctx, SM::BinaryOp::Op::SUP_EQ); }

antlrcpp::Any Visitor::visitNot(GramCompParser::NotContext* ctx)
{
    auto expr = visit_single<SM::Expression>(ctx->expression());
    return static_cast<SM::Expression*>(new SM::UnaryOp(ctx->getSourceInterval(), expr, SM::UnaryOp::Op::NOT));
}

antlrcpp::Any Visitor::visitUnary_minus(GramCompParser::Unary_minusContext* ctx)
{
    auto expr = visit_single<SM::Expression>(ctx->expression());
    return static_cast<SM::Expression*>(new SM::UnaryOp(ctx->getSourceInterval(), expr, SM::UnaryOp::Op::MINUS));
}

// Parse int64_t from token (we assume here this is int64_t, if int32_t is needed an implicit cast will be performed unless optimized away)
antlrcpp::Any Visitor::visitInteger(GramCompParser::IntegerContext* ctx)
{
    return static_cast<SM::Expression*>(SM::make_constant_from_terminal<PT::INT64_T>(ctx->getSourceInterval(), ctx->INTEGER()));
}
antlrcpp::Any Visitor::visitChar_literal(GramCompParser::Char_literalContext* ctx)
{
    return static_cast<SM::Expression*>(SM::make_constant_from_terminal<PT::CHAR>(ctx->getSourceInterval(), ctx->QUOTED_CHAR_LITERAL()));
}
antlrcpp::Any Visitor::visitString_literal(GramCompParser::String_literalContext* ctx) { return static_cast<SM::Expression*>(SM::make_array_const_from_string(ctx->getSourceInterval(), ctx->STRING_LITERAL())); }

antlrcpp::Any Visitor::visitVariable_usage(GramCompParser::Variable_usageContext* ctx)
{
    auto var_name = SM::Identifier(ctx->IDENTIFIER());
    return static_cast<SM::Expression*>(new SM::VariableUsage(ctx->getSourceInterval(), var_name));
}

antlrcpp::Any Visitor::visitIf(GramCompParser::IfContext* ctx)
{
    auto condition = visit_single<SM::Expression>(ctx->expression());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    auto else_clause = visit_single<SM::Else>(ctx->else_structure());
    return static_cast<SM::Instruction*>(new SM::If(ctx->getSourceInterval(), condition, instructions, else_clause));
}

antlrcpp::Any Visitor::visitWhile(GramCompParser::WhileContext* ctx)
{
    auto condition = visit_single<SM::Expression>(ctx->expression());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return static_cast<SM::Instruction*>(new SM::While(ctx->getSourceInterval(), condition, instructions));
}

antlrcpp::Any Visitor::visitElse(GramCompParser::ElseContext* ctx)
{
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return new SM::Else(ctx->getSourceInterval(), instructions);
}

antlrcpp::Any Visitor::visitArray_expr(GramCompParser::Array_exprContext* ctx)
{
    if (ctx->INTEGER().size() > 0) {
        return static_cast<SM::Expression*>(SM::make_array_const<PT::INT64_T>(ctx->getSourceInterval(), ctx->INTEGER()));
    } else if (ctx->QUOTED_CHAR_LITERAL().size() > 0) {
        return static_cast<SM::Expression*>(SM::make_array_const<PT::CHAR>(ctx->getSourceInterval(), ctx->QUOTED_CHAR_LITERAL()));
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitAtomic_type(GramCompParser::Atomic_typeContext* ctx)
{
    if (ctx->CHAR() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::CHAR, false);
    } else if (ctx->INT32_T() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::INT32_T, false);
    } else if (ctx->INT64_T() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::INT64_T, false);
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitType(GramCompParser::TypeContext* ctx)
{
    if (ctx->CHAR() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::CHAR, ctx->ARRAY_BRACKETS() != nullptr);
    } else if (ctx->INT32_T() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::INT32_T, ctx->ARRAY_BRACKETS() != nullptr);
    } else if (ctx->INT64_T() != nullptr) {
        return new SM::Type(ctx->getSourceInterval(), PT::INT64_T, ctx->ARRAY_BRACKETS() != nullptr);
    }
    return nullptr;
}

antlrcpp::Any Visitor::visitExpression_instr(GramCompParser::Expression_instrContext* ctx)
{
    // Don't touch and don't ask why!
    return static_cast<SM::Instruction*>(visit_single<SM::Expression>(ctx->expression()));
}

antlrcpp::Any Visitor::visitParenthesis(GramCompParser::ParenthesisContext* ctx)
{
    return visit_single<SM::Expression>(ctx->expression());
}

antlrcpp::Any Visitor::visitFor(GramCompParser::ForContext* ctx)
{
    auto init = visit_single<SM::SyntaxNodeBase>(ctx->def_or_expr(0));
    auto condition = visit_single<SM::SyntaxNodeBase>(ctx->def_or_expr(1));
    if (condition->is<SM::Definition>())
        throw new CompilerException("For loop doesn't support definitions in their condition statements for now");
    auto condition_expr = dynamic_cast<const SM::Expression*>(condition);
    auto iteration_expression = visit_single<SM::Expression>(ctx->expression());
    auto instructions = visit_all<SM::Instruction>(ctx->instruction());
    return static_cast<SM::Instruction*>(new SM::For(ctx->getSourceInterval(), init, condition_expr, iteration_expression, instructions));
}

antlrcpp::Any Visitor::visitDef_or_expr(GramCompParser::Def_or_exprContext* ctx)
{
    if (ctx->definition() != nullptr)
        return static_cast<SM::SyntaxNodeBase*>(visit_single<SM::Definition>(ctx->definition()));
    else
        return static_cast<SM::SyntaxNodeBase*>(visit_single<SM::Expression>(ctx->expression()));
}

antlrcpp::Any Visitor::visitPre_inc(GramCompParser::Pre_incContext* ctx) { return visitUnaryAffectation(SM::Affectation::Op::PRE_INC, ctx); }
antlrcpp::Any Visitor::visitPre_dec(GramCompParser::Pre_decContext* ctx) { return visitUnaryAffectation(SM::Affectation::Op::PRE_DEC, ctx); }
antlrcpp::Any Visitor::visitPost_inc(GramCompParser::Post_incContext* ctx) { return visitUnaryAffectation(SM::Affectation::Op::POST_INC, ctx); }
antlrcpp::Any Visitor::visitPost_dec(GramCompParser::Post_decContext* ctx) { return visitUnaryAffectation(SM::Affectation::Op::POST_DEC, ctx); }
antlrcpp::Any Visitor::visitAffect_eq(GramCompParser::Affect_eqContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::EQ, ctx); }
antlrcpp::Any Visitor::visitPlus_equal(GramCompParser::Plus_equalContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::PLUS_EQ, ctx); }
antlrcpp::Any Visitor::visitMinus_equal(GramCompParser::Minus_equalContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::MIN_EQ, ctx); }
antlrcpp::Any Visitor::visitDiv_equal(GramCompParser::Div_equalContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::DIV_EQ, ctx); }
antlrcpp::Any Visitor::visitMult_equal(GramCompParser::Mult_equalContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::MULT_EQ, ctx); }
antlrcpp::Any Visitor::visitModulo_equal(GramCompParser::Modulo_equalContext* ctx) { return visitBinaryAffectation(SM::Affectation::Op::MODULO_EQ, ctx); }

std::vector<utils::TerminalInfo> Visitor::make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts)
{
    std::vector<utils::TerminalInfo> syntax_nodes;
    syntax_nodes.reserve(contexts.size());
    for (auto* ctx : contexts)
        syntax_nodes.emplace_back(ctx);
    return syntax_nodes;
}
