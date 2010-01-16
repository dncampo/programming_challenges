/**
 * Title: Factoring Large Numbers
 * URL: http://online-judge.uva.es/p/v103/10392.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se generan los números primos hasta (2^16 - 1) que se los utilizarán
    para factorizar la entrada.
    + Se utiliza una función is_prime para determinar rápidamente si un número
    es o no primo.
    + Por cada número de entrada se lo divide por cada primo (a partir del 2),
    mientras el resto de esta división sea cero, y se le asigna a este número 
    el resultado de dicha división. Se continúa con este procedimiento hasta que
    el número de entrada se convierta en un número primo ó 1.
**/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define SIZE 65536
             
using namespace std;

char list[SIZE];
vector<unsigned> primes;

void criba(int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
   for (unsigned i = 2; i < SIZE; i++) {
      if (list[i])
         primes.push_back(i);
   }
}


bool is_prime(long long n){
   if(n < 2 ) return false;
   
   for (long long i = 2; i < (long long)sqrt(n) + 1; i++){
      if (n % i == 0) 
         return false;
   }
   return true;
}

int main() {
   
   criba (SIZE - 1);

   long long num;
   
   while (cin >> num) {      
      if (-1 == num) return 0;
     
      if (!is_prime(num)) {
         for (unsigned i = 0; (i < primes.size() && 1 < num); i++) {
            while ( 0 == (num % primes[i])) {
               cout << "    " << primes[i] << endl;
               num /= primes[i];
               if (is_prime(num)) {
                  cout << "    " << num << endl;
                  num = 0;
                  break;
               }
            }
         }
      }      

      else {
         cout << "    " << num << endl;
      }
      
      cout << endl;

   }
   return 0;
}

