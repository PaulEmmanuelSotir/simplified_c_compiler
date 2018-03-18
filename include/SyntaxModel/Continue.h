#pragma once

#include "Instruction.h"


namespace SyntaxModel {
  class Continue final : public Instruction {
    public:
      Continue();
      virtual ~Continue() = default;
  };
}
