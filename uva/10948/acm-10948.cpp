/** 
 * Title: The primary problem.
 * URL: http://online-judge.uva.es/p/v109/10948.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Primero se calculan los primeros  1000000 primos
   + Luego para cada entrada se prueba con todos los primos
     hasta que se obtiene el valor ingresado por entrada estandar.
     En caso contario se imprime no way.
	
**/

#include<cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using std::vector;

vector<int> primes;
char list[1000001];

void criba(){
   memset(list, 1, sizeof(list));
   list[0] = list[1] = 0; 
   int d_limit = (int) (sqrt(1000000));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=1000000; j++){
            list[j*i] = 0;
         }
      }
   }
   for(register int i = 2; i <= 1000000; i++){
      if(list[i])
         primes.push_back(i);
   }
}

void solve(int n){
   for(int i = 0; 2*primes[i] <= n; i++){
      if(list[n-primes[i]]){
         printf("%d:\n%d+%d\n", n, primes[i], n-primes[i]);
         return;
      }
   }
   
   printf("%d:\nNO WAY!\n", n);
}

int main() {
   int n;
   
   criba();
   scanf("%d", &n);
   
   while(n != 0){
      solve(n);
      scanf("%d", &n);      
   }
   
   return 0;
}

