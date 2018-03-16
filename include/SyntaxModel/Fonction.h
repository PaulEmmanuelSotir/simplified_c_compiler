#pragma once

#include <iostream>
#include "Identificateur.h"
using namespace std;

class Fonction {
public:
  Fonction();
  ~Fonction();
private:
  list<Declaration> declarations;
  list<Instruction> instructions;
  Identificateur nom;
};
