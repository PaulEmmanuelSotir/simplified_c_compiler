#pragma once

#include "SyntaxModel/AtomicType.h"

namespace SyntaxModel {
  class Type final : public AtomicType {
    public:
      Type();
      virtual ~Type() = default;
  };
}
