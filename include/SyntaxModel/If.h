#pragma once
#include <optional>

#include "Structure.h"
#include "Else.h"

class If final : public Structure
{
public:
  If();
  virtual ~If() = default;

private:
  Else _clauseElse;
};
