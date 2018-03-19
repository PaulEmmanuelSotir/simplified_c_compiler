#pragma once

#include "SyntaxModel/TypesPrimitifs.h"

namespace SyntaxModel {
  class AtomicType {
    public:
      AtomicType(const TypesPrimitifs& type);
      virtual ~AtomicType() = default;

    private:
      TypesPrimitifs _type;
  };
}
