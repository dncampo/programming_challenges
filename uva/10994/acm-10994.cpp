/**
 * Title: Simple Addition
 * URL: http://uva.onlinejudge.org/external/109/10994.html
 * Resources of interest:
 * Solver group: David-Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Viendo la salida para algunos casos comprobamos que para todas las potencias de 10
    las salidas de la función S(p, q) siguen el patron descrito.
**/

#include<iostream>

using namespace std;

unsigned long long D(int n){
   switch(n){
      case 1:
         return 1;
      case 10:
         return 46;
      case 100:
         return 496;
      case 1000:
         return 4996;
      case 10000:
         return 49996;
      case 100000:
         return 499996;
      case 1000000:
         return 4999996;
      case 10000000:
         return 49999996;
      case 100000000:
         return 499999996;
      case 1000000000:
         return 4999999996LL;           
   }
   return 0;
}

unsigned long long f(int n){
   unsigned long long b = 1, t = 0, m;

   while(n > 0){
      m = n % 10;
      t += D(b) * m + ((m*(m-1)) >> 1);
      b *= 10;
      n /= 10;
   }

   return t;
}

int main(){
   int p, q;
   cin >> p >> q;
   
   while (p >= 0 || q >= 0) {
      cout << (f(q) - f(p-1)) << '\n';
      
      cin >> p >> q;
   }
   
   return 0;
}
