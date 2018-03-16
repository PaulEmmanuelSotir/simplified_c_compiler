#include "expr.h"
#include <cmath>

Expression::Expression() {}
Expression::~Expression() {}

Valeur::Valeur(int val) {
   valeur = val;
}

Valeur::Valeur(double val) {
   valeur = val;
}

Valeur::~Valeur() {}

double Valeur::Evaluation(const Vars & variables) {
   return valeur;
}

Variable::Variable(string n) {
   nom = n;
}

Variable::~Variable() { }

double Variable::Evaluation(const Vars & variables) {
   Vars::const_iterator var = variables.find(nom);
   if (var!=variables.end()) {
      return (*var).second;
   } else {
      return .0;
   }
}

OperateurBinaire::OperateurBinaire(Expression * g, Expression * d) {
   gauche = g;
   droite = d;
}

OperateurBinaire::~OperateurBinaire() {
   delete gauche;
   delete droite;
}

double OperateurBinaire::Evaluation(const Vars & variables) {
   double valg,vald;
   valg = gauche->Evaluation(variables);
   vald = droite->Evaluation(variables);
   return operation(valg,vald);
}

OperateurPlus::OperateurPlus(Expression * g, Expression * d) : OperateurBinaire(g,d) {
}

OperateurPlus::~OperateurPlus() {
}

double OperateurPlus::operation(double g, double d) {
   return g+d;
}

OperateurMoins::OperateurMoins(Expression * g, Expression * d) : OperateurBinaire(g,d) { } 
OperateurMoins::~OperateurMoins() { }

double OperateurMoins::operation(double g, double d) {
   return g-d;
}


OperateurDiv::OperateurDiv(Expression * g, Expression * d) : OperateurBinaire(g,d) { } 
OperateurDiv::~OperateurDiv() { }

double OperateurDiv::operation(double g, double d) {
   return g/d;
}

OperateurMul::OperateurMul(Expression * g, Expression * d) : OperateurBinaire(g,d) { } 
OperateurMul::~OperateurMul() { }

double OperateurMul::operation(double g, double d) {
   return g*d;
}

OperateurExp::OperateurExp(Expression * g, Expression * d) : OperateurBinaire(g,d) { } 
OperateurExp::~OperateurExp() { }

double OperateurExp::operation(double g, double d) {
   return pow(g,d);
}
