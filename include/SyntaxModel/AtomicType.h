#pragma once

#include "TypesPrimitifs.h"

namespace SyntaxModel {
  class AtomicType {
    public:
      AtomicType();
      virtual ~AtomicType() = default;

    private:
      TypesPrimitifs _type;
  };
}
