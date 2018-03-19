#include "visitor.h"
#include "SyntaxModel/SyntaxModel.h"
#include "utils.h"

antlrcpp::Any visitor::visitProgram(GramCompParser::ProgramContext* ctx)
{
    std::vector<utils::TerminalInfo> includes;
    for (auto* inc : ctx->INCLUDE()) {
        includes.push_back(utils::TerminalInfo(inc));
    }

    auto declarations = visit_all<SyntaxModel::Definition>(ctx->declaration());
    auto definitions = visit_all<SyntaxModel::Definition>(ctx->definition());
    auto functions = visit_all<SyntaxModel::Function>(ctx->function());

    return new SyntaxModel::Program(includes, functions, declarations, definitions);
}

