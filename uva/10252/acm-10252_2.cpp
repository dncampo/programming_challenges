/**
 * Title: Common Permutation 
 * URL: http://online-judge.uva.es/p/v102/10252.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   Para cada par de strings de entrada se realiza el siguiente algoritmo:
   -Para cada letra en cada palabra, se cuenta la cantidad de veces que aparece.
   -Cada letra L (de la 'a' a la 'z') se la imprime X veces, donde X es el menor 
   número entre la cantadad de veces que aparece L en ambas palabras.
   
**/

#include <iostream>
#include <string>

using namespace std;

int main () {
   string a, b;
   while (getline (cin, a)) {
      getline (cin, b);
      
      unsigned lett_a[256] = { 0 };
      unsigned lett_b[256] = { 0 };
      
      for (unsigned i = 0; i < a.size (); i++) {
         lett_a[ (int) a.at(i) ]++;
      }
      
      for (unsigned i = 0; i < b.size (); i++) {
         lett_b[ (unsigned) b[i] ]++;
      }
      
      for (unsigned i = 'a'; i <= 'z'; i++) {
         for (unsigned j = 0; j < min (lett_a[i], lett_b[i]); j++) {
            cout << (char)i; 
         }
      }
      cout << '\n';      
   }
   return 0;
}
