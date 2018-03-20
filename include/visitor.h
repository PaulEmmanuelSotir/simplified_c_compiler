#pragma once

#include "grammar/GramCompBaseVisitor.h"

class visitor : public GramCompBaseVisitor {
    virtual antlrcpp::Any visitProgram(GramCompParser::ProgramContext* ctx) override;
    virtual antlrcpp::Any visitFucntioncall(GramCompParser::FucntioncallContext* ctx) override;
    virtual antlrcpp::Any visitFunction(GramCompParser::FunctionContext* ctx) override;

    template <class T, class CTX>
    std::vector<const T*> visit_all(const std::vector<CTX*>& contexts)
    {
        std::vector<const T*> syntax_nodes(contexts.size());
        for (auto* ctx : contexts) {
            syntax_nodes.push_back(static_cast<const T*>(visit(ctx)));
        }
        return syntax_nodes;
    }
};
