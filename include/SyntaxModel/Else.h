#pragma once

#include <list>
#include "Instruction.h"

class Else final
{
public:
  Else();

private:
  std::list<Instruction> _instructions;
};
