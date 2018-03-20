#pragma once

#include "SyntaxModel/SyntaxModel.h"
#include "antlr4-runtime.h"
#include "grammar/GramCompBaseVisitor.h"
#include "utils.h"

class visitor : public GramCompBaseVisitor {
public:
    virtual antlrcpp::Any visitProgram(GramCompParser::ProgramContext* ctx) override;
    virtual antlrcpp::Any visitFucntioncall(GramCompParser::FucntioncallContext* ctx) override;
    virtual antlrcpp::Any visitFunction(GramCompParser::FunctionContext* ctx) override;
    virtual antlrcpp::Any visitDeclare(GramCompParser::DeclareContext* context) override;
    virtual antlrcpp::Any visitDefine(GramCompParser::DefineContext* context) override;
    virtual antlrcpp::Any visitReturn(GramCompParser::ReturnContext* context) override;
    virtual antlrcpp::Any visitBreak(GramCompParser::BreakContext* ctx) override;
    virtual antlrcpp::Any visitContinue(GramCompParser::ContinueContext* ctx) override;
    virtual antlrcpp::Any visitInteger(GramCompParser::IntegerContext* ctx) override;
    virtual antlrcpp::Any visitChar_literal(GramCompParser::Char_literalContext* ctx) override;
    virtual antlrcpp::Any visitString_literal(GramCompParser::String_literalContext* ctx) override;
    virtual antlrcpp::Any visitIf(GramCompParser::IfContext* ctx) override;
    virtual antlrcpp::Any visitVariable_usage(GramCompParser::Variable_usageContext* ctx) override;
    virtual antlrcpp::Any visitWhile(GramCompParser::WhileContext* ctx) override;
    virtual antlrcpp::Any visitElse(GramCompParser::ElseContext* ctx) override;
    virtual antlrcpp::Any visitDeftable(GramCompParser::DeftableContext* ctx) override;
    virtual antlrcpp::Any visitDecltable(GramCompParser::DecltableContext* ctx) override;
    virtual antlrcpp::Any visitArray_expr(GramCompParser::Array_exprContext* ctx) override;
    virtual antlrcpp::Any visitAtomic_type(GramCompParser::Atomic_typeContext* ctx) override;
    virtual antlrcpp::Any visitType(GramCompParser::TypeContext* ctx) override;

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
    inline antlrcpp::Any visitBinaryOp(auto exprs, SyntaxModel::BinaryOp::Op op);

    template <class CTX>
    inline antlrcpp::Any visitUnaryAffectation(SyntaxModel::UnaryAffectation::Op op, CTX* ctx)
    {
        // array_indexing is nullptr if we don't affect to an array element
        auto var_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
        auto array_index = visit_single<SyntaxModel::Expression>(ctx->expression());
        return new SyntaxModel::UnaryAffectation(op, var_name, array_index);
    }

    template <class CTX>
    inline antlrcpp::Any visitBinaryAffectation(SyntaxModel::BinaryAffectation::Op op, CTX* ctx)
    {
        // array_indexing is nullptr if we don't affect to an array element
        auto var_name = SyntaxModel::Identifier(ctx->IDENTIFIER());
        auto expressions = ctx->expression();
        auto array_index = (expressions.size() > 1) ? visit_single<SyntaxModel::Expression>(ctx->expression(0)) : nullptr;
        auto value = visit_single<SyntaxModel::Expression>(expressions.back());
        return new SyntaxModel::BinaryAffectation(op, var_name, value, array_index);
    }

    template <class T, class CTX>
    inline const T* visit_single(CTX* context)
    {
        if (context != nullptr)
            return static_cast<const T*>(visit(context));
        return nullptr;
    }

    template <class T, class CTX>
    inline std::vector<const T*> visit_all(const std::vector<CTX*>& contexts)
    {
        std::vector<const T*> syntax_nodes(contexts.size());
        for (auto* ctx : contexts) {
            syntax_nodes.push_back(static_cast<const T*>(visit(ctx)));
        }
        return syntax_nodes;
    }

    static inline const std::vector<const SyntaxModel::Definition::size_constant*> parseArraySizes(auto integers);
    static inline std::vector<utils::TerminalInfo> make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts);
};
