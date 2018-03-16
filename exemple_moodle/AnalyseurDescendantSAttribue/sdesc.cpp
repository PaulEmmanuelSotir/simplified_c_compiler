#include <iostream>
using namespace std;
//#define debug(s) cout<<__FILE__<<":"<< \
//__LINE__<<" "<<__STRING(s)<<"="<<(s)<<endl
#define debug(s) ((void)(0))
#define fin(c) (c==EOF or c=='\n')

bool analyseE(double & val);
bool analyseTEp(double & val,int signe);
bool analyseEp(double & val);
bool analyseT(double & val);
bool analyseFTp(double & val,int inv);
bool analyseTp(double & val);
bool analyseF(double & val);

int next(void) {
   return cin.peek();
}

void shift(void) {
   cin.get();
}

bool analyseE(double & val) {
   debug("AnalyseE");
   if (next()=='(' or isdigit(next())) {
      if (analyseTEp(val,1)) {
         debug(val);
         return true;
      }
   }
   return false;
}

bool analyseTEp(double & val,int signe) {
   debug("AnalyseTEp");
   double valT,valEp;
   bool resT,resEp;
   resT = analyseT(valT);
   if (!resT)
      // pas la peine de continuer dans ce cas
      return false; 
   resEp = analyseEp(valEp);
   if (resT and resEp) {
      val = signe*valT+valEp; // terme=addition
      debug(val);
      return true;
   }
   return false;
}

bool analyseEp(double & val) {
   debug("AnalyseEp");
   int signe = 1;
   if (next()=='+' or next()=='-') {
      if (next()=='-')
         signe = -1;
      shift();
      if (analyseTEp(val,signe)) {
         debug(val);
         return true;
      }
   }
   else if (next()==')' or fin(next())) {
      val = 0; // élément neutre de l'addition
      debug(val);
      return true;
   }
   return false;
}

bool analyseT(double & val) {
   debug("AnalyseT");
   if (next()=='(' or isdigit(next())) {
      if (analyseFTp(val,0))  {
         debug(val);
         return true;
      }
   }
   return false;
}

bool analyseFTp(double & val,int inv) {
   debug("AnalyseFTp");
   double valF,valTp;
   bool resF,resTp;
   resF = analyseF(valF);
   if (!resF)
      return false;
   resTp = analyseTp(valTp);
   if (resF and resTp) {
      if (inv)
         valF = 1.0/valF;
      val = valF*valTp; // facteur = mult.
      debug(val);
      return true;
   }
   return false;
}

bool analyseTp(double & val) {
   int inv;
   debug("AnalyseTp");
   if ((inv=(next()=='/')) or next()=='*') {
      shift();
      if (analyseFTp(val,inv)) {
         debug(val);
         return true;
      }
   }
   else if (next()=='+' or next()=='-' 
            or next()==')' or fin(next())) {
      val = 1.0; //élement neutre de la mult.
      debug(val);
      return true;
   }
   return false;
}

bool analyseF(double & val) {
   debug("AnalyseF");
   if (next()=='(') {
      shift();
      if (analyseE(val)) {
         shift(); // la parenthèse fermante
         return true;
      }
   }
   else if (isdigit(next())) {
      double v=next()-'0';
      // lecture d'un entier 
      // et conversion en double
      shift();
      while (isdigit(next())) {
         v = 10*v+next()-'0';
         shift();
      }
      val = v;
      debug(val);
      return true;
   }
   return false;
}

int main(void) {
   double val;
   analyseE(val);
   cout<<"La valeur résultat est "<<val<<endl;
   return 0;
}
