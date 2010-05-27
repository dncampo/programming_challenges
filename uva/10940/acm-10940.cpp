/**
 * Title: Throwing cards away II 
 * URL: http://online-judge.uva.es/p/v109/10940.html
 * Resources of interest:
 * Solver group: Yeyo, David, Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Observando la salida para varios casos se llega a la fórmula siguiente para un 'n' dado:
    (n - 2^k) * 2, donde 2^k es la mayor potencia de 2 menor que n.
**/

#include <cstdio>

int main(){

	int n;

	while(~scanf("%d", &n)){
      if(0 == n)
         return 0;
         
      if (1 == n) {
         printf ("1\n");
      }
      else {
         int m = 1;
         while ((m <<= 1) < n);
         m >>= 1;
         printf ("%d\n", (n - m) << 1);
      }
	}
	return 0;
}

