
// Generated from .\GramComp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "GramCompParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GramCompParser.
 */
class  GramCompListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgramme(GramCompParser::ProgrammeContext *ctx) = 0;
  virtual void exitProgramme(GramCompParser::ProgrammeContext *ctx) = 0;

  virtual void enterBreak(GramCompParser::BreakContext *ctx) = 0;
  virtual void exitBreak(GramCompParser::BreakContext *ctx) = 0;

  virtual void enterContinue(GramCompParser::ContinueContext *ctx) = 0;
  virtual void exitContinue(GramCompParser::ContinueContext *ctx) = 0;

  virtual void enterStructure_instr(GramCompParser::Structure_instrContext *ctx) = 0;
  virtual void exitStructure_instr(GramCompParser::Structure_instrContext *ctx) = 0;

  virtual void enterFucntioncall(GramCompParser::FucntioncallContext *ctx) = 0;
  virtual void exitFucntioncall(GramCompParser::FucntioncallContext *ctx) = 0;

  virtual void enterReturn(GramCompParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(GramCompParser::ReturnContext *ctx) = 0;

  virtual void enterExpression_instr(GramCompParser::Expression_instrContext *ctx) = 0;
  virtual void exitExpression_instr(GramCompParser::Expression_instrContext *ctx) = 0;

  virtual void enterSemicolon_instr(GramCompParser::Semicolon_instrContext *ctx) = 0;
  virtual void exitSemicolon_instr(GramCompParser::Semicolon_instrContext *ctx) = 0;

  virtual void enterIncludeCroch(GramCompParser::IncludeCrochContext *ctx) = 0;
  virtual void exitIncludeCroch(GramCompParser::IncludeCrochContext *ctx) = 0;

  virtual void enterIncludeGuill(GramCompParser::IncludeGuillContext *ctx) = 0;
  virtual void exitIncludeGuill(GramCompParser::IncludeGuillContext *ctx) = 0;

  virtual void enterFunction_def(GramCompParser::Function_defContext *ctx) = 0;
  virtual void exitFunction_def(GramCompParser::Function_defContext *ctx) = 0;

  virtual void enterVoid_arg(GramCompParser::Void_argContext *ctx) = 0;
  virtual void exitVoid_arg(GramCompParser::Void_argContext *ctx) = 0;

  virtual void enterArgs_list(GramCompParser::Args_listContext *ctx) = 0;
  virtual void exitArgs_list(GramCompParser::Args_listContext *ctx) = 0;

  virtual void enterFunctioninit_decl(GramCompParser::Functioninit_declContext *ctx) = 0;
  virtual void exitFunctioninit_decl(GramCompParser::Functioninit_declContext *ctx) = 0;

  virtual void enterFunctioninit_def(GramCompParser::Functioninit_defContext *ctx) = 0;
  virtual void exitFunctioninit_def(GramCompParser::Functioninit_defContext *ctx) = 0;

  virtual void enterInf(GramCompParser::InfContext *ctx) = 0;
  virtual void exitInf(GramCompParser::InfContext *ctx) = 0;

  virtual void enterIdentifier(GramCompParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(GramCompParser::IdentifierContext *ctx) = 0;

  virtual void enterMinus(GramCompParser::MinusContext *ctx) = 0;
  virtual void exitMinus(GramCompParser::MinusContext *ctx) = 0;

  virtual void enterMult(GramCompParser::MultContext *ctx) = 0;
  virtual void exitMult(GramCompParser::MultContext *ctx) = 0;

  virtual void enterAffect_epxr(GramCompParser::Affect_epxrContext *ctx) = 0;
  virtual void exitAffect_epxr(GramCompParser::Affect_epxrContext *ctx) = 0;

  virtual void enterString(GramCompParser::StringContext *ctx) = 0;
  virtual void exitString(GramCompParser::StringContext *ctx) = 0;

  virtual void enterSupequal(GramCompParser::SupequalContext *ctx) = 0;
  virtual void exitSupequal(GramCompParser::SupequalContext *ctx) = 0;

  virtual void enterInfequal(GramCompParser::InfequalContext *ctx) = 0;
  virtual void exitInfequal(GramCompParser::InfequalContext *ctx) = 0;

  virtual void enterInteger(GramCompParser::IntegerContext *ctx) = 0;
  virtual void exitInteger(GramCompParser::IntegerContext *ctx) = 0;

  virtual void enterParenthesis(GramCompParser::ParenthesisContext *ctx) = 0;
  virtual void exitParenthesis(GramCompParser::ParenthesisContext *ctx) = 0;

  virtual void enterPlus(GramCompParser::PlusContext *ctx) = 0;
  virtual void exitPlus(GramCompParser::PlusContext *ctx) = 0;

  virtual void enterSup(GramCompParser::SupContext *ctx) = 0;
  virtual void exitSup(GramCompParser::SupContext *ctx) = 0;

  virtual void enterDiv(GramCompParser::DivContext *ctx) = 0;
  virtual void exitDiv(GramCompParser::DivContext *ctx) = 0;

  virtual void enterEqual(GramCompParser::EqualContext *ctx) = 0;
  virtual void exitEqual(GramCompParser::EqualContext *ctx) = 0;

  virtual void enterNot(GramCompParser::NotContext *ctx) = 0;
  virtual void exitNot(GramCompParser::NotContext *ctx) = 0;

  virtual void enterChar(GramCompParser::CharContext *ctx) = 0;
  virtual void exitChar(GramCompParser::CharContext *ctx) = 0;

  virtual void enterMinus1(GramCompParser::Minus1Context *ctx) = 0;
  virtual void exitMinus1(GramCompParser::Minus1Context *ctx) = 0;

  virtual void enterDifferent(GramCompParser::DifferentContext *ctx) = 0;
  virtual void exitDifferent(GramCompParser::DifferentContext *ctx) = 0;

  virtual void enterIf(GramCompParser::IfContext *ctx) = 0;
  virtual void exitIf(GramCompParser::IfContext *ctx) = 0;

  virtual void enterWhile(GramCompParser::WhileContext *ctx) = 0;
  virtual void exitWhile(GramCompParser::WhileContext *ctx) = 0;

  virtual void enterElse(GramCompParser::ElseContext *ctx) = 0;
  virtual void exitElse(GramCompParser::ElseContext *ctx) = 0;

  virtual void enterAffect_expr(GramCompParser::Affect_exprContext *ctx) = 0;
  virtual void exitAffect_expr(GramCompParser::Affect_exprContext *ctx) = 0;

  virtual void enterIncrementation(GramCompParser::IncrementationContext *ctx) = 0;
  virtual void exitIncrementation(GramCompParser::IncrementationContext *ctx) = 0;

  virtual void enterDecrementation(GramCompParser::DecrementationContext *ctx) = 0;
  virtual void exitDecrementation(GramCompParser::DecrementationContext *ctx) = 0;

  virtual void enterDividementation(GramCompParser::DividementationContext *ctx) = 0;
  virtual void exitDividementation(GramCompParser::DividementationContext *ctx) = 0;

  virtual void enterMultmentation(GramCompParser::MultmentationContext *ctx) = 0;
  virtual void exitMultmentation(GramCompParser::MultmentationContext *ctx) = 0;

  virtual void enterPourcentmentation(GramCompParser::PourcentmentationContext *ctx) = 0;
  virtual void exitPourcentmentation(GramCompParser::PourcentmentationContext *ctx) = 0;

  virtual void enterIncunairepost(GramCompParser::IncunairepostContext *ctx) = 0;
  virtual void exitIncunairepost(GramCompParser::IncunairepostContext *ctx) = 0;

  virtual void enterIncunairepre(GramCompParser::IncunairepreContext *ctx) = 0;
  virtual void exitIncunairepre(GramCompParser::IncunairepreContext *ctx) = 0;

  virtual void enterTable(GramCompParser::TableContext *ctx) = 0;
  virtual void exitTable(GramCompParser::TableContext *ctx) = 0;

  virtual void enterDefine(GramCompParser::DefineContext *ctx) = 0;
  virtual void exitDefine(GramCompParser::DefineContext *ctx) = 0;

  virtual void enterDeftable(GramCompParser::DeftableContext *ctx) = 0;
  virtual void exitDeftable(GramCompParser::DeftableContext *ctx) = 0;

  virtual void enterDeclare(GramCompParser::DeclareContext *ctx) = 0;
  virtual void exitDeclare(GramCompParser::DeclareContext *ctx) = 0;

  virtual void enterDecltable(GramCompParser::DecltableContext *ctx) = 0;
  virtual void exitDecltable(GramCompParser::DecltableContext *ctx) = 0;

  virtual void enterArray_expr(GramCompParser::Array_exprContext *ctx) = 0;
  virtual void exitArray_expr(GramCompParser::Array_exprContext *ctx) = 0;

  virtual void enterConst_expr(GramCompParser::Const_exprContext *ctx) = 0;
  virtual void exitConst_expr(GramCompParser::Const_exprContext *ctx) = 0;

  virtual void enterAtomic_type(GramCompParser::Atomic_typeContext *ctx) = 0;
  virtual void exitAtomic_type(GramCompParser::Atomic_typeContext *ctx) = 0;

  virtual void enterType(GramCompParser::TypeContext *ctx) = 0;
  virtual void exitType(GramCompParser::TypeContext *ctx) = 0;


};

