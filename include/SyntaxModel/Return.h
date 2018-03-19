#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Instruction.h"


namespace SyntaxModel {
  class Return final : public Instruction {
    public:
      Return();
      virtual ~Return() = default;

    private:
      Expression _expression;
  };
}
