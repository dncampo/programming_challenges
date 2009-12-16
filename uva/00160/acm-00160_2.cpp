#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

char list[101];
vector <unsigned> primes;

void criba (int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
   for (unsigned i = 2; i <= 100; i++) {
      if (list[i]) {
         primes.push_back (i);
      }
   }
}

void solve (unsigned n) {
   vector<unsigned> factors;
   unsigned i = 1;
   unsigned long long res = 2;
   while (i <= n) {
      while ( divide (res,primes[i]) )

   }

}

int main () {
   unsigned n;
   while (cin >> n){
      if (!n) return;

      solve (n);
   }


   return 0;
}
