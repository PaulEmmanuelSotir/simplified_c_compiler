#!/bin/bash

# Compile grammar using antlr4
echo "Compiling grammar using antlr4"
java -jar ./antlr/antlr-4.7.1-complete.jar ./antlr/GramComp.g4 -Dlanguage=Cpp -visitor -no-listener

# Fix include statements
echo "Fix generated code include statements"
sed -i 's,include "GramCompLexer.h",include "antlr/GramCompLexer.h",g' ./antlr/GramCompLexer.cpp
sed -i 's/include "GramCompParser.h"/include "antlr\/GramCompParser.h"/g' ./antlr/GramCompParser.cpp
sed -i 's/include "GramCompVisitor.h"/include "antlr\/GramCompVisitor.h"/g' ./antlr/GramCompParser.cpp
sed -i 's/include "GramCompVisitor.h"/include "antlr\/GramCompVisitor.h"/g' ./antlr/GramCompVisitor.cpp
sed -i 's/include "GramCompBaseVisitor.h"/include "antlr\/GramCompBaseVisitor.h"/g' ./antlr/GramCompBaseVisitor.cpp
sed -i 's/include "GramCompVisitor.h"/include "antlr\/GramCompVisitor.h"/g' ./antlr/GramCompBaseVisitor.h
sed -i 's/include "GramCompParser.h"/include "antlr\/GramCompParser.h"/g' ./antlr/GramCompVisitor.h

# Move generated source files to their respective directories
echo "Move generated source files to their respective directories"
rm -r ./source/antlr
mkdir -p ./source/antlr
mv ./antlr/GramCompBaseVisitor.cpp ./source/antlr/
mv ./antlr/GramCompLexer.cpp ./source/antlr/
mv ./antlr/GramCompParser.cpp ./source/antlr/
mv ./antlr/GramCompVisitor.cpp ./source/antlr/

rm -r ./include/antlr
mkdir -p ./include/antlr
mv ./antlr/GramCompBaseVisitor.h ./include/antlr/
mv ./antlr/GramCompLexer.h ./include/antlr/
mv ./antlr/GramCompParser.h ./include/antlr/
mv ./antlr/GramCompVisitor.h ./include/antlr/
