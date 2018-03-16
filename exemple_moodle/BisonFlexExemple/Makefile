default:
	flex expr.l
	bison -v -d expr.y
	g++ -DYYDEBUG -g -o expr expr.cpp lex.yy.c expr.tab.c
