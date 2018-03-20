#include "antlr4-runtime.h"
#include <cstdlib>
#include <iostream>

#include "SyntaxModel/SyntaxModel.h"
#include "grammar/GramCompBaseVisitor.h"
#include "grammar/GramCompLexer.h"
#include "grammar/GramCompParser.h"
#include "visitor.h"

void parse(std::ifstream& fs)
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
}

void compile(std::ifstream& fs, const std::string& target)
{
    // Parse AST from input file
    parse(fs);

    // Static analysis
    // TODO: ...

    // Optimization
    // TODO: ...

    // Compilation to x86 target
    // TODO: ...
}

int main(int argc, char* argv[])
{
    std::string target = "output";
    if (argc < 2) {
        std::cout << "No input file to compile";
        return EXIT_FAILURE;
    } else if (argc >= 3) {
        // Target executable filename
        target = argv[3];
    }

    // Open source file and compile it
    std::ifstream fs;
    fs.open(argv[1], std::fstream::in);
    if (fs.is_open()) {
        std::cout << "### Compiling '" << argv[1] << "' ###" << std::endl;
        compile(fs, target);
        fs.close();
    } else {
        std::cout << "Couldn't read input file '" << argv[1] << "'";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
