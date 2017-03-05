http://www.spoj.com/problems/FACTCG2/

#include <cstdio>
#include <cmath>
#include <cstring>

#define SIZE 10000001
#define NUM_PRIMES 664579
             
using namespace std;

char list[SIZE];
unsigned primes[NUM_PRIMES];


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
}

int main() {
	criba(SIZE-1);	
	list[0] = 0, list[1] = 0;
	unsigned j=0;
	for (unsigned i=2; i<SIZE; i++) {
		if (list[i]) {
			primes[j++] = i;
		}
	}
	
	unsigned n, i;
	while (scanf("%u", &n) > 0) {
		i=0;
		printf("1");
		if (list[n]) {
			printf(" x%u\n",n);
			continue;
		}
		else {
			while (n > 1) {
				while (0 == n % primes[i]) {
					printf(" x%u", primes[i]);
					n /= primes[i];
				}
				i++;
			}
		}
		printf("\n");
	}
	
	return 0;
}

