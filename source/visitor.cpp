#include "visitor.h"
#include "SyntaxModel/SyntaxModel.h"
#include "utils.h"

// TODO: add checks for nullptr
// TODO: replace static_cast to dynamic_cast?

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

antlrcpp::Any visitor::visitFucntioncall(GramCompParser::FucntioncallContext* ctx)
{
    auto args = visit_all<SyntaxModel::Expression>(ctx->expression());
    auto func_name = utils::TerminalInfo(ctx->IDENTIFIER());
    return new SyntaxModel::FunctionCall(args, func_name);
}

antlrcpp::Any visitor::visitFunction(GramCompParser::FunctionContext* ctx)
{
    auto id = utils::TerminalInfo(ctx->IDENTIFIER());
    auto args = static_cast<const SyntaxModel::Args*>(visit(ctx->args()));
    auto definitions = visit_all<SyntaxModel::Definition>(ctx->function_init());
    auto instructions = visit_all<SyntaxModel::Instruction>(ctx->instruction());
    auto return_type = static_cast<const SyntaxModel::Type*>(visit(ctx->type()));
    return new SyntaxModel::Function(definitions, instructions, args, id, return_type);
}
