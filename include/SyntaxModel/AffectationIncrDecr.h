#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Variable.h"


namespace  SyntaxModel {

  class AffectationIncrDecr final : public Expression {
  public:
    AffectationIncrDecr(const Variable& var);
    virtual ~AffectationIncrDecr() = default;
    private:
      Variable _var;
  };
}
