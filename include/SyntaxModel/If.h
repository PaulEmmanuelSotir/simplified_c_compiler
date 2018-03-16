#pragma once

#include "Structure.h"
#include "Else.h"

class If : public Structure {
  If();
  ~If();
  private:
    Else clauseElse;
};
