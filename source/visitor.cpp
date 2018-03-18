#include "visitor.h"
#include "SyntaxModel/SyntaxModel.h"
#include "utils.h"

antlrcpp::Any visitor::visitProgram(GramCompParser::ProgramContext* ctx)
{
    std::vector<utils::TerminalInfo> includes;
    for (auto* inc : ctx->INCLUDE()) {
        includes.push_back(utils::TerminalInfo(inc));
    }

    auto declarations = visit_all<const SyntaxModel::Declaration, GramCompParser::DeclarationContext>(ctx->declaration());
    auto definitions = visit_all<const SyntaxModel::Definition, GramCompParser::DefinitionContext>(ctx->definition());
    auto functions = visit_all<const SyntaxModel::Function, GramCompParser::FunctionContext>(ctx->function());

    return new SyntaxModel::Program(includes, functions, declarations, definitions);
}

//return (Expression*)new ExpressionBinairePlus(
//    (Expression*)visit(ctx->expr(0)),
//    (Expression*)visit(ctx->expr(1)));
