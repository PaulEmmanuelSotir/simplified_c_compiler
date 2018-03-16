
#pragma once

#include "Instruction.h"
#include "Expression.h"
#include <list>

class Structure : public Instruction {
  Structure();
  ~Structure();
private:
  Expression condition;
  list<Instruction> instructions;
};
