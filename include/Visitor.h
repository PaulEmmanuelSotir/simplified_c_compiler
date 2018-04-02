#pragma once

#include "SyntaxModel/SyntaxModel.h"
#include "antlr4-runtime.h"
#include "grammar/GramCompBaseVisitor.h"
#include "utils.h"

class Visitor : public GramCompBaseVisitor {
public:
    virtual antlrcpp::Any visitProgram(GramCompParser::ProgramContext* ctx) override;
    virtual antlrcpp::Any visitFunctioncall(GramCompParser::FunctioncallContext* ctx) override;
    virtual antlrcpp::Any visitFunction(GramCompParser::FunctionContext* ctx) override;
    virtual antlrcpp::Any visitArgs(GramCompParser::ArgsContext* ctx) override;
    virtual antlrcpp::Any visitDeclare(GramCompParser::DeclareContext* context) override;
    virtual antlrcpp::Any visitDefine(GramCompParser::DefineContext* context) override;
    virtual antlrcpp::Any visitReturn(GramCompParser::ReturnContext* context) override;
    virtual antlrcpp::Any visitBreak(GramCompParser::BreakContext* ctx) override;
    virtual antlrcpp::Any visitContinue(GramCompParser::ContinueContext* ctx) override;
    virtual antlrcpp::Any visitInteger(GramCompParser::IntegerContext* ctx) override;
    virtual antlrcpp::Any visitChar_literal(GramCompParser::Char_literalContext* ctx) override;
    virtual antlrcpp::Any visitString_literal(GramCompParser::String_literalContext* ctx) override;
    virtual antlrcpp::Any visitVariable_usage(GramCompParser::Variable_usageContext* ctx) override;
    virtual antlrcpp::Any visitIf(GramCompParser::IfContext* ctx) override;
    virtual antlrcpp::Any visitWhile(GramCompParser::WhileContext* ctx) override;
    virtual antlrcpp::Any visitElse(GramCompParser::ElseContext* ctx) override;
    virtual antlrcpp::Any visitDeftable(GramCompParser::DeftableContext* ctx) override;
    virtual antlrcpp::Any visitDecltable(GramCompParser::DecltableContext* ctx) override;
    virtual antlrcpp::Any visitArray_expr(GramCompParser::Array_exprContext* ctx) override;
    virtual antlrcpp::Any visitAtomic_type(GramCompParser::Atomic_typeContext* ctx) override;
    virtual antlrcpp::Any visitType(GramCompParser::TypeContext* ctx) override;
    virtual antlrcpp::Any visitExpression_instr(GramCompParser::Expression_instrContext* ctx) override;
    virtual antlrcpp::Any visitParenthesis(GramCompParser::ParenthesisContext* ctx) override;
    virtual antlrcpp::Any visitFor(GramCompParser::ForContext* ctx) override;
    virtual antlrcpp::Any visitDef_or_expr(GramCompParser::Def_or_exprContext* ctx) override;

    // Binary ops
    virtual antlrcpp::Any visitInfequal(GramCompParser::InfequalContext* ctx) override;
    virtual antlrcpp::Any visitDifferent(GramCompParser::DifferentContext* ctx) override;
    virtual antlrcpp::Any visitPlus(GramCompParser::PlusContext* ctx) override;
    virtual antlrcpp::Any visitMult(GramCompParser::MultContext* ctx) override;
    virtual antlrcpp::Any visitMinus(GramCompParser::MinusContext* ctx) override;
    virtual antlrcpp::Any visitInf(GramCompParser::InfContext* ctx) override;
    virtual antlrcpp::Any visitDiv(GramCompParser::DivContext* ctx) override;
    virtual antlrcpp::Any visitEqual(GramCompParser::EqualContext* ctx) override;
    virtual antlrcpp::Any visitSup(GramCompParser::SupContext* ctx) override;
    virtual antlrcpp::Any visitSupequal(GramCompParser::SupequalContext* context) override;
    virtual antlrcpp::Any visitModulo(GramCompParser::ModuloContext* ctx) override;

