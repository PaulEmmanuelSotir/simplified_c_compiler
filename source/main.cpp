#include "antlr4-runtime.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

#include "IR/IR.h"
#include "StaticAnalysis.h"
#include "SyntaxModel/SyntaxModel.h"
#include "Visitor.h"
#include "grammar/GramCompBaseVisitor.h"
#include "grammar/GramCompLexer.h"
#include "grammar/GramCompParser.h"

using namespace std;

//#define DEBUG

const SyntaxModel::Program* parse(ifstream& fs)
{
    // Stream it to lexer
#ifdef DEBUG
    cout << "# Executing lexer" << endl;
#endif
    antlr4::ANTLRInputStream input(fs);
    GramCompLexer lexer(&input);

    // Print tokens
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    if(lexer.getNumberOfSyntaxErrors() > 0) {
        cout << "Lexer errors : " << lexer.getNumberOfSyntaxErrors() << endl;
        return nullptr;
    }
#ifdef DEBUG
    for (auto token : tokens.getTokens()) {
        cout << token->toString() << endl;
    }

    // Parse tokens
    cout << "# Parsing tokens to obtain AST" << endl;
#endif
    GramCompParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.program();
#ifdef DEBUG
    cout << tree->toStringTree(&parser) << endl;
#endif
    if(parser.getNumberOfSyntaxErrors() > 0) {
        cout << "Parser errors : " << parser.getNumberOfSyntaxErrors() << endl;
        return nullptr;
    }

    // Build syntaxic model (AST)
#ifdef DEBUG
    cout << "# Translate Antlr context AST to SyntaxModel AST with Visitor class" << endl;
#endif
    Visitor v;
    antlrcpp::Any ast = v.visit(tree);
    if (ast.is<SyntaxModel::Program*>()) {
        auto prog = ast.as<SyntaxModel::Program*>();
#ifdef DEBUG
        cout << *prog << endl;
#endif
        return prog;
    }
    return nullptr;
}

const StaticAnalysis::StaticAnalyser* staticAnalysis(const SyntaxModel::Program* ast)
{
    cout << "# Solve variable scopes and run static analysis" << endl;
    auto analyser = new StaticAnalysis::StaticAnalyser(ast);
    analyser->Analyse();
    return analyser;
}

int main(int argc, char* argv[])
{
    string target = "output.s";
    string inputFile = "input.c";
    bool staticA = false;
    bool staticC = false;

    if (argc < 2) {
        cout << "No input file to compile" << endl;
        return EXIT_FAILURE;
    }

    int i;
    for (i = 1; i < argc; ++i) {
        //C'est une option
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'a') {
                //cout << "##### -a not implemented #### " << endl;
                staticA = true;
            } else if (argv[i][1] == 'c')
                //cout << "##### -c not implemented #### " << endl;
                staticC = true;
            else if (argv[i][1] == 'o')
                cout << "##### -o not implemented #### " << endl;
            else
                cout << "Unknown option " << argv[i] << endl;
        } else
            inputFile = argv[i];
    }

    // Open source file and compile it
    ifstream fs;
    fs.open(inputFile, fstream::in);
    const SyntaxModel::Program* program;
    if (fs.is_open()) {
        cout << "### Compiling '" << inputFile << "' ###" << endl;
        program = parse(fs);
        if(program == nullptr)
            return EXIT_FAILURE;
        fs.close();
    } else {
        cout << "Couldn't read input file '" << inputFile << "'" << endl;
        return EXIT_FAILURE;
    }

    if (staticA) {
        auto analyser = staticAnalysis(program);
        delete analyser;
    }

    if (staticC) {
        auto analyser = staticAnalysis(program);

        cout << "### Generating assembly ###" << endl;
        auto cfg = IR::ControlFlowGraph(program, analyser, target);
        delete analyser;
    }

    delete program;

    return EXIT_SUCCESS;
}
