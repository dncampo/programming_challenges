/** 
 * Title: Summation of Four Primes
 * URL: http://online-judge.uva.es/p/v101/10168.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Primero se calculan los primeros  10000000 primos
   + Luego para cada entrada se prueba con todos los primos
     hasta que se obtiene el valor ingresado por entrada estandar.
     En caso contario se imprime imposible.
	
**/

#include<cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using std::vector;

vector<int> primes;
char list[10000001];

void criba(){
   memset(list, 1, sizeof(list));
   list[0] = list[1] = 0; 
   int d_limit = (int) (sqrt(10000000));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=10000000; j++){
            list[j*i] = 0;
         }
      }
   }
   for(register int i = 2; i < 10000000; i++){
      if(list[i])
         primes.push_back(i);
   }
}

void solve(int n){
   for(int i = 0; 4*primes[i] <= n; i++){
      for(int j = i; 3*primes[j]+primes[i] <= n; j++){
         for(int k = j; 2*primes[k] + primes[j]+ primes[i] <= n; k++){
            int four = n-primes[k]-primes[j]-primes[i];
            if(list[four]){
               printf("%d %d %d %d\n", primes[i], primes[j], primes[k], four);
               return;
            }
         }
      }
   }
   
   printf("Impossible.\n");
}

int main() {
   int n;
   
   criba();
      
   while(~scanf("%d", &n)){
      solve(n);
   }
   return 0;
}

