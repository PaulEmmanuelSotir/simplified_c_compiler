#pragma once

#include "SyntaxModel/TypesPrimitifs.h"

namespace SyntaxModel {
  class AtomicType {
    public:
      AtomicType();
      virtual ~AtomicType() = default;

    private:
      TypesPrimitifs _type;
  };
}
