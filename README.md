# PLD COMP - Simplified C compiler (WIP)
*by H4413*  

This is a simplified C compiler written in modern C++ with Antlr4 featuring static analysis and x86 asm target.

## Install and run instructions
You need at least c++14 to build the project. Use the makefile like this : 
- make : compile the project
- make rebuild : launch antlr and create the grammar again, then compile the project
- make clean : clean bin folder
The executable file is then in ./bin/debug/c_compiler

Command to launch the compilation of a file : 
```
./bin/debug/c_compiler [filepath] [-a] [-c]
``` 
Examples : "./bin/debug/c_compiler ./tests/Back/2_putchar.c -c"

## Ecarts au sujet
  Nous avons choisi que notre IR soit plus proche du language assembleur que dans le sujet, ainsi notre CFG est une liste chainée qui contient des basics blocs dans l'ordre dans lequel ils apparaitront dans le fichier assembleur (.s). 

## Ce qui marche et ce qui ne marche pas
  Sur le front, toutes les règles de notre grammaire ont été implémentées : ce qui correspond à tout ce qui a été deandé dans le sujet (variables locales, variables globales, tableaux 1D, if, while, for, fonctions, ...). Les erreurs sont récupérées dans le lexer, le parser et ensuite lors de l'analyse statique (résolution de portée des variables et analyse). Notre analyse statique va plus loin que le sujet le suggère : double déclaration de variables, variables non déclarées, fonctions non déclarées, variables inutilisées. 
  
  Sur le back, l'édition du fichier asm fonctionne pour un main vide, des déclarations uniquement, le putchar et permet de lancer les programmes compilés. Pour les expressions, nous avons encore des bugs sur les registres temporaires nécessaires lors de certaines opérations arithmétiques. Nous pouvons donc générer du code asm avec des registres qui ne sont pas compilable par la suite par gcc. Le if et le while sont gérés mais les fichiers .s générés ne peuvent etre éxecutés ensuite. Seule la structure du code assembleur est générée, les registres temporaires sont remplacés par des registres numérotés. 
