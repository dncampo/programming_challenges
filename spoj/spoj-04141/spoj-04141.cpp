#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <cstdio>

#define SIZE 1000001

using namespace std;

char list[SIZE];
vector<unsigned> primes;
unsigned res[SIZE];

void criba(int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int)(sqrt(limit));
   list[1] = 0;
   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
   for (unsigned i = 2; i < SIZE; i++) {
      if (list[i]) {
         primes.push_back(i);
      }
   }
}

unsigned solve(const unsigned n) {
   set<unsigned> factors;

   unsigned i = 0, nn = n;
   while (nn > 1) {
      unsigned p = primes[i];
      while (0 == (nn % p)) {
         factors.insert(p);
         nn /= p;
      }
      i++;
   }
   float parcial = 1.0;
   for (set<unsigned>::const_iterator it = factors.begin(); it != factors.end(); it++) {
      parcial *= (1.0 - 1.0 / (float)*it);
   }
   res[n] = (n * parcial);
   return res[n];
}

int main() {
   criba(SIZE - 1);

   unsigned n_cases, num;

   scanf("%u", &n_cases);
   for (unsigned i = 0; i < n_cases; i++) {
      scanf("%u", &num);
      if (list[num]) {//it's prime
         printf("%u\n", num - 1);
      }
      else {
         if (0 == res[num]) {
            printf("%u\n", solve(num));
         }
         else {
            printf("%u\n", res[num]);
         }
      }
   }
   return 0;
}