#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Variable.h"


namespace  SyntaxModel {

  class AffectationIncrDecr final : public Expression {
    private:
      Variable _var;
  };
}
