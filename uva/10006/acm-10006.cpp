/**
 * Title: Carmichael Numbers 
 * URL: http://uva.onlinejudge.org/external/100/10006.html
 * Resources of interest:
 * Solver group: David-Leo-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se calculan los numeros primos hasta el 65000
    + Luego para todos los numeros no primos se verifica si son numeros de Carmichael,
    para esto se utiliza una funcion recursiva que calcula la potencia de un numero dado
    en complejidad logaritmica.
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 65000

using namespace std;

char primes[MAX + 1];

int rec(int a, unsigned n, unsigned mod){
   if(1 == n){
      return a;
   }

   unsigned square = rec(a, n >> 1, mod);   

   square = (square * square) % mod;

   if(n & 1){ // impar
      square = (square * a) % mod;
   }

   return square;   
}

bool solve(int n){
   if(primes[n] != 0) {
      return false;
   }
   
   for(register int a = 2 ; a < n; a++){
      if(a != rec(a, n, n)){
         return false;
      }
   }
   
   return true;
}

void criba(){
   memset(primes, 1, sizeof(primes));
   
   for(register int i = 2; i*i <= MAX; i++){
      if(primes[i]){
         for(register int j = 2; i*j <= MAX; j++){
            primes[i*j] = 0;
         }
      }
   }
}

int main(){
   criba();

   int n;
   
   scanf("%d", &n);
   
   while(n != 0){
      if(solve(n)){
         printf("The number %d is a Carmichael number.\n", n);
      } else {
         printf("%d is normal.\n", n);
      }
      scanf("%d", &n);
   }

   return 0;
}
