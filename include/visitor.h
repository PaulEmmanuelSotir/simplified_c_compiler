#pragma once

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

private:
    antlrcpp::Any visitBinaryOp(auto exprs, SyntaxModel::BinaryOp::Op op);

    template <class T, class CTX>
    inline const T* visit_single(CTX* context)
    {
        return static_cast<const T*>(visit(context));
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

    static inline std::vector<utils::TerminalInfo> make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts);
};
