#include "visitor.h"
#include "SyntaxModel/SyntaxModel.h"

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

std::vector<utils::TerminalInfo> visitor::make_all_terminals(const std::vector<antlr4::tree::TerminalNode*>& contexts)
{
    std::vector<utils::TerminalInfo> syntax_nodes;
    for (auto* ctx : contexts) {
        syntax_nodes.emplace_back(ctx);
    }
    return syntax_nodes;
}
