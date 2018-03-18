#pragma once

#include "Variable.h"
#include "Expression.h"

namespace  SyntaxModel {
  class VariableTableau final : public Variable {
    private :
      Expression* _indice;
  };
}
