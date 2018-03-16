#ifndef TYPES_H
#define TYPES_H

typedef union {
int ival;
float fval;
} Param;

typedef enum {
   ENTIER=1, FLOTTANT, ERREUR
} Token;

#endif
