#include "aef.h"
#include <iostream>
using namespace std;

int main(void) {
   AEF a = Concat(Kleene(AEF("a")),AEF("b"));
   string chaine;

   a.Reset(); // cet appel est obligatoire sinon il n'y a pas d'état courant...

   cin>>chaine;

   cout<<a<<endl;

   a<<chaine;

   cout<<a<<endl;

   int status = a.GetStatus();
   if (status&ACCEPTE)
   {
      cout<<"Chaine acceptée (partiellement s'il y a des erreurs)"<<endl;
   }
   if (status&ERROR)
   {
      cout<<"Erreur"<<endl;
      cout<<a.GetDiagnostic()<<endl;
   }
   if (status==0)
   {
      cout<<"L'automate n'est pas dans un état final (il n'y a pas d'erreur mais on n'a pas atteint d'état final)"<<endl;
   }

   /*a.Reset();
   a.Snap();
   a<<"a";
   cout<<a<<endl;
   a.Snap();
   a<<"b";
   cout<<a<<endl;
   a.Snap();
   a<<"b";
   cout<<a<<endl;
   a.Snap();*/

   return 0;
}
