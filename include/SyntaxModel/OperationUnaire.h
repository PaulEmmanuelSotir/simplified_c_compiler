#pragma once

#include "SyntaxModel/OperateursUnaires.h"
#include "SyntaxModel/Expression.h"

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
