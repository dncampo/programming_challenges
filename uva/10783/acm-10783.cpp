/**
 * Title: Odd Sum 
 * URL: http://uva.onlinejudge.org/external/107/10783.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
 se utliza la siguiente formula:
  sum (primeros n impares) = n*n
  ej : 1 + 3 + 5+ 7 = 4*4 = 16
**/


#include <stdio.h>

int main(){
   int cases, a, b;
   
   scanf("%d", &cases);
   
   for(int i = 1; i <= cases; i++){
      scanf("%d%d", &a, &b);
      
      if(a == b){
         printf("Case %d: %d\n", i, (a % 2 == 0) ? 0 : a);
      } else {
         if(a % 2 == 0) a++;
         if(b % 2 == 0) b--;

         a = a-2 > 0 ? a-2 : 0;
         int n1 = (b +1)/2;
         int n2 = (a+1)/2;

         printf("Case %d: %d\n", i, (n1*n1)-(n2*n2));
      }
   }
      
   return 0;
}

