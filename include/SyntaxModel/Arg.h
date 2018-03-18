#pragma once

#include "Identificateur.h"
#include "Type.h"

namespace SyntaxModel {
  class Arg final {
    public:
      Arg();
      virtual ~Arg() = default;

    private:
      Type _type;
      Identificateur _nom;
  };
}
