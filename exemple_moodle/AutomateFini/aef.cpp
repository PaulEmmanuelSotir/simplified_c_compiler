#include "aef.h"
#include <iostream>
#include <sstream>
#include <fstream>

// dernier état créé (pour éviter d'avoir les mêmes numéros d'états quand on fait des opérations de mélange d'automates)
static int last = 0;

void AEF::addPointClass(void) {
   string car = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>()"; // il faudrait compléter en théorie
   Classe cl;
   int i;
   for (i=0;i<car.length();i++) {
      cl.insert(car[i]);
   }
   classes["."] = cl;
}

// n'importe quel caractère
AEF::AEF(void) {
   init = last+1;
   int fin = last+2;
   transitions.clear();
   ctransitions.clear();
   classes.clear();
   courants.insert(init);
   diagnostic = "";
   status = 0;
   n = 0;
   histo.clear();
   last+=2;
   addPointClass();
   ctransitions[init]["."].insert(fin);
   finaux.insert(fin);
}

// constructeur par copie
AEF::AEF(const AEF & a) {
   transitions = a.transitions;
   ctransitions = a.ctransitions;
   classes = a.classes;
   init = a.init;
   finaux = a.finaux;
   courants = a.courants;
   n = a.n;
   diagnostic = a.diagnostic;
   status = a.status;
   comment = a.comment;
   histo.clear();
}

AEF::~AEF(void) {
}

AEF::AEF(const Classe & cl,string nom) {
   classes[nom] = cl;
   stringstream oss;
   init = last+1; 
   finaux.insert(last+2); 
   courants.insert(init); 
   ctransitions[last+1][nom].insert(last+2); 
   last+=2;
   diagnostic = "";
   status = 0;
   n = 0;
   oss<<"Classe de caractères '"<<nom<<"' attendue\n";
   comment[init] = oss.str();
   histo.clear();
}

AEF::AEF(unsigned char c)
{ 
   stringstream oss;
   init = last+1; 
   finaux.insert(last+2); 
   courants.insert(init); 
   transitions[last+1][c].insert(last+2); 
   last+=2;
   diagnostic = "";
   status = 0;
   n = 0;
   oss<<"Caractère '"<<c<<"' attendu\n";
   comment[init] = oss.str();
   histo.clear();
}

AEF::AEF(string s)
{ 
   init = last+1; 
   last++;
   courants.insert(init); 
   for (int i=0;i<s.length();i++) {
      transitions[last][s[i]].insert(last+1); 
      if (i==0)
         comment[last] = "Chaîne littérale \""+s+"\" attendue\n";
      else
         comment[last] = "Chaîne littérale \""+s+"\" incomplète\n";
      last++;
   }
   if (s.length()==0)
      finaux.insert(init); // dans ce cas là il n'y aura pas eu de transitions, chaine vide
   else
      finaux.insert(last);
   diagnostic = "";
   status = 0;
   n = 0;
   histo.clear();
}

void CopieClasses(const Classes & src, Classes & dest) {
   Classes::const_iterator c;
   for (c=src.begin();c!=src.end();c++) {
      dest[(*c).first] = (*c).second;
   }
}

void CopieCTrans(const CTransitions & src, CTransitions & dest) {
   // recopie des transitions de classe de src vers dest
   CTransitions::const_iterator i;
   CMapping::const_iterator m;
   Etats::const_iterator e;
   for (i=src.begin();i!=src.end();i++) {
      for (m=(*i).second.begin();m!=(*i).second.end();m++) {
         for (e=(*m).second.begin();e!=(*m).second.end();e++) {
            dest[(*i).first][(*m).first].insert(*e);
         }
      }
   }

}

void CopieTrans(const Transitions & src, Transitions & dest){
   // recopie des transitions de src vers dest
   Transitions::const_iterator i;
   Mapping::const_iterator m;
   Etats::const_iterator e;
   for (i=src.begin();i!=src.end();i++) {
      for (m=(*i).second.begin();m!=(*i).second.end();m++) {
         for (e=(*m).second.begin();e!=(*m).second.end();e++) {
            dest[(*i).first][(*m).first].insert(*e);
         }
      }
   }
}

