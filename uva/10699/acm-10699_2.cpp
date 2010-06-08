/**
 * Title: Count the factors
 * URL: http://uva.onlinejudge.org/external/106/10699.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
   + Se calculan los numeros primos hasta el valor maximo y se almacenan en un vector.
   + Se va dividiendo el numero por cada elemento del vector mientras sea posible, incrementando
   + un contador una vez por cada elemento.

**/
#include<iostream>
#include<cstring>
#include<vector>
#define MAX 1000001

using namespace std;

bool prim[MAX];
vector<int> primes;

int main(){
   memset(prim, true, sizeof(prim));
   
   for(int i=2; i*i<=MAX; i++){
      for(int j=2; i*j<=MAX; j++){
         prim[i*j] = false;
      }
   }
   
   for(int i=2; i<MAX; i++){
      if(prim[i]){
         primes.push_back(i);
      }
   }
   
   int n, tmp, c;
   cin >> n;
   while(n != 0){
      tmp = n;
      c = 0;
      
      for(unsigned i=0; i<primes.size() && tmp >= primes[i]; i++){
         if(tmp % primes[i] == 0){
            c++;
            
            while(tmp % primes[i] == 0){
               tmp /= primes[i];
            }
         }
      }
      
      cout << n << " : " << c << '\n';
   
      cin >> n;
   }
   
   return 0;
}
