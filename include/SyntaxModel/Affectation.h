#pragma once

#include "Expression.h"
#include "Variable.h"
#include "OperateursAffectation.h"

namespace  SyntaxModel {

  class Affectation final : public Expression {
    private:
      Expression _expression;
      Variable _var;
      OperateursAffectation _operateur;
  };
}
