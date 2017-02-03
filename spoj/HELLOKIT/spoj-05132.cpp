/**
 * Title: Hello Kitty
 * URL: https://www.spoj.pl/problems/HELLOKIT/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se concatena la palabra tanta veces como indique el número de entrada. Luego se imprime y se desplazan
   todos las latras un espacio hacia la izquiera. El número total de impresiones es igual al tamaño de
   la palabra original.

**/


#include <iostream>
#include <string>

using namespace std;

int main() {
   string word;
   unsigned count;

   while (cin >> word) {
      if ("." == word) return 0;

      cin >> count;

      unsigned wsize = word.size();

      string res = word;
      for (unsigned i = 1; i < count; i++) {
            res += word;
      }

      for (unsigned i = 0; i < wsize; i++) {
         cout << res << endl;
         char c = res[0];
         res = res.substr(1);
         res += c;
      }
   }

   return 0;
}