void CopieComment(const Commentaires & c1,Commentaires & c2) {
   Commentaires::const_iterator i;
   for (i=c1.begin();i!=c1.end();i++) {
      c2.insert((*i));
   }
}

// pour faire l'union de plusieurs automates, on fait un nouvel état
// initial que l'on relie aux états initiaux des automates par epsilon
// on crée un nouvel état final destination des états finaux des automates
AEF Union(list<AEF> liste) {
   Commentaires com;
   
   int debut = last+1; // nouvel état initial
   Etat init;
   init = debut;

   int fin = last+2; // nouvel état final
   Etats finaux;
   finaux.insert(fin);

   Transitions trans;
   CTransitions ctrans;
   Classes cl;

   list<AEF>::iterator i;
   Etats::iterator e;

   for (i=liste.begin();i!=liste.end();i++) {
      trans[debut][EPSILON].insert((*i).init);
      // epsilon transitions de fin
      for (e=(*i).finaux.begin();e!=(*i).finaux.end();e++) {
         trans[*e][EPSILON].insert(fin);
      }
      CopieTrans((*i).transitions,trans);
      CopieCTrans((*i).ctransitions,ctrans);
      CopieClasses((*i).classes,cl);
      CopieComment((*i).comment,com);
   }

   last+=2; // on a utilisé deux nouveaux états

   return AEF(trans,init,finaux,cl,ctrans,com);
}



// pour faire l'union de deux automates, on fait un nouvel état
// initial que l'on relie aux états initiaux de a1 et a2 par epsilon
// on crée un nouvel état final destination des états finaux de a1 et a2
AEF Union(const AEF & a1, const AEF & a2) {
   Commentaires com;
   
   int debut = last+1; // nouvel état initial
   Etat init;
   init = debut;

   int fin = last+2; // nouvel état final
   Etats finaux;
   finaux.insert(fin);

   Transitions trans = a1.transitions; // on recopie les transitions de a1
   CTransitions ctrans = a1.ctransitions;
   Classes cl = a1.classes;

   // epsilon transitions de début
   Etats::iterator e;
   trans[debut][EPSILON].insert(a1.init);
   trans[debut][EPSILON].insert(a2.init);

   // epsilon transitions de fin
   for (e=a1.finaux.begin();e!=a1.finaux.end();e++) {
      trans[*e][EPSILON].insert(fin);
   }
   for (e=a2.finaux.begin();e!=a2.finaux.end();e++) {
      trans[*e][EPSILON].insert(fin);
   }

   // recopie des transitions de a2
   CopieTrans(a2.transitions,trans);
   CopieCTrans(a2.ctransitions,ctrans);
   CopieClasses(a2.classes,cl);

   last+=2; // on a utilisé deux nouveaux états

   CopieComment(a1.comment,com);
   CopieComment(a2.comment,com);

   return AEF(trans,init,finaux,cl,ctrans,com);
}

// concaténation d'une liste d'automates
AEF Concat(list<AEF> liste) {
   Commentaires com;
   Etat init = liste.front().init;
   Etats finaux = liste.back().finaux;
   Transitions trans;
   CTransitions ctrans;
   Classes cl;

   Etats::iterator e;
   list<AEF>::iterator i;
   list<AEF>::iterator j;

   for (i=liste.begin(),j=i,j++;j!=liste.end();i++,j++) {
      // epsilon transitions de fin vers début du suivant
      for (e=(*i).finaux.begin();e!=(*i).finaux.end();e++) {
         trans[*e][EPSILON].insert((*j).init);
      }
      CopieTrans((*i).transitions,trans); 
      CopieCTrans((*i).ctransitions,ctrans); 
      CopieClasses((*i).classes,cl);
      CopieComment((*i).comment,com);
   }

   CopieTrans((*i).transitions,trans);  // *i dernier élément de la liste (avant end)
   CopieCTrans((*i).ctransitions,ctrans); 
   CopieClasses((*i).classes,cl);
   CopieComment((*i).comment,com);
   return AEF(trans,init,finaux,cl,ctrans,com);
} 

