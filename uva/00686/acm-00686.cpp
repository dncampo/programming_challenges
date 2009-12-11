/** 
 * Title: Goldbach's Conjecture (II)
 * URL: http://online-judge.uva.es/p/v6/686.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Solución similar a la del problema Goldbach's Conjecture.

**/

#include <iostream>
#include <cmath>
#include <cstring>

#define SIZE 32768
             
using namespace std;

char list[SIZE];

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

	criba(SIZE);

	unsigned num;
	while (cin >> num) {
		if (0 == num) return 0;
		
		unsigned a = 2;

		unsigned count = 0;
		while (a <= (num >> 1)){ //only check to half
			if ( (1 == list[num - a]))	count++; //it's prime
			while (1 != list[++a]); // next 'a' prime		
		}
		
		cout << count << endl;
	}
	

   return 0;
}


