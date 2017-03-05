http://www.spoj.com/problems/FACTCG2/

#include <stdio.h>
#include <math.h>
#include <string.h>

//#define SIZE 10000000
#define SIZE 10000002
#define NUM_PRIMES 664579
             

char list[SIZE];
unsigned primes[NUM_PRIMES];


void sieve(int limit) {
   int i, j;
   
   memset(list, 0, sizeof(list) * sizeof(char));
   for(i = 2; i*i < SIZE; i++) {
      if(list[i] == 0) {
          for(j = i*i; j < SIZE; j += i) {
               if(list[j] == 0) list[j] = i;
         }
      }
   }
printf("2402473: %u", list[2402473]);    
}

void criba(int limit){
   unsigned d_limit = (unsigned) (sqrt(limit));
   unsigned i, j; 
   
   memset(list, 1, sizeof(list) * sizeof(char));
   
//printf ("list[SIZE-1]: %d\nsizeof(list): %u\n", list[SIZE-1], sizeof(list));
   for(i=2; i<=d_limit; i++){
      if(list[i]==1){
         for(j=2; j*i<=limit; j++){
            if (list[j*i] == 1) {
				list[j*i] = i;
			}
         }
      }
   }
//printf ("list[SIZE-1]: %d\n", list[SIZE-2]);      
}

int main() {
	unsigned j=0, n, i;
	
	//criba(SIZE);	
	sieve(SIZE);	
	list[0] = 0, list[1] = 0;	
/*	for (i=2; i<SIZE; i++) {
		if (list[i]==1) {
			primes[j++] = i;
		}
		else {
			//printf("%u: %u\n",i,list[i]);
		}
	}*/

	while (scanf("%u", &n) > 0) {
		i=0;
		printf("1");
		if (list[n] == 0) {
			printf(" x %u\n",n);
			continue;
		}
		else {
			//i=list[n];
			while (n > 1) {
				printf ("'%u' ", n);
				if (list[n] == 0) {
					printf(" x %u", n);
					break;
				}
				i=list[n];
				//while (0 == n % primes[i]) {
					printf(" x %u", i);
					n /= i;
				//}
				//i++;
			}
		}
		printf("\n");
	}
//printf ("list[SIZE-1]: %d\n", list[SIZE-1]);      	
	
	return 0;
}