// concaténation de deux automates 
AEF Concat(const AEF & a1, const AEF & a2) {
   Commentaires com;
   Etat init = a1.init;
   Etats finaux = a2.finaux;
   Transitions trans;
   CTransitions ctrans;
   Classes cl;
   Etats::iterator e;

   // epsilon transitions de fin
   for (e=a1.finaux.begin();e!=a1.finaux.end();e++) {
      trans[*e][EPSILON].insert(a2.init);
   }
   // copie de toutes les autres transitions
   CopieTrans(a1.transitions,trans); 
   CopieTrans(a2.transitions,trans); 
   CopieCTrans(a1.ctransitions,ctrans); 
   CopieCTrans(a2.ctransitions,ctrans); 
   CopieClasses(a1.classes,cl);
   CopieClasses(a2.classes,cl);
   CopieComment(a1.comment,com);
   CopieComment(a2.comment,com);
   return AEF(trans,init,finaux,cl,ctrans,com);
} 

AEF Kleene(const AEF & a) {
   AEF r(a.transitions,a.init,a.finaux,a.comment);
   r.Kleene();
   return r;
}

AEF Option(const AEF & a) {
   AEF r(a.transitions,a.init,a.finaux,a.comment);
   r.Option();
   return r;
}

AEF Plus(const AEF & a) {
   AEF r(a.transitions,a.init,a.finaux,a.comment);
   r.Plus();
   return r;
}

void AEF::Kleene(void) {
   // espilon transitions des états finaux vers un nouvel état final
   Etat fin;
   if (finaux.size()>1)
   {
      fin = last+1;
      last++;
      Etats::iterator e;
      for (e=finaux.begin();e!=finaux.end();e++) {
         transitions[*e][EPSILON].insert(fin);
      }
   }
   else
      fin = *(finaux.begin());


   transitions[fin][EPSILON].insert(init); // feedback
   //transitions[init][EPSILON].insert(fin); // bypass pour * de Kleene

   finaux.insert(init); // l'état initial devient aussi un état final
}

void AEF::Option(void) {
   // espilon transitions des états finaux vers un nouvel état final
   Etat fin;
   if (finaux.size()>1)
   {
      fin = last+1;
      last++;
      Etats::iterator e;
      for (e=finaux.begin();e!=finaux.end();e++) {
         transitions[*e][EPSILON].insert(fin);
      }
   }
   else
      fin = *(finaux.begin());


   transitions[init][EPSILON].insert(fin); // bypass pour * de Kleene

   finaux.insert(init); // l'état initial devient aussi un état final
}


void AEF::Plus(void) {
   // espilon transitions des états finaux vers un nouvel état final
   Etat fin;
   if (finaux.size()>1)
   {
      fin = last+1;
      last++;
      Etats::iterator e;
      for (e=finaux.begin();e!=finaux.end();e++) {
         transitions[*e][EPSILON].insert(fin);
      }
   }
   else
      fin = *(finaux.begin());

   transitions[fin][EPSILON].insert(init); // feedback
   last++;
}

AEF AEF::operator<<(string s) {
   for (int i=0;i<s.length();i++) {
      *this<<s[i];
   }
   return *this;
}
 
list<string> AEF::getClasses(unsigned char c) {
   list<string> resultat;
   Classes::iterator i;
   for (i=classes.begin();i!=classes.end();i++) {
      if ((*i).second.find(c)!=(*i).second.end()) {
         resultat.push_back((*i).first);
      }
   }
   return resultat;
}

