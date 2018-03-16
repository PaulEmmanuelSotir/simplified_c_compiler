#ifndef _EXPR_H
#define _EXPR_H

#include <string>
#include <map>
using namespace std;

typedef map<string,double> Vars;

class Expression {
   public:
      Expression();
      virtual ~Expression();
      virtual double Evaluation(const Vars & variables) = 0;
};

class Valeur: public Expression {
   // une expression composée uniquement d'une valeur double
   public:
      Valeur(int val);
      Valeur(double val);
      ~Valeur();
      double Evaluation(const Vars & variables);
   protected:
      double valeur;
};

class Variable: public Expression {
   // une expression composée uniquement d'une variable
   public:
      Variable(string n);
      ~Variable();
      double Evaluation(const Vars & variables);
   protected:
      string nom;
};

class OperateurBinaire: public Expression {
   // un opérateur binaire générique, pour l'implémenter, il faut 
   // implémenter la méthode operation()
   public:
      OperateurBinaire(Expression * g, Expression * d);
      ~OperateurBinaire();
      double Evaluation(const Vars & variables);
   protected:
      virtual double operation(double g, double d) = 0;
      Expression * gauche;
      Expression * droite;
};

class OperateurPlus: public OperateurBinaire {
   public:
      OperateurPlus(Expression * g, Expression * d);
      ~OperateurPlus();
   protected:
      double operation(double g, double d);
};

class OperateurMoins: public OperateurBinaire {
   public:
      OperateurMoins(Expression * g, Expression * d);
      ~OperateurMoins();
   protected:
      double operation(double g, double d);
};

class OperateurDiv: public OperateurBinaire {
   public:
      OperateurDiv(Expression * g, Expression * d);
      ~OperateurDiv();
   protected:
      double operation(double g, double d);
};

class OperateurMul: public OperateurBinaire {
   public:
      OperateurMul(Expression * g, Expression * d);
      ~OperateurMul();
   protected:
      double operation(double g, double d);
};

class OperateurExp: public OperateurBinaire {
   public:
      OperateurExp(Expression * g, Expression * d);
      ~OperateurExp();
   protected:
      double operation(double g, double d);
};

#endif
