/**
 * Title: Is Bigger Smarter?
 * URL: http://uva.onlinejudge.org/external/101/10131.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se crea un vector<Elephant> y se lo ordena por peso y IQ. Luego se busca la mayor subsecuencia
   común (LCS) entre las dos ordenaciones de dicho vector.

**/


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Elephant {
   unsigned W, IQ, ID;

   bool operator== (const Elephant &e) const {
      return ID == e.ID;
   }
};

bool weight_sort ( const Elephant& e1, const Elephant& e2 ) {
   return e1.W > e2.W;
}

bool iq_sort ( const Elephant& e1, const Elephant& e2 ) {
   return e1.IQ < e2.IQ;
}


int lcs(const vector<Elephant>& A, const vector<Elephant>& B, vector<vector<int> >& pm) {
   for (int i = A.size(); i >= 0; i--)
      for (int j = B.size(); j >= 0; j--) {

         if (i == (int)A.size() || j == (int)B.size()) pm[i][j] = 0;
         else if (A[i] == B[j]) pm[i][j] = 1 + pm[i+1][j+1];
         else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);

      }
   return pm[0][0];
}

void print_lcs(const vector<Elephant>& A, const vector<Elephant>& B, const vector<vector<int> >& pm){
   stack<Elephant> s;
   int i = 0, j = 0, m = A.size(), n = B.size();
   while (i < m && j < n){
      if (A[i] == B[j]){
         s.push (A[i]);
         i++; j++;
      }
   else if (pm[i+1][j] >= pm[i][j+1]) i++;
   else j++;
   }
   while (!s.empty ()) {
      cout << s.top ().ID << endl;
      s.pop ();
   }
}

int main(){
   unsigned w, iq, id = 1;
   vector<Elephant> elephants1, elephants2;


   while (cin >> w >> iq) {
      Elephant e = {w, iq, id++}; //se cargan los elefantes
      elephants1.push_back (e);
   }
   elephants2 = elephants1;

   sort (elephants1.begin (), elephants1.end (), weight_sort); //ordenar por peso
   sort (elephants2.begin (), elephants2.end (), iq_sort); //y IQ

   vector<vector<int> > prefix_matrix(elephants1.size() + 1);
   for(unsigned i = 0; i < elephants1.size() + 1; i++){
      vector<int> vy(elephants2.size() + 1,0);
      prefix_matrix[i] = vy;
   }

   cout << lcs(elephants1, elephants2, prefix_matrix) << endl; //Se busca la LCS
   print_lcs(elephants1, elephants2, prefix_matrix);

   cout << endl;

   return 0;
}
