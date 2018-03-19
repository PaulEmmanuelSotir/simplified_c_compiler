#pragma once
#include <list>

#include "Expression.h"

using namespace std;
namespace SyntaxModel {
  class AppelFonction final : public Expression {
    public:
      AppelFonction(const vector<const Expression*>& expressions);
      virtual ~AppelFonction() = default;

    private:
      const vector<const Expression*> _expressions;
  };
}
