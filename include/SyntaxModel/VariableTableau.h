#pragma once

#include "SyntaxModel/Variable.h"
#include "SyntaxModel/Expression.h"

namespace  SyntaxModel {
  class VariableTableau final : public Variable {
    private :
      Expression* _indice;
  };
}
