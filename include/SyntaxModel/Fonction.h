#pragma once
#include <iostream>

#include "Identificateur.h"
#include "Declaration.h"
#include "Instruction.h"

class Fonction final
{
public:
  Fonction();
  virtual ~Fonction() = default;

private:
  std::list<Declaration> _declarations;
  std::list<Instruction> _instructions;
  Identificateur _nom;
};
