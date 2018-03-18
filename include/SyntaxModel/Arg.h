#pragma once

#include "Identifier.h"
#include "Type.h"

namespace SyntaxModel {
  class Arg final {
    public:
      Arg();
      virtual ~Arg() = default;

    private:
      Type _type;
      Identifier _nom;
  };
}
