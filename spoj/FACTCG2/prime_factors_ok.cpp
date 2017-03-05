http://www.spoj.com/problems/FACTCG2/

#include <stdio.h>
#include <math.h>
#include <string.h>


#define SIZE 10000007
#define NUM_PRIMES 664579

using namespace std;

char list[SIZE];
unsigned primes[NUM_PRIMES];


void sieve(int limit) {
   int i, j;
   
   memset(list, 0, SIZE * sizeof(char));
   for(i = 2; i*i < SIZE; i++) {
      if(list[i] == 0) {
          for(j = i*i; j < SIZE; j += i) {
               if(list[j] == 0) list[j] = i;
         }
      }
   }
//printf("2402473: %u", list[2402473]);    
}

void printFactor(int num) {
	if(num == 1) {
		printf("1\n");
		return;
	}
	else {
		printf("1");
		while(list[num] != 0 && num % list[num] == 0) {
			printf(" x %d", list[num]);
			if(list[num]==0) break;
			num /= list[num];
			//if(sieveTable[num] == 0)	break;
		}   
		printf(" x %d\n", num);
	}
}

int main() {
	sieve(SIZE);	
	list[0] = 0, list[1] = 0;
	unsigned j=0;

	unsigned n, i;
	while (scanf("%u", &n) > 0) {
		printFactor(n);
	}	
	return 0;
}
