#pragma once

#include <iostream>
#include "Identificateur.h"
using namespace std;

class Declaration : public Instruction {
public:
  Declaration();
  ~Declaration();
private:
  Identificateur nom;
};
