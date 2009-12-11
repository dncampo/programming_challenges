/**
 * Title: Maximum Product
 * URL: http://online-judge.uva.es/p/v110/11059.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   para cada entrada se calcula el producto maximo con la función de fuerza bruta
   y luego se imprime la solucíon.
**/

#include<stdio.h>

int main(){
   int n, count = 1;
   long long prod;
   
   while(~scanf("%d", &n)){
      long long list_s[n];
      prod = 0;
      
      for(int i = 0; i < n; i++){
         scanf("%llu", &list_s[i]);
      }
      long long tprod ;
      for(int i = 0; i < n; i++){
         tprod = 1;
         for(int j = i; j < n; j++){
            tprod *= list_s[j];
            
            if(tprod > prod)
               prod = tprod;
         }
      }
       printf("Case #%d: The maximum product is %llu.\n\n", count++, prod);
   }

   return 0;
}
