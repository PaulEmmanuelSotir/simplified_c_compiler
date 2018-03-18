#pragma once

#include "Instruction.h"

namespace SyntaxModel {
  class Break final : public Instruction {
    public:
      Break();
      virtual ~Break() = default;
  };
}
