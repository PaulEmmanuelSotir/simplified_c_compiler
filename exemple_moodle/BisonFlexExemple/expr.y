%{
#include "expr.h"
#include <map>
#include <string>
#include <iostream>

extern int yylex(void);
void yyerror(Expression ** e, const char * msg);

%}

%union {
   char * s;
   double d;
   int i;
   Expression * e;
}
%token PLUS MOINS MULT SLASH EXP OPEN CLOSE
%token <s> VAR
%token <d> DOUBLE
%token <i> INT
%type <e> expr

%left MOINS PLUS
%left MULT SLASH
%right EXP

%parse-param {Expression ** e}

%%
main : expr             { *e = $1; }
     ;

expr: DOUBLE            { $$ = new Valeur($1); }
    | INT               { $$ = new Valeur($1); }
    | VAR               { $$ = new Variable($1); free($1); }
    | expr PLUS expr    { $$ = new OperateurPlus($1,$3); }
    | expr MOINS expr   { $$ = new OperateurMoins($1,$3); }
    | expr SLASH expr   { $$ = new OperateurDiv($1,$3); }
    | expr MULT expr    { $$ = new OperateurMul($1,$3); }
    | expr EXP expr     { $$ = new OperateurExp($1,$3); }
    | OPEN expr CLOSE   { $$ = $2; }
    ;
%%


void yyerror(Expression ** e, const char * msg) {
   cout<<msg;
}

int main(void) {
   map<string,double> var;
   Expression * e=0;
   //yydebug = 1;
   yyparse(&e);
   if (e) {
      var["x"] = 1.0;
      var["y"] = 2.0;
      cout<<"Valeur : "<<e->Evaluation(var)<<endl;
      delete e;
   }
   return 0;
}
