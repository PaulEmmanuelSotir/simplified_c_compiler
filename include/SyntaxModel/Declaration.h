#pragma once

#include "Identificateur.h"
#include "Instruction.h"

class Declaration final : public Instruction
{
public:
  Declaration();
  virtual ~Declaration() = default;

private:
  Identificateur _nom;
};
