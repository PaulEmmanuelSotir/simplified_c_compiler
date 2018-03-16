#ifndef _AEF_H
#define _AEF_H

#include <set>
#include <list>
#include <map>
#include <ostream>
#include <string>

using namespace std;

typedef int Etat; // un état est représenté par un entier
typedef set<Etat> Etats; // ensemble d'états de l'automate
typedef map<unsigned char,Etats> Mapping; // mapping caractère -> ensemble d'états
typedef map<int,Mapping> Transitions; // transitions de l'automate
typedef map<int,string> Commentaires; // commentaire associé à un état (lié à une transition entrante et non sortante de cet état)
typedef set<unsigned char> Classe; // classe de caractères
typedef map<string,Classe> Classes; // on associe un nom à une classe de carcactères
typedef list<pair<unsigned char,string> > Historique; // historique caractère lu -> chaîne de diagnostic
typedef map<string,Etats> CMapping; // mapping string -> ensemble d'états (pour les classes de caractères)
typedef map<int,CMapping> CTransitions; // transitions de classes de caractères de l'automate

typedef int Status;
enum EStatus {DEFAUT=0, ACCEPTE=1, ERROR=2};

#define EPSILON 0 // la valeur de epsilon, la chaine vide utilisée pour les epsilon transitions

// description d'un automate à états finis
class AEF {
   public:
      void Reset(void); // on remet à init + fermeture les etats courants

      // destructeur
      ~AEF(void);

      // constructeurs
      // automate que ne reconnait que le mot vide
      AEF(void);
      // constructeur à partir d'un symbole tout simple
      AEF(unsigned char c);
      // constructeur à partir d'une liste de symbole (classe de caractères)
      AEF(const Classe & cl,string nom);
      // constructeur à partir d'une chaine de caractères : concaténation (si chaine vide, alors l'automate ne reconnait que la chaine vide)
      AEF(string s);
      // constructeur par copie
      AEF(const AEF & a);
      // constructeur complet : transitions, etat initial et etats finaux
      AEF(const Transitions &t, const Etat &i, const Etats & f) : transitions(t), init(i), finaux(f), n(0),diagnostic(""),status(0) {comment.clear();}
      AEF(const Transitions &t, const Etat &i, const Etats & f, const Commentaires & c) : transitions(t), init(i), finaux(f), n(0),diagnostic(""),status(0),comment(c) {}
      AEF(const Transitions &t, const Etat &i, const Etats & f,const Classes & c, const CTransitions & ct ) : transitions(t), init(i), finaux(f), n(0),diagnostic(""),status(0) ,ctransitions(ct),classes(c) {comment.clear();}
      AEF(const Transitions &t, const Etat &i, const Etats & f,const Classes & cl, const CTransitions & ct, const Commentaires & c) : transitions(t), init(i), finaux(f), n(0),diagnostic(""),ctransitions(ct),classes(cl),status(0),comment(c) {}

      // exécution de l'automate
      AEF operator<<(unsigned char c); // on envoie un caractère sur l'automate
      AEF operator<<(string s); // on envoie une chaîne sur l'automate
      Status GetStatus(void); // si ERROR, diagnostic est renseigné
      string GetDiagnostic(void);

      // opérations de combinaisons
      friend AEF Union(const AEF & a1, const AEF & a2); // union ("ou")
      friend AEF Union(list<AEF> liste); // union d'une liste d'automates
      friend AEF Concat(const AEF & a1, const AEF & a2); // concaténation (séquence)
      friend AEF Concat(list<AEF> liste); // concaténation (séquence) d'une liste
      friend AEF Kleene(const AEF & a); // etoile de Kleene version fonction
      friend AEF Plus(const AEF & a); // opérateur + : de 1 à n fois version fonction
      friend AEF Option(const AEF & a); // opérateur ? : optionnel
      void Kleene(void); // opérateur unaire * etoile de Kleene version méthode
      void Plus(void); // // opérateur + : de 1 à n fois version méthode
      void Option(void); // opérateur ? : optionnel

      // affichage de l'automate sous forme textuelle
      friend ostream & operator<<(ostream & os, AEF & a); // surcharge operateur d'affichage

      // sortie Graphviz
      void Snap(void); // affiche un fichier dot numéroté par le caractère lu
      void PrintGraph(ostream & os); // affiche le source graphviz dans os

   protected:
      // on ne stocke pas les états qui peuvent être retrouvés dans les transitions et le reste
      // on ne stocke pas non plus l'alphabet (ensemble des caractères)
      // toutes ces informations sont tirées des transitions
      Commentaires comment; // table des commentaires associés à chaque état (si 
      Transitions transitions; // transitions de caractères
      CTransitions ctransitions; // transitions de classes de caractères
      Historique histo; // historique des caractères lus avec leur diagnostic associé
      Etat init; // état initial
      Etats finaux; // états finaux
      Etats courants; // état(s) courant(s)
      int n; // nombre de caractères lus
      string diagnostic; // diagnostic de la dernière erreur
      Status status; // statut de l'automate 
      Classes classes; // classes de caractères
      void addPointClass(void); // crée la classe de caractères "." qui contient n'importe quel caractère imprimable
      list<string> getClasses(unsigned char c); // retourne la liste des classes de caractères d'un caractère
};

#endif // #ifndef _AEF_H

