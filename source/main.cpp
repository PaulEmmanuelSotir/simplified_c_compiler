#include "antlr4-runtime.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

#include "StaticAnalysis.h"
#include "SyntaxModel/SyntaxModel.h"
#include "Visitor.h"
#include "grammar/GramCompBaseVisitor.h"
#include "grammar/GramCompLexer.h"
#include "grammar/GramCompParser.h"

const SyntaxModel::Program* parse(std::ifstream& fs)
{
    // Stream it to lexer
    std::cout << "\n# Executing lexer\n";
    antlr4::ANTLRInputStream input(fs);
    GramCompLexer lexer(&input);

    // Print tokens
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    // Parse tokens
    std::cout << "\n# Parsing tokens to obtain AST\n";
    GramCompParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.program();
    std::cout << tree->toStringTree(&parser) << std::endl;

    // Build syntaxic model (AST)
    std::cout << "\n# Translate Antlr context AST to SyntaxModel AST with Visitor class\n";
    Visitor v;
    antlrcpp::Any ast = v.visit(tree);

    if (ast.is<SyntaxModel::Program*>()) {
        auto prog = ast.as<SyntaxModel::Program*>();
        std::cout << *prog << std::endl;
        return prog;
    }
    return nullptr;
}

const StaticAnalysis::StaticAnalyser* staticAnalysis(const SyntaxModel::Program* ast)
{
    std::cout << "\n# Solve variable scopes and run static analysis\n";
    auto analyser = new StaticAnalysis::StaticAnalyser(ast);
    analyser->Analyse();
    return analyser;
}

void compile(std::ifstream& fs, const std::string& target)
{
    // Parse AST from input file
    auto program = parse(fs);

    // Static analysis
    auto analyser = staticAnalysis(program);

    if (!analyser->raisedErrors()) {
        // Test expression type resolution (TODO: remove it!!)
        auto exprs = program->getAllChildrenOfType<SyntaxModel::Expression>();
        auto expr_type = (*utils::get_at(exprs, 0))->getExprType(analyser);
        std::cout << expr_type << std::endl;

        // Optimization
        // TODO: ...

        // Compilation to x86 target
        // TODO: ...
    }

    delete program;
    delete analyser;
}

int main(int argc, char* argv[])
{
    std::string target = "output";
    std::string inputFile = "input";

    if (argc < 2) {
        std::cout << "No input file to compile" << std::endl;
        return EXIT_FAILURE;
    }

    int i;
    for (i = 1; i < argc; ++i) {
        //C'est une option
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'a')
                std::cout << "##### -a not implemented #### " << std::endl;
            else if (argv[i][1] == 'c')
                std::cout << "##### -c not implemented #### " << std::endl;
            else if (argv[i][1] == 'o')
                std::cout << "##### -o not implemented #### " << std::endl;
            else
                std::cout << "Unknown option " << argv[i] << std::endl;

        } else
            inputFile = argv[i];
    }

    // Open source file and compile it
    std::ifstream fs;
    fs.open(inputFile, std::fstream::in);
    if (fs.is_open()) {
        std::cout << "### Compiling '" << inputFile << "' ###" << std::endl;
        compile(fs, target);
        fs.close();
    } else {
        std::cout << "Couldn't read input file '" << inputFile << "'" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
