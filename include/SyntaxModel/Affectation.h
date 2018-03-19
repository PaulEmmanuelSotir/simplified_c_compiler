#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Variable.h"
#include "SyntaxModel/OperateursAffectation.h"

namespace  SyntaxModel {

  class Affectation final : public Expression {
    private:
      Expression _expression;
      Variable _var;
      OperateursAffectation _operateur;
  };
}
