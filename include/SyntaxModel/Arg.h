#pragma once

#include "Identifier.h"
#include "Type.h"

namespace SyntaxModel {
  class Arg final {
    public:
      Arg(const Type& type, const Identifier& id);
      virtual ~Arg() = default;

    private:
      Type _type;
      Identifier _nom;
  };
}
