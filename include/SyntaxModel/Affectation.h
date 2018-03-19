#pragma once

#include "Expression.h"
#include "Variable.h"
#include "OperateursAffectation.h"

namespace  SyntaxModel {

  class Affectation final : public Expression {
    public:
      Affectation(const OperateursAffectation& operateur, const Variable& var, const Expression& expression);
      virtual ~Affectation() = default;
    private:
      Expression _expression;
      Variable _var;
      OperateursAffectation _operateur;
  };
}
