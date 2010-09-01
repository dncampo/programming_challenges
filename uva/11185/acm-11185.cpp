/**
 * Title: Ternary
 * URL: http://uva.onlinejudge.org/external/111/11185.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se utiliza la herramienta de conversión de bases para resolver el problema.
    + Tener cuidado porque con un número decimal suficientemente grande, se necesita
    utilizar long long para representarlo en base 3.
**/


#include <cstdio>


int main () {
   int n;
   
   while (~scanf("%d", &n) && n >= 0) {
      long long int result = 0, multiplier = 1;   
      
      while (n > 0) {
         result += (n % 3) * multiplier;
         multiplier *= 10;
         n /= 3;
      }
      printf ("%lld\n", result);
   }

   return 0;
}

