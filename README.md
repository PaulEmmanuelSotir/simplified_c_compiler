# PLD COMP - Simplified C compiler
*by H4413*

Ce projet est un compilateur pour un language C simplifié, écrit en c++ avec Antlr4. La cible est une architecture x86.
## Instalation et lancement
Vous devez utiliser au minimum c++14. Le makefile propose ces options :
- make : compile le projet
- make rebuild : lance la génération de la grammaire puis compile le projet
- make clean : nettoie le dossier bin
L'éxecutable se trouve ensuite dans ce dossier à partir de la racine du projet : ```./bin/debug/c_compiler```

**Compilation pour Mac : il faut créer un fichier .MAC à la racine du projet pour que gcc puisse linker les bonnes librairies Antlr.**

Commande pour lancer le programme une fois compilé :
```
./bin/debug/c_compiler [filepath] [-a] [-c]
```
Exemples : ```./bin/debug/c_compiler ./tests/Back/2_putchar.c -c```

## Ecarts au sujet
  Nous avons choisi que notre IR soit plus proche du language assembleur que dans le sujet, ainsi notre CFG est une liste chainée qui contient des basics blocs dans l'ordre dans lequel ils apparaitront dans le fichier assembleur (.s).

## Ce qui marche et ce qui ne marche pas
  Sur le front, toutes les règles de notre grammaire ont été implémentées : ce qui correspond à tout ce qui a été deandé dans le sujet (variables locales, variables globales, tableaux 1D, if, while, for, fonctions, ...). Les erreurs sont récupérées dans le lexer, le parser et ensuite lors de l'analyse statique (résolution de portée des variables et analyse). Notre analyse statique va plus loin que le sujet le suggère : double déclaration de variables, variables non déclarées, fonctions non déclarées, variables inutilisées.

  Sur le back, l'édition du fichier asm fonctionne pour tous les programmes du dossier "./tests/Demo/back" et permet de lancer les programmes compilés (main vide, declarations, fonctions, if, while, mélange des précédents). Pour les expressions, nous avons encore des problèmes sur les registres temporaires lors de certaines opérations arithmétiques, ce qui peut dans certains cas mener à des erreurs.

## Lancement des tests

Pour lancer les tests, plusieurs scripts sont disponibles :

 -  ```./tests-front.sh``` : Lance les tests avec des erreur de syntaxe, sémantiques et de lexer.
 - ```./tests-front-valid.sh``` : Lance les tests avec des programmes valides pour le front (environ 50 tests).
 - ```./tests-back.sh``` : Lance les tests pour le back-end et la génération de code assembleur.

**Pour pouvoir avoir un affichage en mode debug et observer ce qui se passe lors des différentes étapes de la compilation, vous pouvez décommenter la ligne ```//#define DEBUG``` au début du fichier main.cpp, puis relancer la compilation avec make**
