
// Generated from ./antlr/GramComp.g4 by ANTLR 4.7.1


#include "grammar/GramCompVisitor.h"

#include "grammar/GramCompParser.h"


using namespace antlrcpp;
using namespace antlr4;

GramCompParser::GramCompParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GramCompParser::~GramCompParser() {
  delete _interpreter;
}

std::string GramCompParser::getGrammarFileName() const {
  return "GramComp.g4";
}

const std::vector<std::string>& GramCompParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GramCompParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

GramCompParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GramCompParser::ProgramContext::INCLUDE() {
  return getTokens(GramCompParser::INCLUDE);
}

tree::TerminalNode* GramCompParser::ProgramContext::INCLUDE(size_t i) {
  return getToken(GramCompParser::INCLUDE, i);
}

std::vector<GramCompParser::DeclarationContext *> GramCompParser::ProgramContext::declaration() {
  return getRuleContexts<GramCompParser::DeclarationContext>();
}

GramCompParser::DeclarationContext* GramCompParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<GramCompParser::DeclarationContext>(i);
}

std::vector<GramCompParser::DefinitionContext *> GramCompParser::ProgramContext::definition() {
  return getRuleContexts<GramCompParser::DefinitionContext>();
}

GramCompParser::DefinitionContext* GramCompParser::ProgramContext::definition(size_t i) {
  return getRuleContext<GramCompParser::DefinitionContext>(i);
}

std::vector<GramCompParser::FunctionContext *> GramCompParser::ProgramContext::function() {
  return getRuleContexts<GramCompParser::FunctionContext>();
}

GramCompParser::FunctionContext* GramCompParser::ProgramContext::function(size_t i) {
  return getRuleContext<GramCompParser::FunctionContext>(i);
}


size_t GramCompParser::ProgramContext::getRuleIndex() const {
  return GramCompParser::RuleProgram;
}

antlrcpp::Any GramCompParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::ProgramContext* GramCompParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, GramCompParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::T__7)
      | (1ULL << GramCompParser::CHAR)
      | (1ULL << GramCompParser::INT32_T)
      | (1ULL << GramCompParser::INT64_T)
      | (1ULL << GramCompParser::INCLUDE))) != 0)) {
      setState(34);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(30);
        match(GramCompParser::INCLUDE);
        break;
      }

      case 2: {
        setState(31);
        declaration();
        break;
      }

      case 3: {
        setState(32);
        definition();
        break;
      }

      case 4: {
        setState(33);
        function();
        break;
      }

      }
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

GramCompParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::InstructionContext::getRuleIndex() const {
  return GramCompParser::RuleInstruction;
}

