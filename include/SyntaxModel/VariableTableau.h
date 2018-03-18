#pragma once

#include "SyntaxModelVariable.h"

namespace  SyntaxModel {
  class VariableTableau : public Variable{
    private :
      Expression* _indice;
  }
}
