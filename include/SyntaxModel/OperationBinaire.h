#pragma once

#include "SyntaxModel/OperateursBinaires.h"
#include "SyntaxModel/Expression.h"

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
