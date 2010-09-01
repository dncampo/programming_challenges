/**
 * Title: Parity
 * URL: http://uva.onlinejudge.org/external/109/10931.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se realiza un chequeo del último bit para ver si está seteado. Luego se van desplazando
    todos los bits hacia la derecha, mientras el número sea mayor que 0.
    + Se guarda en un arreglo la representación binaria del número.
**/


#include <cstdio>


int main () {
   int n, sum, i;
   
   while (~scanf("%d", &n) && 0 != n) {
      char bits[33] = {'\0'};
      
      sum = 0, i = 32;
      
      while (n > 0) {
         sum += n & 1;
         bits[--i] = '0' + (n & 1);
         n >>= 1;
      }
      printf ("The parity of %s is %d (mod 2).\n", bits + i, sum);
   }

}

