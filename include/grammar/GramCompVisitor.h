
// Generated from ./antlr/GramComp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "grammar/GramCompParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GramCompParser.
 */
class  GramCompVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GramCompParser.
   */
    virtual antlrcpp::Any visitProgram(GramCompParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitBreak(GramCompParser::BreakContext *context) = 0;

    virtual antlrcpp::Any visitContinue(GramCompParser::ContinueContext *context) = 0;

    virtual antlrcpp::Any visitStructure_instr(GramCompParser::Structure_instrContext *context) = 0;

    virtual antlrcpp::Any visitFucntioncall(GramCompParser::FucntioncallContext *context) = 0;

    virtual antlrcpp::Any visitReturn(GramCompParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitExpression_instr(GramCompParser::Expression_instrContext *context) = 0;

    virtual antlrcpp::Any visitSemicolon_instr(GramCompParser::Semicolon_instrContext *context) = 0;

    virtual antlrcpp::Any visitFunction(GramCompParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitVoid_arg(GramCompParser::Void_argContext *context) = 0;

    virtual antlrcpp::Any visitArgs_list(GramCompParser::Args_listContext *context) = 0;

    virtual antlrcpp::Any visitFunctioninit_decl(GramCompParser::Functioninit_declContext *context) = 0;

    virtual antlrcpp::Any visitFunctioninit_def(GramCompParser::Functioninit_defContext *context) = 0;

    virtual antlrcpp::Any visitInfequal(GramCompParser::InfequalContext *context) = 0;

    virtual antlrcpp::Any visitDifferent(GramCompParser::DifferentContext *context) = 0;

    virtual antlrcpp::Any visitPlus(GramCompParser::PlusContext *context) = 0;

    virtual antlrcpp::Any visitMult(GramCompParser::MultContext *context) = 0;

    virtual antlrcpp::Any visitMinus(GramCompParser::MinusContext *context) = 0;

    virtual antlrcpp::Any visitInteger(GramCompParser::IntegerContext *context) = 0;

    virtual antlrcpp::Any visitChar(GramCompParser::CharContext *context) = 0;

    virtual antlrcpp::Any visitInf(GramCompParser::InfContext *context) = 0;

    virtual antlrcpp::Any visitDiv(GramCompParser::DivContext *context) = 0;

    virtual antlrcpp::Any visitEqual(GramCompParser::EqualContext *context) = 0;

    virtual antlrcpp::Any visitSup(GramCompParser::SupContext *context) = 0;

    virtual antlrcpp::Any visitNot(GramCompParser::NotContext *context) = 0;

    virtual antlrcpp::Any visitString(GramCompParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitAffect_epxr(GramCompParser::Affect_epxrContext *context) = 0;

    virtual antlrcpp::Any visitSupequal(GramCompParser::SupequalContext *context) = 0;

    virtual antlrcpp::Any visitParenthesis(GramCompParser::ParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(GramCompParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitMinus1(GramCompParser::Minus1Context *context) = 0;

    virtual antlrcpp::Any visitIf(GramCompParser::IfContext *context) = 0;

    virtual antlrcpp::Any visitWhile(GramCompParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitElse(GramCompParser::ElseContext *context) = 0;

    virtual antlrcpp::Any visitAffect_expr(GramCompParser::Affect_exprContext *context) = 0;

    virtual antlrcpp::Any visitIncrementation(GramCompParser::IncrementationContext *context) = 0;

    virtual antlrcpp::Any visitDecrementation(GramCompParser::DecrementationContext *context) = 0;

    virtual antlrcpp::Any visitDividementation(GramCompParser::DividementationContext *context) = 0;

    virtual antlrcpp::Any visitMultmentation(GramCompParser::MultmentationContext *context) = 0;

    virtual antlrcpp::Any visitPourcentmentation(GramCompParser::PourcentmentationContext *context) = 0;

    virtual antlrcpp::Any visitIncunairepost(GramCompParser::IncunairepostContext *context) = 0;

    virtual antlrcpp::Any visitIncunairepre(GramCompParser::IncunairepreContext *context) = 0;

    virtual antlrcpp::Any visitTable(GramCompParser::TableContext *context) = 0;

    virtual antlrcpp::Any visitDefine(GramCompParser::DefineContext *context) = 0;

    virtual antlrcpp::Any visitDeftable(GramCompParser::DeftableContext *context) = 0;

    virtual antlrcpp::Any visitDeclare(GramCompParser::DeclareContext *context) = 0;

    virtual antlrcpp::Any visitDecltable(GramCompParser::DecltableContext *context) = 0;

    virtual antlrcpp::Any visitArray_expr(GramCompParser::Array_exprContext *context) = 0;

    virtual antlrcpp::Any visitConst_expr(GramCompParser::Const_exprContext *context) = 0;

    virtual antlrcpp::Any visitAtomic_type(GramCompParser::Atomic_typeContext *context) = 0;

    virtual antlrcpp::Any visitType(GramCompParser::TypeContext *context) = 0;


};

