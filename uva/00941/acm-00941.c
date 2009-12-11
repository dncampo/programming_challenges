/**
 * Title: Permutations
 * URL: http://online-judge.uva.es/p/v9/941.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Primero se calculan los primeros 20 factoriales.
   luego para cada entrada se realiza el siguiente algoritmo:
   - se ordena la entrada.
   - se itera tantas veces como elementos tenga la entrada y 
     se va calculando la letra que hay que imprimir para cada caso.
     El indice de la letra que se imprime se calcula como :
     temp = n!/n;
     indice --> c/temp
     luego se elimina de la entrada el elemento que se imprimio (indice)
     y se vuelve a aplicar el algoritmo.
**/

#include <stdio.h>
#include <string.h>

int main(){
   int i, x, y;
   int cases, size, SIZE;
   long long fact[21], c, tmp;
   char list[21];
   
   fact[0] = fact[1] = 1;
   
   for(i = 2; i < 21; i++){
      fact[i] = i * fact[i-1];
   }

   scanf("%d", &cases);   
   
   for(i = 0; i < cases; i++){
      scanf("%s%n%llu", list,&SIZE, &c);

      SIZE  = size = SIZE-1;

      /* sort */
       for(x = 0; x < SIZE-1; x++){
         for(y = x+1; y < SIZE; y++){
            if(list[x] > list[y]){
               list[x] ^= list[y];
               list[y] ^= list[x];
               list[x] ^= list[y];                              
            }
         }
      }

      /* solve */
      for(x  = 0; x < SIZE; x++, size--){
         c %= fact[size];
         y = c/(fact[size]/size);
         
         printf("%c", list[y]);

         for(; y < size; y++){
            list[y] = list[y+1];
         }
      }
      
      printf("\n");
   }
   
   return 0;
}
