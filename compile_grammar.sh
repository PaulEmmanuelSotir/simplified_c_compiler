#!/bin/bash

# Compile grammar using antlr4
echo "Compiling grammar using antlr4"
java -jar ./antlr/antlr-4.7.1-complete.jar ./antlr/GramComp.g4 -Dlanguage=Cpp -visitor -no-listener

# Fix include statements
echo "Fix generated code include statements"
sed -i 's,include "GramCompLexer.h",include "grammar/GramCompLexer.h",g' ./antlr/GramCompLexer.cpp
sed -i 's/include "GramCompParser.h"/include "grammar\/GramCompParser.h"/g' ./antlr/GramCompParser.cpp
sed -i 's/include "GramCompVisitor.h"/include "grammar\/GramCompVisitor.h"/g' ./antlr/GramCompParser.cpp
sed -i 's/include "GramCompVisitor.h"/include "grammar\/GramCompVisitor.h"/g' ./antlr/GramCompVisitor.cpp
sed -i 's/include "GramCompBaseVisitor.h"/include "grammar\/GramCompBaseVisitor.h"/g' ./antlr/GramCompBaseVisitor.cpp
sed -i 's/include "GramCompVisitor.h"/include "grammar\/GramCompVisitor.h"/g' ./antlr/GramCompBaseVisitor.h
sed -i 's/include "GramCompParser.h"/include "grammar\/GramCompParser.h"/g' ./antlr/GramCompVisitor.h

# Move generated source files to their respective directories
echo "Move generated source files to their respective directories"
rm -r ./source/grammar
mkdir -p ./source/grammar
mv ./antlr/GramCompBaseVisitor.cpp ./source/grammar/
mv ./antlr/GramCompLexer.cpp ./source/grammar/
mv ./antlr/GramCompParser.cpp ./source/grammar/
mv ./antlr/GramCompVisitor.cpp ./source/grammar/

rm -r ./include/grammar
mkdir -p ./include/grammar
mv ./antlr/GramCompBaseVisitor.h ./include/grammar/
mv ./antlr/GramCompLexer.h ./include/grammar/
mv ./antlr/GramCompParser.h ./include/grammar/
mv ./antlr/GramCompVisitor.h ./include/grammar/
