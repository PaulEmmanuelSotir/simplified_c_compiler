#pragma once

#include "SyntaxModel/Identifier.h"
#include "SyntaxModel/Type.h"

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
