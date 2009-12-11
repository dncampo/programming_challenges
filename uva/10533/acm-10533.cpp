/**
 * Title: Digit Primes
 * URL: http://online-judge.uva.es/p/v105/10533.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan los primos en el rango [0,1000000].
	+ Se calculan los números que son "digit primes" en el rango [2,1000000], de forma acumulada. Es decir
	si en el rango [0, n1] hay un sólo digit prime, y el número n1+1 es un digit prime, entonces 
	acum_digit_primes[n1+1] = acum_digit_primes[n1] + 1.
	+ Luego, para el rango [t1, t2], se imprime la diferencia de "acum_digit_primes[t2] - acum_digit_primes[t1]".

**/


#include <iostream>
#include <cmath>
#include <cstring>

#define SIZE 1000001

using namespace std;

unsigned char list[SIZE];
unsigned acum_digit_primes[SIZE];

inline unsigned how_many_digit_primes (unsigned t1, unsigned t2) {
	unsigned cnt = acum_digit_primes[t2] - acum_digit_primes[t1];
	if (acum_digit_primes[t1] - acum_digit_primes[t1 - 1]) cnt++;
	return cnt;
}

unsigned sum_dig (unsigned i ) {
	unsigned sum = 0;
	do {
		sum += i % 10;
	 } while ( (i = i / 10) );

	return sum;
}

void criba(unsigned limit){
	memset(list, 1, sizeof(list));
	list[0] = list[1] = 0;
	unsigned d_limit = (unsigned) (sqrt(limit));

	for(unsigned i=2; i<=d_limit; i++){
		if(list[i]){
			for(unsigned j=2; j*i<=limit; j++){
				list[j*i] = 0;
			}
		}
	}
	for (unsigned i = 2; i < SIZE; i++) {
		if ( list[i] && list [ sum_dig (i)] ) {
			acum_digit_primes[i] = acum_digit_primes[i-1] + 1;
		}
		else {
			acum_digit_primes[i] = acum_digit_primes[i-1];
		}
	}
}


int main() {
	unsigned n_cases, t1, t2;

	criba(SIZE - 1);

	scanf ("%u", &n_cases);
	for (unsigned i = 0; i < n_cases; i++) {
		scanf ("%u%u", &t1, &t2);
		if (t1 > t2) {
			t1 ^= t2;
			t2 ^= t1;
			t1 ^= t2;
		}
		printf ("%u\n", how_many_digit_primes (t1, t2));
	}
	return 0;
}

