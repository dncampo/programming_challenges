/**
 * Title: Enormous Input Test
 * URL: https://www.spoj.pl/problems/INTEST/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se usa scanf y printf para pasar la prueba, contando la cantidad de números que son
   divisibles por k.

**/


#include <stdio.h>

unsigned cnt, i;

int main() {
   unsigned n, k, num;

   scanf("%u%u",&n,&k);

   for (; i < n; i++) {
      scanf("%u",&num);
      if (0 == num % k) cnt++;
   }
   printf("%u\n",cnt);
   return 0;
}
