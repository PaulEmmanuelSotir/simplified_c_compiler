%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"
#include "expr.tab.h"
%}
%option noyywrap
digit    [0-9]
ident    [a-zA-Z]+
%%
{digit}+"."{digit}* { yylval.d = atof(yytext); return DOUBLE; }
{digit}+            { yylval.i = atoi(yytext); return INT; }
{ident}             { yylval.s = strdup(yytext); return VAR; }
"+"                 { return PLUS; }
"-"                 { return MOINS; }
"/"                 { return SLASH; }
"*"                 { return MULT; }
"^"                 { return EXP; }
"("                 { return OPEN; }
")"                 { return CLOSE; }
.                   { printf("Caractère non attendu : %c\n",*yytext); }
%%
