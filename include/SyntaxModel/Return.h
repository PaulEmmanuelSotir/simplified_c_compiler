#pragma once

#include "Expression.h"
#include "Instruction.h"


namespace SyntaxModel {
  class Return final : public Instruction {
    public:
      Return();
      virtual ~Return() = default;

    private:
      Expression _expression;
  };
}
