#include "types.h"
#include <stdio.h>

int yylex_mine(Param* param);

int main(void) {
   Param p;
   Token t;
   while ((t=yylex_mine(&p)))
   {
      switch(t) {
         case ENTIER:
            printf("Valeur entière : %d\n",p.ival);
            break;
         case FLOTTANT:
            printf("Valeur flottante : %f\n",p.fval);
            break;
         default:
            printf("Erreur !\n");
      }
   }
   return 0;
}
