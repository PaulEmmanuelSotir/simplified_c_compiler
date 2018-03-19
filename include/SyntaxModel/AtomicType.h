#pragma once

#include "TypesPrimitifs.h"

namespace SyntaxModel {
  class AtomicType {
    public:
      AtomicType(const TypesPrimitifs& type);
      virtual ~AtomicType() = default;

    private:
      TypesPrimitifs _type;
  };
}
