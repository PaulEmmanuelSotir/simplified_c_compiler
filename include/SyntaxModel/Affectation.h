#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Variable.h"
#include "SyntaxModel/OperateursAffectation.h"

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
