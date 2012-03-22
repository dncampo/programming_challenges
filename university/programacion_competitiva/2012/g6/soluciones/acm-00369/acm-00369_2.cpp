/**
 * Title: Combinations
 * URL: http://online-judge.uva.es/p/v3/369.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   En esta solución se factorizan los número del 2 al 100 en producto de número primos.
   Luego se calcula el factorial del numerador y el producto de factoriales del denominador 
   pero mediante la factorización de los números.
   Luego se hace una "aritmética de factores" y se descuentan en el numerador
   los factores (y su multiplicidad) que aparecen en el denominador.
   Luego en el numerador ya tenemos la respuesta (expresada en factores de 
   números primos)
**/


#include <iostream>
#include <cstring>
#include <cmath>

#define MAX_N 100
#define PRIMES 25

using namespace std;

unsigned primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, \
   53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

unsigned factorized [MAX_N + 1][PRIMES] = {{0}};

void factorization () {
   for (unsigned i = 2; i <= MAX_N; i++) {
      unsigned num = i, j = 0;

      while (num > 0 && j < PRIMES) {
         while (0 == num % primes[j] && num > 1) {
            num /= primes[j];
            factorized[i][j]++;
         }
         j++;
      }
   }
}



int main () {
   unsigned N, M;
   
   factorization ();
   
   while (cin >> N >> M) {
      if (0 == (N|M)) {
         break; //o return
      }

      unsigned num[PRIMES] = {0};
      
      for (unsigned i = 2; i <= N; i++) {
         for (unsigned j = 0; j < PRIMES; j++) {
            num[j] += factorized[i][j];
         }
      }
       
       
      unsigned den_tmp[PRIMES] = {0}; 
      for (unsigned i = 2; i <= M; i++) {
         for (unsigned j = 0; j < PRIMES; j++) {
            den_tmp[j] += factorized[i][j];
         }
      }      
      
      
      unsigned den[PRIMES] = {0};
      for (unsigned i = 2; i <= N - M; i++) {
         for (unsigned j = 0; j < PRIMES; j++) {
            den[j] += factorized[i][j];
         }
      }

      for (unsigned i = 0; i < PRIMES; i++) {
         den[i] += den_tmp[i];
      }
      
      
      for (unsigned i = 0; i < PRIMES; i++) {
         num[i] -= den[i];
      }

      
      unsigned res = 1;
      for (unsigned i = 0; i < PRIMES; i++) {
         
         if (num[i] > 0) {
            res *= (unsigned) pow ((double)primes[i], (double)num[i]);
         }
      }
         
      cout << N << " things taken " << M << " at a time is " << res << " exactly." << endl;

   }

   return 0;
}

