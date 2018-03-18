#pragma once

#include "OperateursUnaires.h"
#include "Expression.h"

namespace SyntaxModel {
  class OperationUnaire final : public Expression {
    public:
      OperationUnaire();
      virtual ~OperationUnaire() = default;

    private:
      Expression _expression;
      OperateursUnaires _operateur;
  };
}