void GramCompParser::InstructionContext::copyFrom(InstructionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FucntioncallContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::FucntioncallContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

std::vector<GramCompParser::ExpressionContext *> GramCompParser::FucntioncallContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::FucntioncallContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::FucntioncallContext::FucntioncallContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::FucntioncallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitFucntioncall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakContext ------------------------------------------------------------------

GramCompParser::BreakContext::BreakContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::BreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expression_instrContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::Expression_instrContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::Expression_instrContext::Expression_instrContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Expression_instrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitExpression_instr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueContext ------------------------------------------------------------------

GramCompParser::ContinueContext::ContinueContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::ContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitContinue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::ReturnContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::ReturnContext::ReturnContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Semicolon_instrContext ------------------------------------------------------------------

GramCompParser::Semicolon_instrContext::Semicolon_instrContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Semicolon_instrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitSemicolon_instr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Structure_instrContext ------------------------------------------------------------------

GramCompParser::StructureContext* GramCompParser::Structure_instrContext::structure() {
  return getRuleContext<GramCompParser::StructureContext>(0);
}

GramCompParser::Structure_instrContext::Structure_instrContext(InstructionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Structure_instrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitStructure_instr(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::InstructionContext* GramCompParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 2, GramCompParser::RuleInstruction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::BreakContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(39);
      match(GramCompParser::T__0);
      setState(40);
      match(GramCompParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::ContinueContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(41);
      match(GramCompParser::T__2);
      setState(42);
      match(GramCompParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::Structure_instrContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(43);
      structure();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::FucntioncallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(44);
      match(GramCompParser::IDENTIFIER);
      setState(45);
      match(GramCompParser::T__3);
      setState(54);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GramCompParser::T__3)
        | (1ULL << GramCompParser::T__11)
        | (1ULL << GramCompParser::T__12)
        | (1ULL << GramCompParser::T__30)
        | (1ULL << GramCompParser::T__31)
        | (1ULL << GramCompParser::INTEGER)
        | (1ULL << GramCompParser::IDENTIFIER)
        | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
        | (1ULL << GramCompParser::STRING_LITERAL))) != 0)) {
        setState(46);
        expression(0);
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GramCompParser::T__4) {
          setState(47);
          match(GramCompParser::T__4);
          setState(48);
          expression(0);
          setState(53);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(56);
      match(GramCompParser::T__5);
      setState(57);
      match(GramCompParser::T__1);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::ReturnContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(58);
      match(GramCompParser::T__6);
      setState(59);
      expression(0);
      setState(60);
      match(GramCompParser::T__1);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::Expression_instrContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(62);
      expression(0);
      setState(63);
      match(GramCompParser::T__1);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<InstructionContext *>(_tracker.createInstance<GramCompParser::Semicolon_instrContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(65);
      match(GramCompParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

GramCompParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GramCompParser::FunctionContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::TypeContext* GramCompParser::FunctionContext::type() {
  return getRuleContext<GramCompParser::TypeContext>(0);
}

GramCompParser::ArgsContext* GramCompParser::FunctionContext::args() {
  return getRuleContext<GramCompParser::ArgsContext>(0);
}

std::vector<GramCompParser::Function_initContext *> GramCompParser::FunctionContext::function_init() {
  return getRuleContexts<GramCompParser::Function_initContext>();
}

GramCompParser::Function_initContext* GramCompParser::FunctionContext::function_init(size_t i) {
  return getRuleContext<GramCompParser::Function_initContext>(i);
}

std::vector<GramCompParser::InstructionContext *> GramCompParser::FunctionContext::instruction() {
  return getRuleContexts<GramCompParser::InstructionContext>();
}

GramCompParser::InstructionContext* GramCompParser::FunctionContext::instruction(size_t i) {
  return getRuleContext<GramCompParser::InstructionContext>(i);
}


size_t GramCompParser::FunctionContext::getRuleIndex() const {
  return GramCompParser::RuleFunction;
}

antlrcpp::Any GramCompParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::FunctionContext* GramCompParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, GramCompParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GramCompParser::CHAR:
      case GramCompParser::INT32_T:
      case GramCompParser::INT64_T: {
        setState(68);
        type();
        break;
      }

      case GramCompParser::T__7: {
        setState(69);
        match(GramCompParser::T__7);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(72);
    match(GramCompParser::IDENTIFIER);
    setState(73);
    match(GramCompParser::T__3);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::T__7)
      | (1ULL << GramCompParser::CHAR)
      | (1ULL << GramCompParser::INT32_T)
      | (1ULL << GramCompParser::INT64_T))) != 0)) {
      setState(74);
      args();
    }
    setState(77);
    match(GramCompParser::T__5);
    setState(78);
    match(GramCompParser::T__8);
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::CHAR)
      | (1ULL << GramCompParser::INT32_T)
      | (1ULL << GramCompParser::INT64_T))) != 0)) {
      setState(79);
      function_init();
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::T__0)
      | (1ULL << GramCompParser::T__1)
      | (1ULL << GramCompParser::T__2)
      | (1ULL << GramCompParser::T__3)
      | (1ULL << GramCompParser::T__6)
      | (1ULL << GramCompParser::T__11)
      | (1ULL << GramCompParser::T__12)
      | (1ULL << GramCompParser::T__21)
      | (1ULL << GramCompParser::T__22)
      | (1ULL << GramCompParser::T__30)
      | (1ULL << GramCompParser::T__31)
      | (1ULL << GramCompParser::INTEGER)
      | (1ULL << GramCompParser::IDENTIFIER)
      | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
      | (1ULL << GramCompParser::STRING_LITERAL))) != 0)) {
      setState(85);
      instruction();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    match(GramCompParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

GramCompParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::ArgsContext::getRuleIndex() const {
  return GramCompParser::RuleArgs;
}

void GramCompParser::ArgsContext::copyFrom(ArgsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Void_argContext ------------------------------------------------------------------

GramCompParser::Void_argContext::Void_argContext(ArgsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Void_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitVoid_arg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Args_listContext ------------------------------------------------------------------

std::vector<GramCompParser::TypeContext *> GramCompParser::Args_listContext::type() {
  return getRuleContexts<GramCompParser::TypeContext>();
}

GramCompParser::TypeContext* GramCompParser::Args_listContext::type(size_t i) {
  return getRuleContext<GramCompParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> GramCompParser::Args_listContext::IDENTIFIER() {
  return getTokens(GramCompParser::IDENTIFIER);
}

tree::TerminalNode* GramCompParser::Args_listContext::IDENTIFIER(size_t i) {
  return getToken(GramCompParser::IDENTIFIER, i);
}

GramCompParser::Args_listContext::Args_listContext(ArgsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Args_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitArgs_list(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::ArgsContext* GramCompParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 6, GramCompParser::RuleArgs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GramCompParser::T__7: {
        _localctx = dynamic_cast<ArgsContext *>(_tracker.createInstance<GramCompParser::Void_argContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(93);
        match(GramCompParser::T__7);
        break;
      }

      case GramCompParser::CHAR:
      case GramCompParser::INT32_T:
      case GramCompParser::INT64_T: {
        _localctx = dynamic_cast<ArgsContext *>(_tracker.createInstance<GramCompParser::Args_listContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(94);
        type();
        setState(95);
        match(GramCompParser::IDENTIFIER);
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GramCompParser::T__4) {
          setState(96);
          match(GramCompParser::T__4);
          setState(97);
          type();
          setState(98);
          match(GramCompParser::IDENTIFIER);
          setState(104);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_initContext ------------------------------------------------------------------

GramCompParser::Function_initContext::Function_initContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::Function_initContext::getRuleIndex() const {
  return GramCompParser::RuleFunction_init;
}

void GramCompParser::Function_initContext::copyFrom(Function_initContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Functioninit_declContext ------------------------------------------------------------------

GramCompParser::DeclarationContext* GramCompParser::Functioninit_declContext::declaration() {
  return getRuleContext<GramCompParser::DeclarationContext>(0);
}

GramCompParser::Functioninit_declContext::Functioninit_declContext(Function_initContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Functioninit_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitFunctioninit_decl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Functioninit_defContext ------------------------------------------------------------------

GramCompParser::DefinitionContext* GramCompParser::Functioninit_defContext::definition() {
  return getRuleContext<GramCompParser::DefinitionContext>(0);
}

GramCompParser::Functioninit_defContext::Functioninit_defContext(Function_initContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Functioninit_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitFunctioninit_def(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::Function_initContext* GramCompParser::function_init() {
  Function_initContext *_localctx = _tracker.createInstance<Function_initContext>(_ctx, getState());
  enterRule(_localctx, 8, GramCompParser::RuleFunction_init);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Function_initContext *>(_tracker.createInstance<GramCompParser::Functioninit_declContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(107);
      declaration();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Function_initContext *>(_tracker.createInstance<GramCompParser::Functioninit_defContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(108);
      definition();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GramCompParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::ExpressionContext::getRuleIndex() const {
  return GramCompParser::RuleExpression;
}

void GramCompParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InfequalContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::InfequalContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::InfequalContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::InfequalContext::InfequalContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::InfequalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitInfequal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DifferentContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::DifferentContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::DifferentContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::DifferentContext::DifferentContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DifferentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDifferent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::PlusContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::PlusContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::PlusContext::PlusContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::PlusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitPlus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::MultContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::MultContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::MultContext::MultContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MinusContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::MinusContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::MinusContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::MinusContext::MinusContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::MinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::IntegerContext::INTEGER() {
  return getToken(GramCompParser::INTEGER, 0);
}

GramCompParser::IntegerContext::IntegerContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitInteger(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::CharContext::QUOTED_CHAR_LITERAL() {
  return getToken(GramCompParser::QUOTED_CHAR_LITERAL, 0);
}

GramCompParser::CharContext::CharContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InfContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::InfContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::InfContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::InfContext::InfContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::InfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitInf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::DivContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::DivContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::DivContext::DivContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::EqualContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::EqualContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::EqualContext::EqualContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::EqualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitEqual(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SupContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::SupContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::SupContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::SupContext::SupContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::SupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitSup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::NotContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::NotContext::NotContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::StringContext::STRING_LITERAL() {
  return getToken(GramCompParser::STRING_LITERAL, 0);
}

GramCompParser::StringContext::StringContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affect_epxrContext ------------------------------------------------------------------

GramCompParser::AffectationContext* GramCompParser::Affect_epxrContext::affectation() {
  return getRuleContext<GramCompParser::AffectationContext>(0);
}

GramCompParser::Affect_epxrContext::Affect_epxrContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Affect_epxrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitAffect_epxr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SupequalContext ------------------------------------------------------------------

std::vector<GramCompParser::ExpressionContext *> GramCompParser::SupequalContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::SupequalContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::SupequalContext::SupequalContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::SupequalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitSupequal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::ParenthesisContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::ParenthesisContext::ParenthesisContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::IdentifierContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::IdentifierContext::IdentifierContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Minus1Context ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::Minus1Context::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::Minus1Context::Minus1Context(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Minus1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitMinus1(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::ExpressionContext* GramCompParser::expression() {
   return expression(0);
}

GramCompParser::ExpressionContext* GramCompParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GramCompParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  GramCompParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, GramCompParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(112);
      match(GramCompParser::T__3);
      setState(113);
      expression(0);
      setState(114);
      match(GramCompParser::T__5);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Minus1Context>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(116);
      match(GramCompParser::T__11);
      setState(117);
      expression(15);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(118);
      match(GramCompParser::T__12);
      setState(119);
      expression(14);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Affect_epxrContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(120);
      affectation();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<IntegerContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(GramCompParser::INTEGER);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CharContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(122);
      match(GramCompParser::QUOTED_CHAR_LITERAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      match(GramCompParser::STRING_LITERAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(124);
      match(GramCompParser::IDENTIFIER);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(157);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(127);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(128);
          match(GramCompParser::T__10);
          setState(129);
          expression(18);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MinusContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(130);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(131);
          match(GramCompParser::T__11);
          setState(132);
          expression(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(133);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(134);
          match(GramCompParser::T__13);
          setState(135);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(136);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(137);
          match(GramCompParser::T__14);
          setState(138);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(139);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(140);
          match(GramCompParser::T__15);
          setState(141);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<DifferentContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(142);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(143);
          match(GramCompParser::T__16);
          setState(144);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<InfContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(145);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(146);
          match(GramCompParser::T__17);
          setState(147);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<InfequalContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(148);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(149);
          match(GramCompParser::T__18);
          setState(150);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<SupContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(151);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(152);
          match(GramCompParser::T__19);
          setState(153);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<SupequalContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(154);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(155);
          match(GramCompParser::T__20);
          setState(156);
          expression(7);
          break;
        }

        } 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

GramCompParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::StructureContext::getRuleIndex() const {
  return GramCompParser::RuleStructure;
}

void GramCompParser::StructureContext::copyFrom(StructureContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::IfContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

std::vector<GramCompParser::InstructionContext *> GramCompParser::IfContext::instruction() {
  return getRuleContexts<GramCompParser::InstructionContext>();
}

GramCompParser::InstructionContext* GramCompParser::IfContext::instruction(size_t i) {
  return getRuleContext<GramCompParser::InstructionContext>(i);
}

GramCompParser::Else_structureContext* GramCompParser::IfContext::else_structure() {
  return getRuleContext<GramCompParser::Else_structureContext>(0);
}

GramCompParser::IfContext::IfContext(StructureContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

GramCompParser::ExpressionContext* GramCompParser::WhileContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

std::vector<GramCompParser::InstructionContext *> GramCompParser::WhileContext::instruction() {
  return getRuleContexts<GramCompParser::InstructionContext>();
}

GramCompParser::InstructionContext* GramCompParser::WhileContext::instruction(size_t i) {
  return getRuleContext<GramCompParser::InstructionContext>(i);
}

GramCompParser::WhileContext::WhileContext(StructureContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::StructureContext* GramCompParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 12, GramCompParser::RuleStructure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GramCompParser::T__21: {
        _localctx = dynamic_cast<StructureContext *>(_tracker.createInstance<GramCompParser::IfContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(162);
        match(GramCompParser::T__21);
        setState(163);
        match(GramCompParser::T__3);
        setState(164);
        expression(0);
        setState(165);
        match(GramCompParser::T__5);
        setState(166);
        match(GramCompParser::T__8);
        setState(170);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << GramCompParser::T__0)
          | (1ULL << GramCompParser::T__1)
          | (1ULL << GramCompParser::T__2)
          | (1ULL << GramCompParser::T__3)
          | (1ULL << GramCompParser::T__6)
          | (1ULL << GramCompParser::T__11)
          | (1ULL << GramCompParser::T__12)
          | (1ULL << GramCompParser::T__21)
          | (1ULL << GramCompParser::T__22)
          | (1ULL << GramCompParser::T__30)
          | (1ULL << GramCompParser::T__31)
          | (1ULL << GramCompParser::INTEGER)
          | (1ULL << GramCompParser::IDENTIFIER)
          | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
          | (1ULL << GramCompParser::STRING_LITERAL))) != 0)) {
          setState(167);
          instruction();
          setState(172);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(173);
        match(GramCompParser::T__9);
        setState(175);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == GramCompParser::T__23) {
          setState(174);
          else_structure();
        }
        break;
      }

      case GramCompParser::T__22: {
        _localctx = dynamic_cast<StructureContext *>(_tracker.createInstance<GramCompParser::WhileContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(177);
        match(GramCompParser::T__22);
        setState(178);
        match(GramCompParser::T__3);
        setState(179);
        expression(0);
        setState(180);
        match(GramCompParser::T__5);
        setState(181);
        match(GramCompParser::T__8);
        setState(185);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << GramCompParser::T__0)
          | (1ULL << GramCompParser::T__1)
          | (1ULL << GramCompParser::T__2)
          | (1ULL << GramCompParser::T__3)
          | (1ULL << GramCompParser::T__6)
          | (1ULL << GramCompParser::T__11)
          | (1ULL << GramCompParser::T__12)
          | (1ULL << GramCompParser::T__21)
          | (1ULL << GramCompParser::T__22)
          | (1ULL << GramCompParser::T__30)
          | (1ULL << GramCompParser::T__31)
          | (1ULL << GramCompParser::INTEGER)
          | (1ULL << GramCompParser::IDENTIFIER)
          | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
          | (1ULL << GramCompParser::STRING_LITERAL))) != 0)) {
          setState(182);
          instruction();
          setState(187);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(188);
        match(GramCompParser::T__9);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_structureContext ------------------------------------------------------------------

GramCompParser::Else_structureContext::Else_structureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::Else_structureContext::getRuleIndex() const {
  return GramCompParser::RuleElse_structure;
}

void GramCompParser::Else_structureContext::copyFrom(Else_structureContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ElseContext ------------------------------------------------------------------

std::vector<GramCompParser::InstructionContext *> GramCompParser::ElseContext::instruction() {
  return getRuleContexts<GramCompParser::InstructionContext>();
}

GramCompParser::InstructionContext* GramCompParser::ElseContext::instruction(size_t i) {
  return getRuleContext<GramCompParser::InstructionContext>(i);
}

GramCompParser::ElseContext::ElseContext(Else_structureContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::ElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitElse(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::Else_structureContext* GramCompParser::else_structure() {
  Else_structureContext *_localctx = _tracker.createInstance<Else_structureContext>(_ctx, getState());
  enterRule(_localctx, 14, GramCompParser::RuleElse_structure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Else_structureContext *>(_tracker.createInstance<GramCompParser::ElseContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(GramCompParser::T__23);
    setState(193);
    match(GramCompParser::T__8);
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::T__0)
      | (1ULL << GramCompParser::T__1)
      | (1ULL << GramCompParser::T__2)
      | (1ULL << GramCompParser::T__3)
      | (1ULL << GramCompParser::T__6)
      | (1ULL << GramCompParser::T__11)
      | (1ULL << GramCompParser::T__12)
      | (1ULL << GramCompParser::T__21)
      | (1ULL << GramCompParser::T__22)
      | (1ULL << GramCompParser::T__30)
      | (1ULL << GramCompParser::T__31)
      | (1ULL << GramCompParser::INTEGER)
      | (1ULL << GramCompParser::IDENTIFIER)
      | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
      | (1ULL << GramCompParser::STRING_LITERAL))) != 0)) {
      setState(194);
      instruction();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(200);
    match(GramCompParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AffectationContext ------------------------------------------------------------------

GramCompParser::AffectationContext::AffectationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::AffectationContext::getRuleIndex() const {
  return GramCompParser::RuleAffectation;
}

void GramCompParser::AffectationContext::copyFrom(AffectationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PourcentmentationContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::PourcentmentationContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::PourcentmentationContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::PourcentmentationContext::PourcentmentationContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::PourcentmentationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitPourcentmentation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncunairepreContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::IncunairepreContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::IncunairepreContext::IncunairepreContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IncunairepreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitIncunairepre(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultmentationContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::MultmentationContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::MultmentationContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::MultmentationContext::MultmentationContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::MultmentationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitMultmentation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecrementationContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::DecrementationContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::DecrementationContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::DecrementationContext::DecrementationContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DecrementationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDecrementation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncunairepostContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::IncunairepostContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::IncunairepostContext::IncunairepostContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IncunairepostContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitIncunairepost(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Affect_exprContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::Affect_exprContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::Affect_exprContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::Affect_exprContext::Affect_exprContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::Affect_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitAffect_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DividementationContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::DividementationContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::DividementationContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::DividementationContext::DividementationContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DividementationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDividementation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TableContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::TableContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

std::vector<GramCompParser::ExpressionContext *> GramCompParser::TableContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::TableContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::TableContext::TableContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::TableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncrementationContext ------------------------------------------------------------------

tree::TerminalNode* GramCompParser::IncrementationContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

GramCompParser::ExpressionContext* GramCompParser::IncrementationContext::expression() {
  return getRuleContext<GramCompParser::ExpressionContext>(0);
}

GramCompParser::IncrementationContext::IncrementationContext(AffectationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::IncrementationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitIncrementation(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::AffectationContext* GramCompParser::affectation() {
  AffectationContext *_localctx = _tracker.createInstance<AffectationContext>(_ctx, getState());
  enterRule(_localctx, 16, GramCompParser::RuleAffectation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::Affect_exprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(202);
      match(GramCompParser::IDENTIFIER);
      setState(203);
      match(GramCompParser::T__24);
      setState(204);
      expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::IncrementationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(205);
      match(GramCompParser::IDENTIFIER);
      setState(206);
      match(GramCompParser::T__25);
      setState(207);
      expression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::DecrementationContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(208);
      match(GramCompParser::IDENTIFIER);
      setState(209);
      match(GramCompParser::T__26);
      setState(210);
      expression(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::DividementationContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(211);
      match(GramCompParser::IDENTIFIER);
      setState(212);
      match(GramCompParser::T__27);
      setState(213);
      expression(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::MultmentationContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(214);
      match(GramCompParser::IDENTIFIER);
      setState(215);
      match(GramCompParser::T__28);
      setState(216);
      expression(0);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::PourcentmentationContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(217);
      match(GramCompParser::IDENTIFIER);
      setState(218);
      match(GramCompParser::T__29);
      setState(219);
      expression(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::IncunairepostContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(220);
      match(GramCompParser::IDENTIFIER);
      setState(221);
      _la = _input->LA(1);
      if (!(_la == GramCompParser::T__30

      || _la == GramCompParser::T__31)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 8: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::IncunairepreContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(222);
      _la = _input->LA(1);
      if (!(_la == GramCompParser::T__30

      || _la == GramCompParser::T__31)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(223);
      match(GramCompParser::IDENTIFIER);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<AffectationContext *>(_tracker.createInstance<GramCompParser::TableContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(224);
      match(GramCompParser::IDENTIFIER);
      setState(225);
      match(GramCompParser::T__32);
      setState(226);
      expression(0);
      setState(227);
      match(GramCompParser::T__33);
      setState(228);
      match(GramCompParser::T__24);
      setState(229);
      expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

GramCompParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::DefinitionContext::getRuleIndex() const {
  return GramCompParser::RuleDefinition;
}

void GramCompParser::DefinitionContext::copyFrom(DefinitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefineContext ------------------------------------------------------------------

GramCompParser::TypeContext* GramCompParser::DefineContext::type() {
  return getRuleContext<GramCompParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> GramCompParser::DefineContext::IDENTIFIER() {
  return getTokens(GramCompParser::IDENTIFIER);
}

tree::TerminalNode* GramCompParser::DefineContext::IDENTIFIER(size_t i) {
  return getToken(GramCompParser::IDENTIFIER, i);
}

std::vector<GramCompParser::ExpressionContext *> GramCompParser::DefineContext::expression() {
  return getRuleContexts<GramCompParser::ExpressionContext>();
}

GramCompParser::ExpressionContext* GramCompParser::DefineContext::expression(size_t i) {
  return getRuleContext<GramCompParser::ExpressionContext>(i);
}

GramCompParser::DefineContext::DefineContext(DefinitionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDefine(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeftableContext ------------------------------------------------------------------

GramCompParser::Atomic_typeContext* GramCompParser::DeftableContext::atomic_type() {
  return getRuleContext<GramCompParser::Atomic_typeContext>(0);
}

tree::TerminalNode* GramCompParser::DeftableContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

tree::TerminalNode* GramCompParser::DeftableContext::INTEGER() {
  return getToken(GramCompParser::INTEGER, 0);
}

GramCompParser::Array_exprContext* GramCompParser::DeftableContext::array_expr() {
  return getRuleContext<GramCompParser::Array_exprContext>(0);
}

tree::TerminalNode* GramCompParser::DeftableContext::STRING_LITERAL() {
  return getToken(GramCompParser::STRING_LITERAL, 0);
}

GramCompParser::DeftableContext::DeftableContext(DefinitionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DeftableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDeftable(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::DefinitionContext* GramCompParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 18, GramCompParser::RuleDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DefinitionContext *>(_tracker.createInstance<GramCompParser::DefineContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(233);
      type();
      setState(234);
      match(GramCompParser::IDENTIFIER);
      setState(235);
      match(GramCompParser::T__24);
      setState(236);
      expression(0);
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GramCompParser::T__4) {
        setState(237);
        match(GramCompParser::T__4);
        setState(238);
        match(GramCompParser::IDENTIFIER);
        setState(239);
        match(GramCompParser::T__24);
        setState(240);
        expression(0);
        setState(245);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(246);
      match(GramCompParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DefinitionContext *>(_tracker.createInstance<GramCompParser::DeftableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(248);
      atomic_type();
      setState(249);
      match(GramCompParser::IDENTIFIER);
      setState(250);
      match(GramCompParser::T__32);
      setState(251);
      match(GramCompParser::INTEGER);
      setState(252);
      match(GramCompParser::T__33);
      setState(253);
      match(GramCompParser::T__24);
      setState(256);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case GramCompParser::T__8:
        case GramCompParser::T__34: {
          setState(254);
          array_expr();
          break;
        }

        case GramCompParser::STRING_LITERAL: {
          setState(255);
          match(GramCompParser::STRING_LITERAL);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(258);
      match(GramCompParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

GramCompParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GramCompParser::DeclarationContext::getRuleIndex() const {
  return GramCompParser::RuleDeclaration;
}

void GramCompParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DecltableContext ------------------------------------------------------------------

GramCompParser::Atomic_typeContext* GramCompParser::DecltableContext::atomic_type() {
  return getRuleContext<GramCompParser::Atomic_typeContext>(0);
}

tree::TerminalNode* GramCompParser::DecltableContext::IDENTIFIER() {
  return getToken(GramCompParser::IDENTIFIER, 0);
}

tree::TerminalNode* GramCompParser::DecltableContext::INTEGER() {
  return getToken(GramCompParser::INTEGER, 0);
}

GramCompParser::DecltableContext::DecltableContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DecltableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDecltable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclareContext ------------------------------------------------------------------

GramCompParser::TypeContext* GramCompParser::DeclareContext::type() {
  return getRuleContext<GramCompParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> GramCompParser::DeclareContext::IDENTIFIER() {
  return getTokens(GramCompParser::IDENTIFIER);
}

tree::TerminalNode* GramCompParser::DeclareContext::IDENTIFIER(size_t i) {
  return getToken(GramCompParser::IDENTIFIER, i);
}

GramCompParser::DeclareContext::DeclareContext(DeclarationContext *ctx) { copyFrom(ctx); }

antlrcpp::Any GramCompParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}
GramCompParser::DeclarationContext* GramCompParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 20, GramCompParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<GramCompParser::DeclareContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(262);
      type();
      setState(263);
      match(GramCompParser::IDENTIFIER);
      setState(268);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GramCompParser::T__4) {
        setState(264);
        match(GramCompParser::T__4);
        setState(265);
        match(GramCompParser::IDENTIFIER);
        setState(270);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(271);
      match(GramCompParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<GramCompParser::DecltableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(273);
      atomic_type();
      setState(274);
      match(GramCompParser::IDENTIFIER);
      setState(275);
      match(GramCompParser::T__32);
      setState(276);
      match(GramCompParser::INTEGER);
      setState(277);
      match(GramCompParser::T__33);
      setState(278);
      match(GramCompParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_exprContext ------------------------------------------------------------------

GramCompParser::Array_exprContext::Array_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GramCompParser::Const_exprContext *> GramCompParser::Array_exprContext::const_expr() {
  return getRuleContexts<GramCompParser::Const_exprContext>();
}

GramCompParser::Const_exprContext* GramCompParser::Array_exprContext::const_expr(size_t i) {
  return getRuleContext<GramCompParser::Const_exprContext>(i);
}


size_t GramCompParser::Array_exprContext::getRuleIndex() const {
  return GramCompParser::RuleArray_expr;
}

antlrcpp::Any GramCompParser::Array_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitArray_expr(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::Array_exprContext* GramCompParser::array_expr() {
  Array_exprContext *_localctx = _tracker.createInstance<Array_exprContext>(_ctx, getState());
  enterRule(_localctx, 22, GramCompParser::RuleArray_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(294);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GramCompParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(282);
        match(GramCompParser::T__8);
        setState(283);
        const_expr();
        setState(288);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GramCompParser::T__4) {
          setState(284);
          match(GramCompParser::T__4);
          setState(285);
          const_expr();
          setState(290);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(291);
        match(GramCompParser::T__9);
        break;
      }

      case GramCompParser::T__34: {
        enterOuterAlt(_localctx, 2);
        setState(293);
        match(GramCompParser::T__34);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_exprContext ------------------------------------------------------------------

GramCompParser::Const_exprContext::Const_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GramCompParser::Const_exprContext::INTEGER() {
  return getToken(GramCompParser::INTEGER, 0);
}

tree::TerminalNode* GramCompParser::Const_exprContext::STRING_LITERAL() {
  return getToken(GramCompParser::STRING_LITERAL, 0);
}

tree::TerminalNode* GramCompParser::Const_exprContext::QUOTED_CHAR_LITERAL() {
  return getToken(GramCompParser::QUOTED_CHAR_LITERAL, 0);
}


size_t GramCompParser::Const_exprContext::getRuleIndex() const {
  return GramCompParser::RuleConst_expr;
}

antlrcpp::Any GramCompParser::Const_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitConst_expr(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::Const_exprContext* GramCompParser::const_expr() {
  Const_exprContext *_localctx = _tracker.createInstance<Const_exprContext>(_ctx, getState());
  enterRule(_localctx, 24, GramCompParser::RuleConst_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::INTEGER)
      | (1ULL << GramCompParser::QUOTED_CHAR_LITERAL)
      | (1ULL << GramCompParser::STRING_LITERAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Atomic_typeContext ------------------------------------------------------------------

GramCompParser::Atomic_typeContext::Atomic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GramCompParser::Atomic_typeContext::CHAR() {
  return getToken(GramCompParser::CHAR, 0);
}

tree::TerminalNode* GramCompParser::Atomic_typeContext::INT32_T() {
  return getToken(GramCompParser::INT32_T, 0);
}

tree::TerminalNode* GramCompParser::Atomic_typeContext::INT64_T() {
  return getToken(GramCompParser::INT64_T, 0);
}


size_t GramCompParser::Atomic_typeContext::getRuleIndex() const {
  return GramCompParser::RuleAtomic_type;
}

antlrcpp::Any GramCompParser::Atomic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitAtomic_type(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::Atomic_typeContext* GramCompParser::atomic_type() {
  Atomic_typeContext *_localctx = _tracker.createInstance<Atomic_typeContext>(_ctx, getState());
  enterRule(_localctx, 26, GramCompParser::RuleAtomic_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GramCompParser::CHAR)
      | (1ULL << GramCompParser::INT32_T)
      | (1ULL << GramCompParser::INT64_T))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

GramCompParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GramCompParser::Atomic_typeContext* GramCompParser::TypeContext::atomic_type() {
  return getRuleContext<GramCompParser::Atomic_typeContext>(0);
}


size_t GramCompParser::TypeContext::getRuleIndex() const {
  return GramCompParser::RuleType;
}

antlrcpp::Any GramCompParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GramCompVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

GramCompParser::TypeContext* GramCompParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 28, GramCompParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    atomic_type();
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GramCompParser::T__32) {
      setState(301);
      match(GramCompParser::T__32);
      setState(302);
      match(GramCompParser::T__33);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool GramCompParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GramCompParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 17);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> GramCompParser::_decisionToDFA;
atn::PredictionContextCache GramCompParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GramCompParser::_atn;
std::vector<uint16_t> GramCompParser::_serializedATN;

std::vector<std::string> GramCompParser::_ruleNames = {
  "program", "instruction", "function", "args", "function_init", "expression", 
  "structure", "else_structure", "affectation", "definition", "declaration", 
  "array_expr", "const_expr", "atomic_type", "type"
};

std::vector<std::string> GramCompParser::_literalNames = {
  "", "'break'", "';'", "'continue'", "'('", "','", "')'", "'return'", "'void'", 
  "'{'", "'}'", "'+'", "'-'", "'!'", "'*'", "'/'", "'=='", "'!='", "'<'", 
  "'<='", "'>'", "'>='", "'if'", "'while'", "'else'", "'='", "'+='", "'-='", 
  "'/='", "'*='", "'%='", "'++'", "'--'", "'['", "']'", "'[]'", "", "'char'"
};

std::vector<std::string> GramCompParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "WS", "CHAR", "INTEGER", "INT32_T", "INT64_T", "IDENTIFIER", "QUOTED_CHAR_LITERAL", 
  "STRING_LITERAL", "INCLUDE"
};

dfa::Vocabulary GramCompParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GramCompParser::_tokenNames;

GramCompParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0x134, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x25, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x28, 0xb, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x34, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x37, 0xb, 0x3, 0x5, 0x3, 0x39, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x45, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x49, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4e, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x53, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x56, 
    0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 0x59, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5c, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x67, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x6a, 0xb, 0x5, 0x5, 0x5, 0x6c, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x70, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x80, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0xa0, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xa3, 0xb, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xab, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0xae, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xb2, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x7, 0x8, 0xba, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xbd, 0xb, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0xc1, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0xc6, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xc9, 0xb, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xea, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xf4, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0xf7, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x103, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x107, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x10d, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0x110, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x11b, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x121, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x124, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0x129, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x132, 0xa, 0x10, 0x3, 0x10, 
    0x2, 0x3, 0xc, 0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 0x5, 0x3, 0x2, 0x21, 0x22, 
    0x4, 0x2, 0x28, 0x28, 0x2c, 0x2d, 0x4, 0x2, 0x27, 0x27, 0x29, 0x2a, 
    0x2, 0x15d, 0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 0x8, 0x6b, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7f, 0x3, 0x2, 0x2, 0x2, 0xe, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x12, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x106, 0x3, 0x2, 0x2, 0x2, 0x16, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x128, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x25, 0x7, 0x2e, 0x2, 0x2, 0x21, 0x25, 0x5, 0x16, 0xc, 0x2, 0x22, 
    0x25, 0x5, 0x14, 0xb, 0x2, 0x23, 0x25, 0x5, 0x6, 0x4, 0x2, 0x24, 0x20, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x21, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x3, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x2a, 0x7, 0x3, 0x2, 0x2, 0x2a, 0x45, 0x7, 0x4, 0x2, 0x2, 0x2b, 
    0x2c, 0x7, 0x5, 0x2, 0x2, 0x2c, 0x45, 0x7, 0x4, 0x2, 0x2, 0x2d, 0x45, 
    0x5, 0xe, 0x8, 0x2, 0x2e, 0x2f, 0x7, 0x2b, 0x2, 0x2, 0x2f, 0x38, 0x7, 
    0x6, 0x2, 0x2, 0x30, 0x35, 0x5, 0xc, 0x7, 0x2, 0x31, 0x32, 0x7, 0x7, 
    0x2, 0x2, 0x32, 0x34, 0x5, 0xc, 0x7, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x30, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x8, 0x2, 0x2, 0x3b, 0x45, 0x7, 0x4, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x9, 
    0x2, 0x2, 0x3d, 0x3e, 0x5, 0xc, 0x7, 0x2, 0x3e, 0x3f, 0x7, 0x4, 0x2, 
    0x2, 0x3f, 0x45, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x5, 0xc, 0x7, 0x2, 
    0x41, 0x42, 0x7, 0x4, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x45, 0x7, 0x4, 0x2, 0x2, 0x44, 0x29, 0x3, 0x2, 0x2, 0x2, 0x44, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x44, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x49, 0x5, 0x1e, 0x10, 0x2, 0x47, 0x49, 0x7, 0xa, 0x2, 0x2, 
    0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x2b, 0x2, 0x2, 0x4b, 0x4d, 
    0x7, 0x6, 0x2, 0x2, 0x4c, 0x4e, 0x5, 0x8, 0x5, 0x2, 0x4d, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x50, 0x7, 0x8, 0x2, 0x2, 0x50, 0x54, 0x7, 0xb, 0x2, 
    0x2, 0x51, 0x53, 0x5, 0xa, 0x6, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x59, 0x5, 0x4, 0x3, 0x2, 0x58, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xc, 0x2, 0x2, 
    0x5e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x6c, 0x7, 0xa, 0x2, 0x2, 0x60, 
    0x61, 0x5, 0x1e, 0x10, 0x2, 0x61, 0x68, 0x7, 0x2b, 0x2, 0x2, 0x62, 0x63, 
    0x7, 0x7, 0x2, 0x2, 0x63, 0x64, 0x5, 0x1e, 0x10, 0x2, 0x64, 0x65, 0x7, 
    0x2b, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x70, 
    0x5, 0x16, 0xc, 0x2, 0x6e, 0x70, 0x5, 0x14, 0xb, 0x2, 0x6f, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x72, 0x8, 0x7, 0x1, 0x2, 0x72, 0x73, 0x7, 0x6, 0x2, 
    0x2, 0x73, 0x74, 0x5, 0xc, 0x7, 0x2, 0x74, 0x75, 0x7, 0x8, 0x2, 0x2, 
    0x75, 0x80, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0xe, 0x2, 0x2, 0x77, 
    0x80, 0x5, 0xc, 0x7, 0x11, 0x78, 0x79, 0x7, 0xf, 0x2, 0x2, 0x79, 0x80, 
    0x5, 0xc, 0x7, 0x10, 0x7a, 0x80, 0x5, 0x12, 0xa, 0x2, 0x7b, 0x80, 0x7, 
    0x28, 0x2, 0x2, 0x7c, 0x80, 0x7, 0x2c, 0x2, 0x2, 0x7d, 0x80, 0x7, 0x2d, 
    0x2, 0x2, 0x7e, 0x80, 0x7, 0x2b, 0x2, 0x2, 0x7f, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0xc, 
    0x13, 0x2, 0x2, 0x82, 0x83, 0x7, 0xd, 0x2, 0x2, 0x83, 0xa0, 0x5, 0xc, 
    0x7, 0x14, 0x84, 0x85, 0xc, 0x12, 0x2, 0x2, 0x85, 0x86, 0x7, 0xe, 0x2, 
    0x2, 0x86, 0xa0, 0x5, 0xc, 0x7, 0x13, 0x87, 0x88, 0xc, 0xf, 0x2, 0x2, 
    0x88, 0x89, 0x7, 0x10, 0x2, 0x2, 0x89, 0xa0, 0x5, 0xc, 0x7, 0x10, 0x8a, 
    0x8b, 0xc, 0xe, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x11, 0x2, 0x2, 0x8c, 0xa0, 
    0x5, 0xc, 0x7, 0xf, 0x8d, 0x8e, 0xc, 0xd, 0x2, 0x2, 0x8e, 0x8f, 0x7, 
    0x12, 0x2, 0x2, 0x8f, 0xa0, 0x5, 0xc, 0x7, 0xe, 0x90, 0x91, 0xc, 0xc, 
    0x2, 0x2, 0x91, 0x92, 0x7, 0x13, 0x2, 0x2, 0x92, 0xa0, 0x5, 0xc, 0x7, 
    0xd, 0x93, 0x94, 0xc, 0xb, 0x2, 0x2, 0x94, 0x95, 0x7, 0x14, 0x2, 0x2, 
    0x95, 0xa0, 0x5, 0xc, 0x7, 0xc, 0x96, 0x97, 0xc, 0xa, 0x2, 0x2, 0x97, 
    0x98, 0x7, 0x15, 0x2, 0x2, 0x98, 0xa0, 0x5, 0xc, 0x7, 0xb, 0x99, 0x9a, 
    0xc, 0x9, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x16, 0x2, 0x2, 0x9b, 0xa0, 0x5, 
    0xc, 0x7, 0xa, 0x9c, 0x9d, 0xc, 0x8, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x17, 
    0x2, 0x2, 0x9e, 0xa0, 0x5, 0xc, 0x7, 0x9, 0x9f, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x84, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x18, 0x2, 0x2, 
    0xa5, 0xa6, 0x7, 0x6, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0xc, 0x7, 0x2, 0xa7, 
    0xa8, 0x7, 0x8, 0x2, 0x2, 0xa8, 0xac, 0x7, 0xb, 0x2, 0x2, 0xa9, 0xab, 
    0x5, 0x4, 0x3, 0x2, 0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb1, 0x7, 0xc, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0x10, 0x9, 0x2, 
    0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xc1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x19, 0x2, 0x2, 0xb4, 0xb5, 
    0x7, 0x6, 0x2, 0x2, 0xb5, 0xb6, 0x5, 0xc, 0x7, 0x2, 0xb6, 0xb7, 0x7, 
    0x8, 0x2, 0x2, 0xb7, 0xbb, 0x7, 0xb, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x4, 
    0x3, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbc, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xbf, 0x7, 0xc, 0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x1a, 0x2, 0x2, 0xc3, 0xc7, 0x7, 0xb, 
    0x2, 0x2, 0xc4, 0xc6, 0x5, 0x4, 0x3, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xc, 0x2, 0x2, 0xcb, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x2b, 0x2, 0x2, 0xcd, 0xce, 0x7, 
    0x1b, 0x2, 0x2, 0xce, 0xea, 0x5, 0xc, 0x7, 0x2, 0xcf, 0xd0, 0x7, 0x2b, 
    0x2, 0x2, 0xd0, 0xd1, 0x7, 0x1c, 0x2, 0x2, 0xd1, 0xea, 0x5, 0xc, 0x7, 
    0x2, 0xd2, 0xd3, 0x7, 0x2b, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x1d, 0x2, 0x2, 
    0xd4, 0xea, 0x5, 0xc, 0x7, 0x2, 0xd5, 0xd6, 0x7, 0x2b, 0x2, 0x2, 0xd6, 
    0xd7, 0x7, 0x1e, 0x2, 0x2, 0xd7, 0xea, 0x5, 0xc, 0x7, 0x2, 0xd8, 0xd9, 
    0x7, 0x2b, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x1f, 0x2, 0x2, 0xda, 0xea, 0x5, 
    0xc, 0x7, 0x2, 0xdb, 0xdc, 0x7, 0x2b, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x20, 
    0x2, 0x2, 0xdd, 0xea, 0x5, 0xc, 0x7, 0x2, 0xde, 0xdf, 0x7, 0x2b, 0x2, 
    0x2, 0xdf, 0xea, 0x9, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x9, 0x2, 0x2, 0x2, 
    0xe1, 0xea, 0x7, 0x2b, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x2b, 0x2, 0x2, 0xe3, 
    0xe4, 0x7, 0x23, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0xc, 0x7, 0x2, 0xe5, 0xe6, 
    0x7, 0x24, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x1b, 0x2, 0x2, 0xe7, 0xe8, 0x5, 
    0xc, 0x7, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xe9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xea, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x1e, 0x10, 0x2, 0xec, 0xed, 0x7, 
    0x2b, 0x2, 0x2, 0xed, 0xee, 0x7, 0x1b, 0x2, 0x2, 0xee, 0xf5, 0x5, 0xc, 
    0x7, 0x2, 0xef, 0xf0, 0x7, 0x7, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x2b, 0x2, 
    0x2, 0xf1, 0xf2, 0x7, 0x1b, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0xc, 0x7, 0x2, 
    0xf3, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 
    0x4, 0x2, 0x2, 0xf9, 0x107, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x1c, 
    0xf, 0x2, 0xfb, 0xfc, 0x7, 0x2b, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x23, 0x2, 
    0x2, 0xfd, 0xfe, 0x7, 0x28, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x24, 0x2, 0x2, 
    0xff, 0x102, 0x7, 0x1b, 0x2, 0x2, 0x100, 0x103, 0x5, 0x18, 0xd, 0x2, 
    0x101, 0x103, 0x7, 0x2d, 0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x105, 0x7, 0x4, 0x2, 0x2, 0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 
    0x106, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x106, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x5, 0x1e, 0x10, 0x2, 0x109, 
    0x10e, 0x7, 0x2b, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x7, 0x2, 0x2, 0x10b, 
    0x10d, 0x7, 0x2b, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10d, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 
    0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x4, 0x2, 0x2, 0x112, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x5, 0x1c, 0xf, 0x2, 0x114, 
    0x115, 0x7, 0x2b, 0x2, 0x2, 0x115, 0x116, 0x7, 0x23, 0x2, 0x2, 0x116, 
    0x117, 0x7, 0x28, 0x2, 0x2, 0x117, 0x118, 0x7, 0x24, 0x2, 0x2, 0x118, 
    0x119, 0x7, 0x4, 0x2, 0x2, 0x119, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x113, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xb, 0x2, 0x2, 0x11d, 0x122, 
    0x5, 0x1a, 0xe, 0x2, 0x11e, 0x11f, 0x7, 0x7, 0x2, 0x2, 0x11f, 0x121, 
    0x5, 0x1a, 0xe, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x121, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x7, 0xc, 0x2, 0x2, 0x126, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x7, 0x25, 0x2, 0x2, 0x128, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x128, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12b, 0x9, 0x3, 0x2, 0x2, 0x12b, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x12d, 0x9, 0x4, 0x2, 0x2, 0x12d, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x131, 0x5, 0x1c, 0xf, 0x2, 0x12f, 0x130, 0x7, 0x23, 0x2, 
    0x2, 0x130, 0x132, 0x7, 0x24, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x24, 0x26, 0x35, 0x38, 0x44, 0x48, 0x4d, 0x54, 0x5a, 0x68, 0x6b, 
    0x6f, 0x7f, 0x9f, 0xa1, 0xac, 0xb1, 0xbb, 0xc0, 0xc7, 0xe9, 0xf5, 0x102, 
    0x106, 0x10e, 0x11a, 0x122, 0x128, 0x131, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GramCompParser::Initializer GramCompParser::_init;
