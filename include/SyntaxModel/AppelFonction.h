#pragma once
#include <list>

#include "Expression.h"

namespace SyntaxModel {
  class AppelFonction final : public Expression {
    public:
      AppelFonction();
      virtual ~AppelFonction() = default;

    private:
      std::list<Expression> _expressions;
  };
}
