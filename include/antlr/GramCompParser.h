
// Generated from .\GramComp.g4 by ANTLR 4.7.1

#pragma once

#include "antlr4-runtime.h"

class GramCompParser : public antlr4::Parser {
public:
    enum {
        T__0 = 1,
        T__1 = 2,
        T__2 = 3,
        T__3 = 4,
        T__4 = 5,
        T__5 = 6,
        T__6 = 7,
        T__7 = 8,
        T__8 = 9,
        T__9 = 10,
        T__10 = 11,
        T__11 = 12,
        T__12 = 13,
        T__13 = 14,
        T__14 = 15,
        T__15 = 16,
        T__16 = 17,
        T__17 = 18,
        T__18 = 19,
        T__19 = 20,
        T__20 = 21,
        T__21 = 22,
        T__22 = 23,
        T__23 = 24,
        T__24 = 25,
        T__25 = 26,
        T__26 = 27,
        T__27 = 28,
        T__28 = 29,
        T__29 = 30,
        T__30 = 31,
        T__31 = 32,
        T__32 = 33,
        T__33 = 34,
        T__34 = 35,
        T__35 = 36,
        T__36 = 37,
        T__37 = 38,
        IDENTIFIER = 39,
        STRING_LITERAL = 40,
        CHAR_LITERAL = 41,
        INTEGER = 42,
        CHAR = 43,
        INT32_T = 44,
        INT64_T = 45
    };

    enum {
        RuleProgramme = 0,
        RuleInstruction = 1,
        RuleInclude = 2,
        RuleFunction = 3,
        RuleArgs = 4,
        RuleFunction_init = 5,
        RuleExpression = 6,
        RuleStructure = 7,
        RuleElse_structure = 8,
        RuleAffectation = 9,
        RuleDefinition = 10,
        RuleDeclaration = 11,
        RuleArray_expr = 12,
        RuleConst_expr = 13,
        RuleAtomic_type = 14,
        RuleType = 15
    };

    GramCompParser(antlr4::TokenStream* input);
    ~GramCompParser();

    virtual std::string getGrammarFileName() const override;
    virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
    virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
    virtual const std::vector<std::string>& getRuleNames() const override;
    virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

    class ProgrammeContext;
    class InstructionContext;
    class IncludeContext;
    class FunctionContext;
    class ArgsContext;
    class Function_initContext;
    class ExpressionContext;
    class StructureContext;
    class Else_structureContext;
    class AffectationContext;
    class DefinitionContext;
    class DeclarationContext;
    class Array_exprContext;
    class Const_exprContext;
    class Atomic_typeContext;
    class TypeContext;

    class ProgrammeContext : public antlr4::ParserRuleContext {
    public:
        ProgrammeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<IncludeContext*> include();
        IncludeContext* include(size_t i);
        std::vector<DeclarationContext*> declaration();
        DeclarationContext* declaration(size_t i);
        std::vector<DefinitionContext*> definition();
        DefinitionContext* definition(size_t i);
        std::vector<FunctionContext*> function();
        FunctionContext* function(size_t i);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ProgrammeContext* programme();

