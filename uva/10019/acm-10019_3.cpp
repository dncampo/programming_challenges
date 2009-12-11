/**
 * Title: Funny Encryption Method
 * URL: http://online-judge.uva.es/p/v100/10019.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para cada entrada primero se calcula b1 utilizando nivel de bits y
   para b2 se utiliza un arreglo de contadores de bits para contar los bits
   en hexadecimal que tiene el numero.
   Luego se imprime la solucion
**/

#include <stdio.h>

int main (){
   unsigned count[10] = {0,1,1,2,1,2,2,3,1,2};
	unsigned cases, num, b1, b2, i, j;
	
	scanf("%d", &cases);
	
	for(i = 0; i < cases; i++){
		scanf("%d", &num);

		b1 = b2 = 0;
   
      for(j = 0; j < 14; j++){
         b1 += (num >> j ) & 1;
      }
      
      for(j = num; j > 0;){
         j /= 10;
         b2 += count[num-10*j];
         num = j;
      }
      
      printf("%d %d\n", b1, b2);
	}

	return 0;
}
