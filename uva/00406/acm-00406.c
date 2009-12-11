/**
 * Title: Prime Cuts
 * URL: http://acm.uva.es/p/v4/406.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   se calculan primero los primos menor o igual a 1010 ( el primo 1009 se usa como limite superior, para simplificar la implementacion).
   luego se calcula el centro y se define un inicio y fin para imprimir los numeros primos.
**/

#include <stdio.h>
#include <math.h>
#include <string.h>
          
int primes[170];

void criba(int limit){
   char list[limit+1];
   memset(list, 1, sizeof(list));

   int index = 0, i, j, d_limit = (int) (sqrt(limit));
   
   for(i = 2; i<=d_limit; i++){
      if(list[i]){
         for(j = 2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
 
   for(i = 1; i < limit; i++){
      if(list[i] == 1)
         primes[index++] = i;
   }
}


int main() {
   int n, c;
   criba(1010); /*un primo de mas */

   while(~scanf("%d%d", &n, &c)){
      int count = 0, begin , end;

      while(primes[count] <= n){
         ++count;
      }

      printf("%d %d: ", n, c);

      c <<= 1;
      if(count & 1) --c;        
      
      if(count <= c){
         begin = 0;
         end = count-1;
      }else {
         begin = (count - c) /2;
         end = begin + c-1;
      }
      
      for(count = begin; count < end; count++){
         printf("%d ", primes[count]);
      }
      printf("%d\n\n", primes[end]);
   }

   return 0;
}

