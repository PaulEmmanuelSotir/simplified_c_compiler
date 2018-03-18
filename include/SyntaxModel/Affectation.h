#pragma once

#include "SyntaxModel/Expression.h"
#include "SyntaxModel/Variable.h"

namespace  SyntaxModel {
  enum OperateursAffectation{"=","+=","-=","/=","*=","%=","++","--"};

  class Affectation : public Expression{
    public :

    private :
      Expression _valeur;
      Variable _var;
  };
}
