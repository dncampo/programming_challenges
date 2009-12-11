/**
 * Title: Prime Factors 
 * URL: http://acm.uva.es/p/v5/583.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   primero se calculan los primeros primos menores a sqrt(2^31).
   luego para cada entrada primero se verifica si el numero no es primo.
   si es primo se imprime directamente, en caso contrario se sigue el siguiente algoritmo:
   mientras n > 1 se va dividiendo n todas las veces que sea posible por un primo c mientras n sea divisible 
   por c(se imprime el numero primo). Luego se incremente c y se sigue el mismo algoritmo, hasta que n = 1.
**/


#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> primes;

void criba(int limit){
   char list[limit+1];
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
   for(int i = 2; i < limit; i++){
      if(list[i])
         primes.push_back(i);
   }
   
}
bool is_prime(int n){
   if(n < 2 ) return false;
   
   for (int i = 2; i < (int)sqrt(n) + 1; i++){
      if (n % i == 0) 
         return false;
   }
   return true;
}

int main(){
   int n;
   criba(46349);
   
   scanf("%d", &n);
   
   while(n != 0){
      printf("%d = ", n);

      if(n < 0){
         printf("-1 x ");
         n = -n;
      }
      if(is_prime(n)){
         cout << n;
      } else {
         int c = 0;
         while(n > 1){
            int tmp =  n/primes[c];
            while(tmp * primes[c] == n ){
               printf("%d", primes[c]);
               n = tmp;
               tmp /= primes[c];
               if(n > 1) printf(" x ");
            }
            c++;
         }
      }
      printf("\n");
      scanf("%d", &n);
   }
   return 0;
}
