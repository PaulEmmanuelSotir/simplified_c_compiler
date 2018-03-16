
// Generated from .\GramComp.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "GramCompListener.h"


/**
 * This class provides an empty implementation of GramCompListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GramCompBaseListener : public GramCompListener {
public:

  virtual void enterProgramme(GramCompParser::ProgrammeContext * /*ctx*/) override { }
  virtual void exitProgramme(GramCompParser::ProgrammeContext * /*ctx*/) override { }

  virtual void enterBreak(GramCompParser::BreakContext * /*ctx*/) override { }
  virtual void exitBreak(GramCompParser::BreakContext * /*ctx*/) override { }

  virtual void enterContinue(GramCompParser::ContinueContext * /*ctx*/) override { }
  virtual void exitContinue(GramCompParser::ContinueContext * /*ctx*/) override { }

  virtual void enterStructure_instr(GramCompParser::Structure_instrContext * /*ctx*/) override { }
  virtual void exitStructure_instr(GramCompParser::Structure_instrContext * /*ctx*/) override { }

  virtual void enterFucntioncall(GramCompParser::FucntioncallContext * /*ctx*/) override { }
  virtual void exitFucntioncall(GramCompParser::FucntioncallContext * /*ctx*/) override { }

  virtual void enterReturn(GramCompParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(GramCompParser::ReturnContext * /*ctx*/) override { }

  virtual void enterExpression_instr(GramCompParser::Expression_instrContext * /*ctx*/) override { }
  virtual void exitExpression_instr(GramCompParser::Expression_instrContext * /*ctx*/) override { }

  virtual void enterSemicolon_instr(GramCompParser::Semicolon_instrContext * /*ctx*/) override { }
  virtual void exitSemicolon_instr(GramCompParser::Semicolon_instrContext * /*ctx*/) override { }

  virtual void enterIncludeCroch(GramCompParser::IncludeCrochContext * /*ctx*/) override { }
  virtual void exitIncludeCroch(GramCompParser::IncludeCrochContext * /*ctx*/) override { }

  virtual void enterIncludeGuill(GramCompParser::IncludeGuillContext * /*ctx*/) override { }
  virtual void exitIncludeGuill(GramCompParser::IncludeGuillContext * /*ctx*/) override { }

  virtual void enterFunction_def(GramCompParser::Function_defContext * /*ctx*/) override { }
  virtual void exitFunction_def(GramCompParser::Function_defContext * /*ctx*/) override { }

  virtual void enterVoid_arg(GramCompParser::Void_argContext * /*ctx*/) override { }
  virtual void exitVoid_arg(GramCompParser::Void_argContext * /*ctx*/) override { }

  virtual void enterArgs_list(GramCompParser::Args_listContext * /*ctx*/) override { }
  virtual void exitArgs_list(GramCompParser::Args_listContext * /*ctx*/) override { }

  virtual void enterFunctioninit_decl(GramCompParser::Functioninit_declContext * /*ctx*/) override { }
  virtual void exitFunctioninit_decl(GramCompParser::Functioninit_declContext * /*ctx*/) override { }

  virtual void enterFunctioninit_def(GramCompParser::Functioninit_defContext * /*ctx*/) override { }
  virtual void exitFunctioninit_def(GramCompParser::Functioninit_defContext * /*ctx*/) override { }

  virtual void enterInf(GramCompParser::InfContext * /*ctx*/) override { }
  virtual void exitInf(GramCompParser::InfContext * /*ctx*/) override { }

  virtual void enterIdentifier(GramCompParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(GramCompParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterMinus(GramCompParser::MinusContext * /*ctx*/) override { }
  virtual void exitMinus(GramCompParser::MinusContext * /*ctx*/) override { }

  virtual void enterMult(GramCompParser::MultContext * /*ctx*/) override { }
  virtual void exitMult(GramCompParser::MultContext * /*ctx*/) override { }

  virtual void enterAffect_epxr(GramCompParser::Affect_epxrContext * /*ctx*/) override { }
  virtual void exitAffect_epxr(GramCompParser::Affect_epxrContext * /*ctx*/) override { }

  virtual void enterString(GramCompParser::StringContext * /*ctx*/) override { }
  virtual void exitString(GramCompParser::StringContext * /*ctx*/) override { }

  virtual void enterSupequal(GramCompParser::SupequalContext * /*ctx*/) override { }
  virtual void exitSupequal(GramCompParser::SupequalContext * /*ctx*/) override { }

  virtual void enterInfequal(GramCompParser::InfequalContext * /*ctx*/) override { }
  virtual void exitInfequal(GramCompParser::InfequalContext * /*ctx*/) override { }

  virtual void enterInteger(GramCompParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(GramCompParser::IntegerContext * /*ctx*/) override { }

  virtual void enterParenthesis(GramCompParser::ParenthesisContext * /*ctx*/) override { }
  virtual void exitParenthesis(GramCompParser::ParenthesisContext * /*ctx*/) override { }

  virtual void enterPlus(GramCompParser::PlusContext * /*ctx*/) override { }
  virtual void exitPlus(GramCompParser::PlusContext * /*ctx*/) override { }

  virtual void enterSup(GramCompParser::SupContext * /*ctx*/) override { }
  virtual void exitSup(GramCompParser::SupContext * /*ctx*/) override { }

  virtual void enterDiv(GramCompParser::DivContext * /*ctx*/) override { }
  virtual void exitDiv(GramCompParser::DivContext * /*ctx*/) override { }

  virtual void enterEqual(GramCompParser::EqualContext * /*ctx*/) override { }
  virtual void exitEqual(GramCompParser::EqualContext * /*ctx*/) override { }

  virtual void enterNot(GramCompParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(GramCompParser::NotContext * /*ctx*/) override { }

  virtual void enterChar(GramCompParser::CharContext * /*ctx*/) override { }
  virtual void exitChar(GramCompParser::CharContext * /*ctx*/) override { }

  virtual void enterMinus1(GramCompParser::Minus1Context * /*ctx*/) override { }
  virtual void exitMinus1(GramCompParser::Minus1Context * /*ctx*/) override { }

  virtual void enterDifferent(GramCompParser::DifferentContext * /*ctx*/) override { }
  virtual void exitDifferent(GramCompParser::DifferentContext * /*ctx*/) override { }

  virtual void enterIf(GramCompParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(GramCompParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(GramCompParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(GramCompParser::WhileContext * /*ctx*/) override { }

  virtual void enterElse(GramCompParser::ElseContext * /*ctx*/) override { }
  virtual void exitElse(GramCompParser::ElseContext * /*ctx*/) override { }

  virtual void enterAffect_expr(GramCompParser::Affect_exprContext * /*ctx*/) override { }
  virtual void exitAffect_expr(GramCompParser::Affect_exprContext * /*ctx*/) override { }

  virtual void enterIncrementation(GramCompParser::IncrementationContext * /*ctx*/) override { }
  virtual void exitIncrementation(GramCompParser::IncrementationContext * /*ctx*/) override { }

  virtual void enterDecrementation(GramCompParser::DecrementationContext * /*ctx*/) override { }
  virtual void exitDecrementation(GramCompParser::DecrementationContext * /*ctx*/) override { }

  virtual void enterDividementation(GramCompParser::DividementationContext * /*ctx*/) override { }
  virtual void exitDividementation(GramCompParser::DividementationContext * /*ctx*/) override { }

  virtual void enterMultmentation(GramCompParser::MultmentationContext * /*ctx*/) override { }
  virtual void exitMultmentation(GramCompParser::MultmentationContext * /*ctx*/) override { }

  virtual void enterPourcentmentation(GramCompParser::PourcentmentationContext * /*ctx*/) override { }
  virtual void exitPourcentmentation(GramCompParser::PourcentmentationContext * /*ctx*/) override { }

  virtual void enterIncunairepost(GramCompParser::IncunairepostContext * /*ctx*/) override { }
  virtual void exitIncunairepost(GramCompParser::IncunairepostContext * /*ctx*/) override { }

  virtual void enterIncunairepre(GramCompParser::IncunairepreContext * /*ctx*/) override { }
  virtual void exitIncunairepre(GramCompParser::IncunairepreContext * /*ctx*/) override { }

  virtual void enterTable(GramCompParser::TableContext * /*ctx*/) override { }
  virtual void exitTable(GramCompParser::TableContext * /*ctx*/) override { }

  virtual void enterDefine(GramCompParser::DefineContext * /*ctx*/) override { }
  virtual void exitDefine(GramCompParser::DefineContext * /*ctx*/) override { }

  virtual void enterDeftable(GramCompParser::DeftableContext * /*ctx*/) override { }
  virtual void exitDeftable(GramCompParser::DeftableContext * /*ctx*/) override { }

  virtual void enterDeclare(GramCompParser::DeclareContext * /*ctx*/) override { }
  virtual void exitDeclare(GramCompParser::DeclareContext * /*ctx*/) override { }

  virtual void enterDecltable(GramCompParser::DecltableContext * /*ctx*/) override { }
  virtual void exitDecltable(GramCompParser::DecltableContext * /*ctx*/) override { }

  virtual void enterArray_expr(GramCompParser::Array_exprContext * /*ctx*/) override { }
  virtual void exitArray_expr(GramCompParser::Array_exprContext * /*ctx*/) override { }

  virtual void enterConst_expr(GramCompParser::Const_exprContext * /*ctx*/) override { }
  virtual void exitConst_expr(GramCompParser::Const_exprContext * /*ctx*/) override { }

  virtual void enterAtomic_type(GramCompParser::Atomic_typeContext * /*ctx*/) override { }
  virtual void exitAtomic_type(GramCompParser::Atomic_typeContext * /*ctx*/) override { }

  virtual void enterType(GramCompParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(GramCompParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

