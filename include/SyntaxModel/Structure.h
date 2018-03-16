
#pragma once
#include <list>

#include "Instruction.h"
#include "Expression.h"

class Structure : public Instruction
{
public:
  Structure();
  ~Structure();

private:
  Expression _condition;
  std::list<Instruction> _instructions;
};
