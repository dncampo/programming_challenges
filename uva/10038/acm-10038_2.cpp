/**
 * Title: Jolly Jumpers
 * URL: http://online-judge.uva.es/p/v100/10038.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   Solucion alternativa a la solucion de david. Difiere en 
   que se implementa a modo "c" y para detectar si es Jolly
   en este caso solo se utiliza un vector en donde se guardan las diferencias.
**/


#include <stdio.h>
#include <string.h>

int main(){
   int n, i;
   
   while(~scanf("%d", &n)){
      char list[n];
      int a, b, is_jolly = 1;
      
      memset(list, 0, sizeof(list));

      scanf("%d", &a);

      for(i = 1; i < n; i++){
         scanf("%d", &b);
         list[a > b? a-b: b-a] = 1;
         a = b;
      }
      
      for(i = 1; i< n; i++){
         if(list[i] == 0){
            is_jolly = 0;
            break;
         }
      }

      if(is_jolly){
         printf("Jolly\n");
      }else {
         printf("Not jolly\n");
      }
   }
  
   return 0;
}
