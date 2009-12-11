/** 
 * Title: Count on Cantor
 * URL: http://online-judge.uva.es/p/v2/264.html
 * Resources of interest:
 * Solver group: yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   similar a la implementacion de david..
	
**/
#include <stdio.h>

unsigned sol_a[10000001];
unsigned sol_b[10000001];

int main(){
   int index = 1, i, n, count;

   sol_a[1] = sol_b[1] = 1;

   for(i = 2; i < 10000001; i++){
      if(index == 1){
         if(sol_a[i-1] == 1){
            sol_a[i] = 1;
            index = 0;
         } else {
            sol_a[i] = sol_a[i-1] - 1;         
         }
         sol_b[i] = sol_b[i-1] + 1;         
      } else {
         if(sol_b[i-1] == 1){
            sol_b[i] = 1;
            index = 1;
         } else {
            sol_b[i] = sol_b[i-1] - 1;         
         }
         sol_a[i] = sol_a[i-1] + 1;         
      }
   }

   while(~scanf("%d", &n)){
      printf("TERM %d IS %d/%d\n ", n, sol_a[n], sol_b[n]);

   }
   
   return 0;
}

