#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/AtomicType.h"
#include "SyntaxModel/Identifier.h"

namespace  SyntaxModel {
  class Variable : public Expression {
    public:
      Variable();
      virtual ~Variable();

    private:
      AtomicType _type;
      Identifier _name;
  };
}
