#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/AtomicType.h"
#include "SyntaxModel/Identificateur.h"

namespace  SyntaxModel {
  class Variable : public Expression{
    public :

    private :
      AtomicType _type;
      Identificateur _name;

  };
}
