#pragma once

#include "antlr4-runtime.h"
#include "grammar/GramCompBaseVisitor.h"
#include "utils.h"

class visitor : public GramCompBaseVisitor {
    virtual antlrcpp::Any visitProgram(GramCompParser::ProgramContext* ctx) override;
    virtual antlrcpp::Any visitFucntioncall(GramCompParser::FucntioncallContext* ctx) override;
    virtual antlrcpp::Any visitFunction(GramCompParser::FunctionContext* ctx) override;
    virtual antlrcpp::Any visitDeclare(GramCompParser::DeclareContext* context) override;
    virtual antlrcpp::Any visitDefine(GramCompParser::DefineContext* context) override;

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