    // Unary ops
    virtual antlrcpp::Any visitNot(GramCompParser::NotContext* ctx) override;
    virtual antlrcpp::Any visitUnary_minus(GramCompParser::Unary_minusContext* ctx) override;

    // Unaray affectations
    virtual antlrcpp::Any visitPost_inc(GramCompParser::Post_incContext* ctx) override;
    virtual antlrcpp::Any visitPre_dec(GramCompParser::Pre_decContext* ctx) override;
    virtual antlrcpp::Any visitPost_dec(GramCompParser::Post_decContext* ctx) override;
    virtual antlrcpp::Any visitPre_inc(GramCompParser::Pre_incContext* ctx) override;

    // Binary affectations
    virtual antlrcpp::Any visitAffect_eq(GramCompParser::Affect_eqContext* ctx) override;
    virtual antlrcpp::Any visitPlus_equal(GramCompParser::Plus_equalContext* ctx) override;
    virtual antlrcpp::Any visitMinus_equal(GramCompParser::Minus_equalContext* ctx) override;
    virtual antlrcpp::Any visitDiv_equal(GramCompParser::Div_equalContext* ctx) override;
    virtual antlrcpp::Any visitMult_equal(GramCompParser::Mult_equalContext* ctx) override;
    virtual antlrcpp::Any visitModulo_equal(GramCompParser::Modulo_equalContext* ctx) override;

private:
    template <typename CTX>
    antlrcpp::Any visitBinaryOp(CTX* ctx, SyntaxModel::BinaryOp::Op op)
    {
        const auto& exprs = ctx->expression();
        auto left_expr = visit_single<SyntaxModel::Expression>(exprs[0]);
        auto right_expr = visit_single<SyntaxModel::Expression>(exprs[1]);
        return static_cast<SyntaxModel::Expression*>(new SyntaxModel::BinaryOp(ctx->getSourceInterval(), left_expr, right_expr, op));
    }

    template <class CTX>
    inline antlrcpp::Any visitUnaryAffectation(SyntaxModel::Affectation::Op op, CTX* ctx)
    {
        // array_indexing is nullptr if we don't affect to an array element
        auto var_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
        auto array_index = visit_single<SyntaxModel::Expression>(ctx->expression());
        return static_cast<SyntaxModel::Expression*>(new SyntaxModel::Affectation(ctx->getSourceInterval(), op, var_name, array_index));
    }

    template <class CTX>
    inline antlrcpp::Any visitBinaryAffectation(SyntaxModel::Affectation::Op op, CTX* ctx)
    {
        // array_indexing is nullptr if we don't affect to an array element
        auto var_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
        auto expressions = ctx->expression();
        auto array_index = (expressions.size() > 1) ? visit_single<SyntaxModel::Expression>(ctx->expression(0)) : nullptr;
        auto value = visit_single<SyntaxModel::Expression>(expressions.back());
        return static_cast<SyntaxModel::Expression*>(new SyntaxModel::Affectation(ctx->getSourceInterval(), op, var_name, array_index, value));
    }

    template <class T, class CTX>
    inline T* visit_single(CTX* context)
    {
        if (context != nullptr)
            return static_cast<T*>(visit(context));
        return nullptr;
    }

    template <class T, class CTX>
    inline std::list<const T*> visit_all(const std::vector<CTX*>& contexts)
    {
        std::list<const T*> syntax_nodes;
        for (auto* ctx : contexts) {
            if (ctx != nullptr) {
                auto visited = visit(ctx);
                if (visited.isNotNull())
                    syntax_nodes.push_back(static_cast<T*>(visited));
            }
        }
        return syntax_nodes;
    }

    static inline const std::list<const SyntaxModel::Definition::size_constant*> parseArraySizes(const std::vector<antlr4::tree::TerminalNode*>& integers);
    static inline std::vector<utils::TerminalInfo> make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts);
};
