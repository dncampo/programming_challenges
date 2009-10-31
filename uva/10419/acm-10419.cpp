#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define SIZE 294
#define LAST_PRIME 293
#define TOTAL_PRIMES 62

             
using namespace std;

char list[SIZE];
unsigned primes[TOTAL_PRIMES];

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
	
	unsigned k = 0;
	for (unsigned j = 2; j < SIZE; j++)
		if (list[j]) primes[k++] = j;
	
}

int main(){
	criba(SIZE);

	unsigned N, t;

	while (cin >> N >> t){
		bool t_odd = false, N_odd = false;
		if (0 == N + t) return 0;
		if (t & 1) t_odd = true;
		if (N & 1) N_odd = true;

				
		
		
	
	}

//for (unsigned i = 250; i < SIZE; i++) cout << i << ": " << (int)list[i] << endl;

	return 0;
}

