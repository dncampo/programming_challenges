/**
 * Title: Street Numbers 
 * URL: http://online-judge.uva.es/p/v1/138.html
 * Resources of interest:
 * Solver group: sergio-david
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza la siguiente formula : k*k = n*(n+1)/2 para 
   imprimir los resultados.
**/

#include <stdio.h>
#include <math.h>

int main(){
   long long n = 8, k = 6, count = 0;
   double k2;
   
   for( ;count < 10; n++){
      k2 = n*(n+1) >> 1;
      k = (int)sqrt(k2);
      
      if(k2 == k*k){
         printf("%10llu%10llu\n", k, n);
         count++;
      }
   }

   return 0;
}

