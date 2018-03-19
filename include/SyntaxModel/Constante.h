#pragma once

#include "SyntaxModel/Expression.h"


namespace SyntaxModel {
  class Constante final : public Expression {
    public:
      Constante();
      virtual ~Constante() = default;
  };
}
