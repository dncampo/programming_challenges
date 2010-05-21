/**
 * Title: Pizza Cutting
 * URL: http://uva.onlinejudge.org/external/100/10079.html
 * Resources of interest:
 * Solver group: David, Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se visualiza una fórmula cerrada que resuelve el problema:
   result = 1 + [n * (n + 1)] / 2

**/

#include <iostream>

using namespace std;


int main () {
   long long num;

   while (cin >> num) {
      if (num < 0) return 0;
      
      cout << (num * (num + 1) >> 1) + 1 << '\n';      
   }
}

