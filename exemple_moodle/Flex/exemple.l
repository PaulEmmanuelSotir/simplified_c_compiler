%{
#include <stdlib.h>
#include "types.h"

#define YY_DECL int yylex_mine(Param * param)
%}
%option noyywrap
entier [0-9]+
flottant [0-9]+\.[0-9]*
%%
{entier}    { param->ival = atoi(yytext); return ENTIER; }
{flottant}  { param->fval = atof(yytext); return FLOTTANT; }
.*          { return ERREUR; }
%%

