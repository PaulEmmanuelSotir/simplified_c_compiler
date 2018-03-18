#pragma once

#include "OperateursBinaires.h"
#include "Expression.h"

namespace SyntaxModel {
  class OperationBinaire final : public Expression {
    public:
      OperationBinaire();
      virtual ~OperationBinaire() = default;

    private:
      Expression _expressionGauche;
      Expression _expressionDroite;
      OperateursBinaires _operateur;
  };
}