    class InstructionContext : public antlr4::ParserRuleContext {
    public:
        InstructionContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        InstructionContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(InstructionContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Expression_instrContext : public InstructionContext {
    public:
        Expression_instrContext(InstructionContext* ctx);

        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class BreakContext : public InstructionContext {
    public:
        BreakContext(InstructionContext* ctx);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class FucntioncallContext : public InstructionContext {
    public:
        FucntioncallContext(InstructionContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ContinueContext : public InstructionContext {
    public:
        ContinueContext(InstructionContext* ctx);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Semicolon_instrContext : public InstructionContext {
    public:
        Semicolon_instrContext(InstructionContext* ctx);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Structure_instrContext : public InstructionContext {
    public:
        Structure_instrContext(InstructionContext* ctx);

        StructureContext* structure();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ReturnContext : public InstructionContext {
    public:
        ReturnContext(InstructionContext* ctx);

        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    InstructionContext* instruction();

    class IncludeContext : public antlr4::ParserRuleContext {
    public:
        IncludeContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        IncludeContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(IncludeContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class IncludeCrochContext : public IncludeContext {
    public:
        IncludeCrochContext(IncludeContext* ctx);

        antlr4::tree::TerminalNode* STRING_LITERAL();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IncludeGuillContext : public IncludeContext {
    public:
        IncludeGuillContext(IncludeContext* ctx);

        antlr4::tree::TerminalNode* STRING_LITERAL();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IncludeContext* include();

    class FunctionContext : public antlr4::ParserRuleContext {
    public:
        FunctionContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        FunctionContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(FunctionContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Function_defContext : public FunctionContext {
    public:
        Function_defContext(FunctionContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        TypeContext* type();
        ArgsContext* args();
        std::vector<Function_initContext*> function_init();
        Function_initContext* function_init(size_t i);
        std::vector<InstructionContext*> instruction();
        InstructionContext* instruction(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    FunctionContext* function();

    class ArgsContext : public antlr4::ParserRuleContext {
    public:
        ArgsContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        ArgsContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(ArgsContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Args_listContext : public ArgsContext {
    public:
        Args_listContext(ArgsContext* ctx);

        std::vector<TypeContext*> type();
        TypeContext* type(size_t i);
        std::vector<antlr4::tree::TerminalNode*> IDENTIFIER();
        antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Void_argContext : public ArgsContext {
    public:
        Void_argContext(ArgsContext* ctx);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ArgsContext* args();

    class Function_initContext : public antlr4::ParserRuleContext {
    public:
        Function_initContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        Function_initContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(Function_initContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class Functioninit_defContext : public Function_initContext {
    public:
        Functioninit_defContext(Function_initContext* ctx);

        DefinitionContext* definition();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Functioninit_declContext : public Function_initContext {
    public:
        Functioninit_declContext(Function_initContext* ctx);

        DeclarationContext* declaration();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    Function_initContext* function_init();

    class ExpressionContext : public antlr4::ParserRuleContext {
    public:
        ExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        ExpressionContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(ExpressionContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class InfContext : public ExpressionContext {
    public:
        InfContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IdentifierContext : public ExpressionContext {
    public:
        IdentifierContext(ExpressionContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MinusContext : public ExpressionContext {
    public:
        MinusContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultContext : public ExpressionContext {
    public:
        MultContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Affect_epxrContext : public ExpressionContext {
    public:
        Affect_epxrContext(ExpressionContext* ctx);

        AffectationContext* affectation();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class StringContext : public ExpressionContext {
    public:
        StringContext(ExpressionContext* ctx);

        antlr4::tree::TerminalNode* STRING_LITERAL();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class SupequalContext : public ExpressionContext {
    public:
        SupequalContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class InfequalContext : public ExpressionContext {
    public:
        InfequalContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IntegerContext : public ExpressionContext {
    public:
        IntegerContext(ExpressionContext* ctx);

        antlr4::tree::TerminalNode* INTEGER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ParenthesisContext : public ExpressionContext {
    public:
        ParenthesisContext(ExpressionContext* ctx);

        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class PlusContext : public ExpressionContext {
    public:
        PlusContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class SupContext : public ExpressionContext {
    public:
        SupContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DivContext : public ExpressionContext {
    public:
        DivContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class EqualContext : public ExpressionContext {
    public:
        EqualContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class NotContext : public ExpressionContext {
    public:
        NotContext(ExpressionContext* ctx);

        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class CharContext : public ExpressionContext {
    public:
        CharContext(ExpressionContext* ctx);

        antlr4::tree::TerminalNode* CHAR_LITERAL();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Minus1Context : public ExpressionContext {
    public:
        Minus1Context(ExpressionContext* ctx);

        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DifferentContext : public ExpressionContext {
    public:
        DifferentContext(ExpressionContext* ctx);

        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExpressionContext* expression();
    ExpressionContext* expression(int precedence);
    class StructureContext : public antlr4::ParserRuleContext {
    public:
        StructureContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        StructureContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(StructureContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class WhileContext : public StructureContext {
    public:
        WhileContext(StructureContext* ctx);

        ExpressionContext* expression();
        std::vector<InstructionContext*> instruction();
        InstructionContext* instruction(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IfContext : public StructureContext {
    public:
        IfContext(StructureContext* ctx);

        ExpressionContext* expression();
        std::vector<InstructionContext*> instruction();
        InstructionContext* instruction(size_t i);
        Else_structureContext* else_structure();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StructureContext* structure();

    class Else_structureContext : public antlr4::ParserRuleContext {
    public:
        Else_structureContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        Else_structureContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(Else_structureContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class ElseContext : public Else_structureContext {
    public:
        ElseContext(Else_structureContext* ctx);

        std::vector<InstructionContext*> instruction();
        InstructionContext* instruction(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    Else_structureContext* else_structure();

    class AffectationContext : public antlr4::ParserRuleContext {
    public:
        AffectationContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        AffectationContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(AffectationContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class PourcentmentationContext : public AffectationContext {
    public:
        PourcentmentationContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class Affect_exprContext : public AffectationContext {
    public:
        Affect_exprContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultmentationContext : public AffectationContext {
    public:
        MultmentationContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IncrementationContext : public AffectationContext {
    public:
        IncrementationContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IncunairepostContext : public AffectationContext {
    public:
        IncunairepostContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DividementationContext : public AffectationContext {
    public:
        DividementationContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DecrementationContext : public AffectationContext {
    public:
        DecrementationContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class IncunairepreContext : public AffectationContext {
    public:
        IncunairepreContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class TableContext : public AffectationContext {
    public:
        TableContext(AffectationContext* ctx);

        antlr4::tree::TerminalNode* IDENTIFIER();
        std::vector<ExpressionContext*> expression();
        ExpressionContext* expression(size_t i);
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AffectationContext* affectation();

    class DefinitionContext : public antlr4::ParserRuleContext {
    public:
        DefinitionContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        DefinitionContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(DefinitionContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class DeftableContext : public DefinitionContext {
    public:
        DeftableContext(DefinitionContext* ctx);

        Atomic_typeContext* atomic_type();
        antlr4::tree::TerminalNode* IDENTIFIER();
        antlr4::tree::TerminalNode* INTEGER();
        Array_exprContext* array_expr();
        antlr4::tree::TerminalNode* STRING_LITERAL();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DefineContext : public DefinitionContext {
    public:
        DefineContext(DefinitionContext* ctx);

        TypeContext* type();
        antlr4::tree::TerminalNode* IDENTIFIER();
        ExpressionContext* expression();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DefinitionContext* definition();

    class DeclarationContext : public antlr4::ParserRuleContext {
    public:
        DeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        DeclarationContext()
            : antlr4::ParserRuleContext()
        {
        }
        void copyFrom(DeclarationContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class DecltableContext : public DeclarationContext {
    public:
        DecltableContext(DeclarationContext* ctx);

        Atomic_typeContext* atomic_type();
        antlr4::tree::TerminalNode* IDENTIFIER();
        antlr4::tree::TerminalNode* INTEGER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DeclareContext : public DeclarationContext {
    public:
        DeclareContext(DeclarationContext* ctx);

        TypeContext* type();
        antlr4::tree::TerminalNode* IDENTIFIER();
        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DeclarationContext* declaration();

    class Array_exprContext : public antlr4::ParserRuleContext {
    public:
        Array_exprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<Const_exprContext*> const_expr();
        Const_exprContext* const_expr(size_t i);

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    Array_exprContext* array_expr();

    class Const_exprContext : public antlr4::ParserRuleContext {
    public:
        Const_exprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* INTEGER();
        antlr4::tree::TerminalNode* CHAR();
        antlr4::tree::TerminalNode* CHAR_LITERAL();

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    Const_exprContext* const_expr();

    class Atomic_typeContext : public antlr4::ParserRuleContext {
    public:
        Atomic_typeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CHAR();
        antlr4::tree::TerminalNode* INT32_T();
        antlr4::tree::TerminalNode* INT64_T();

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    Atomic_typeContext* atomic_type();

    class TypeContext : public antlr4::ParserRuleContext {
    public:
        TypeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        Atomic_typeContext* atomic_type();

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TypeContext* type();

    virtual bool sempred(antlr4::RuleContext* _localctx, size_t ruleIndex, size_t predicateIndex) override;
    bool expressionSempred(ExpressionContext* _localctx, size_t predicateIndex);

private:
    static std::vector<antlr4::dfa::DFA> _decisionToDFA;
    static antlr4::atn::PredictionContextCache _sharedContextCache;
    static std::vector<std::string> _ruleNames;
    static std::vector<std::string> _tokenNames;

    static std::vector<std::string> _literalNames;
    static std::vector<std::string> _symbolicNames;
    static antlr4::dfa::Vocabulary _vocabulary;
    static antlr4::atn::ATN _atn;
    static std::vector<uint16_t> _serializedATN;

    struct Initializer {
        Initializer();
    };
    static Initializer _init;
};