AEF AEF::operator<<(unsigned char c) {
   Etats ncourants;
   Etats::iterator e;
   Etats::iterator f;

   n++;
   //cout<<"Lecture du caractère "<<c<<endl;

   bool chgt = false;
   list<string> lc;
   list<string>::iterator ilc;

   for (e=courants.begin();e!=courants.end();e++) {
      if (transitions.find(*e)!=transitions.end()) { // il y a des transitions depuis cet état
         if (transitions[*e].find(c)!=transitions[*e].end()) { // il y a des transitions avec le caractère c
            for (f=transitions[*e][c].begin();f!=transitions[*e][c].end();f++) {
               chgt = true;
               ncourants.insert(*f); // copie des cibles des transitions vers les novueaux états courants
            }
         }
      }
      if (ctransitions.find(*e)!=ctransitions.end()) { // il y a des transitions depuis cet état dans les classes de caractères
         lc = getClasses(c);
         for (ilc=lc.begin();ilc!=lc.end();ilc++) {
            if (ctransitions[*e].find(*ilc)!=ctransitions[*e].end()) {
               for (f=ctransitions[*e][*ilc].begin();f!=ctransitions[*e][*ilc].end();f++) {
                  chgt = true;
                  ncourants.insert(*f); // copie des cibles des transitions vers les novueaux états courants
               }
            }
         }
      }
   }
   if (!chgt)
   {
      status = status | ERROR;

      diagnostic = "";
      for (e=courants.begin();e!=courants.end();e++) {
         if (comment.find(*e)!=comment.end()) {
            diagnostic += "  - ";
            diagnostic += comment[*e];
         }
      }
      if (diagnostic=="")
         diagnostic = "Aucune transition possible (probablement fin de lecture de l'expression)";
      histo.push_back(make_pair(c,diagnostic));
   }
   else {
      // fermeture transitive avec les epsilon transitions
      do {
         chgt = false;
         courants.clear();
         courants = ncourants;
         for (e=courants.begin();e!=courants.end();e++) {
            if (transitions.find(*e)!=transitions.end()) { // il y a des transitions depuis cet état
               if (transitions[*e].find(EPSILON)!=transitions[*e].end()) { // il y a des epsilon transitions
                  for (f=transitions[*e][EPSILON].begin();f!=transitions[*e][EPSILON].end();f++) {
                     if (courants.find(*f)==courants.end()) {
                        chgt = true;
                        ncourants.insert(*f);
                     }
                  }
               }
            }
         }
      } while(chgt);
      histo.push_back(make_pair(c,"Ok"));
   }
   //Snap();
   // si on sort de la boucle c'est car courant==ncourant
   return *this;
}

void AEF::Reset(void) {
   courants.clear();
   courants.insert(init);
   Etats ncourants;
   Etats::iterator e;
   Etats::iterator f;

   ncourants = courants;
   status = DEFAUT;
   n = 0;
   diagnostic = "";

   bool chgt;
   // fermeture transitive avec les epsilon transitions
   do {
      chgt = false;
      courants.clear();
      courants = ncourants;
      for (e=courants.begin();e!=courants.end();e++) {
         if (transitions.find(*e)!=transitions.end()) { // il y a des transitions depuis cet état
            if (transitions[*e].find(EPSILON)!=transitions[*e].end()) { // il y a des epsilon transitions
               for (f=transitions[*e][EPSILON].begin();f!=transitions[*e][EPSILON].end();f++) {
                  if (courants.find(*f)==courants.end()) {
                     chgt = true;
                     ncourants.insert(*f);
                  }
               }
            }
         }
      }
   } while(chgt);
   histo.clear();
}

Status AEF::GetStatus(void) {
   Etats::iterator e;
   for (e=courants.begin();e!=courants.end();e++) {
      if (finaux.find(*e)!=finaux.end())
         status |= ACCEPTE;
   }
   return status;
}

string AEF::GetDiagnostic(void) {
   return diagnostic;
}

