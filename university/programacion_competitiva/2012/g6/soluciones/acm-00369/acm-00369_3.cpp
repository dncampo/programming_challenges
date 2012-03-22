/*
Básicamente esta solución lo que hace es simplificar (entre num y dem) lo mayor posible.
Esto puede ser eliminando, tanto desde el numerador como del denominador, (N-M)! o M!
*/

#include <iostream>

using namespace std;

long double mul (unsigned a, unsigned b) {
   long double ret;
   
   for (ret = 1; a <= b; a++) {
      ret *= a;
   }
   
   return ret;
}

int main () {
   long double N, M, num, den;
   
   while (cin >> N >> M) {
      if (0 == N) {
         break; //o return
      }
      
      if ((N - M) < M) {
         num = mul (M + 1, N);
         den = mul (1, N - M);
      }
      else {
         num = mul (N - M + 1, N);
         den = mul (1, M);
      }

      long double result = num / den;
            
      cout << N << " things taken " << M << " at a time is " << (unsigned)result << " exactly." << endl;

   }


   return 0;
}

