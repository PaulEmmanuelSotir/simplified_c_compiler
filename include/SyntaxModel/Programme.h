#pragma once

#include <iostream>
#include <list>
#include <map>
#include "Declaration.h"
#include "Fonction.h"

using namespace std;

class Programme
{
public:
  Programme();
  ~Programme();
private:
  list<Fonction *> fonctions;
  list<Declaration *>declarations;

};