ostream & operator<<(ostream & os, AEF & a) {
   Transitions::const_iterator i;
   Mapping::const_iterator m;
   Etats::const_iterator e;
   os<<"Transitions"<<endl;
   for (i=a.transitions.begin();i!=a.transitions.end();i++) {
      for (m=(*i).second.begin();m!=(*i).second.end();m++) {
         for (e=(*m).second.begin();e!=(*m).second.end();e++) {
            os<<"  "<<(*i).first<<" ";
            if ((*m).first==EPSILON)
               os<<"§";
            else
               os<<(*m).first;
            os<<" -> "<<*e<<endl;
         }
      }
   }
   os<<"Courants : ";
   for (e=a.courants.begin();e!=a.courants.end();e++) {
      os<<" "<<*e;
   }
   os<<endl;
   os<<"Finaux : ";
   for (e=a.finaux.begin();e!=a.finaux.end();e++) {
      os<<" "<<*e;
   }
   os<<endl;
   Commentaires::iterator c;
   os<<"Commentaires : "<<endl;
   for (c=a.comment.begin();c!=a.comment.end();c++) {
      os<<(*c).first<<" -> "<<(*c).second;
   }
   os<<endl;
   os<<"Historique :"<<endl;
   Historique::iterator h;
   for (h=a.histo.begin();h!=a.histo.end();h++) {
      os<<"Caractère "<<(*h).first<<" : "<<(*h).second<<endl;
   }
   return os;
}

void AEF::Snap(void) {
   ostringstream oss;
   oss<<"caractere"<<n<<".dot";
   filebuf fb;
   fb.open (oss.str().c_str(),ios::out);
   ostream os(&fb);
   PrintGraph(os);
   fb.close();
}

void AEF::PrintGraph(ostream & os) {
   Transitions::const_iterator i;
   Mapping::const_iterator m;
   Etats::const_iterator e;
   CTransitions::const_iterator ci;
   CMapping::const_iterator cm;
   Etats etats;
   os<<"digraph aef {"<<endl<<"  rankdir=LR;"<<endl<<endl;
   for (i=transitions.begin();i!=transitions.end();i++) { // pour tous les états de départ de transition
      for (m=(*i).second.begin();m!=(*i).second.end();m++) { // pour tous les caractères de transition
         for (e=(*m).second.begin();e!=(*m).second.end();e++) { // pour tous les états cibles de transition
            etats.insert((*i).first);
            os<<"  etat"<<(*i).first<<" -> ";
            etats.insert(*e);
            os<<"etat"<<*e<<" ";
            if ((*m).first==EPSILON)
               os<<"[label=\"&epsilon;\"];"<<endl;
            else
               os<<"[label=\""<<(*m).first<<"\"];"<<endl;
         }
      }
   }
   for (ci=ctransitions.begin();ci!=ctransitions.end();ci++) { // pour tous les états de départ de transition de classes
      for (cm=(*ci).second.begin();cm!=(*ci).second.end();cm++) { // pour toutes les classes de transition
         for (e=(*cm).second.begin();e!=(*cm).second.end();e++) { // pour tous les états cibles de transition
            etats.insert((*ci).first);
            os<<"  etat"<<(*ci).first<<" -> ";
            etats.insert(*e);
            os<<"etat"<<*e<<" ";
            os<<"[label=\"{"<<(*cm).first<<"}\"];"<<endl;
         }
      }
   }

   for (e=finaux.begin();e!=finaux.end();e++) {
      etats.insert(*e);
   }
   for (e=etats.begin();e!=etats.end();e++) {
      os<<"  etat"<<*e<<"[shape=";
      if (finaux.find(*e)!=finaux.end())
         os<<"doublecircle";
      else
         os<<"circle";
         
      os<<",label=\""<<*e<<"\"";

      if (courants.find(*e)!=courants.end())
         os<<",style=filled";

      os<<"];"<<endl;
   }
   os<<"  debut -> etat"<<init<<"[label=\"start\"];"<<endl;
   os<<"  debut[shape=point];"<<endl;
   Historique::iterator h;
   stringstream oss;
   for (h=histo.begin();h!=histo.end();h++) {
      if ((*h).second=="Ok")
         oss<<(*h).first;
      else
         oss<<"<font color='red'>"<<(*h).first<<"</font>";
   }
   //os<<"  comment[pos=\"1,0\",shape=plaintext,label=<"<<oss.str()<<">];"<<endl;
   os<<"}"<<endl;
}
