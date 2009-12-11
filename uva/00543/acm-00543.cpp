/** 
 * Title: Goldbach's Conjecture
 * URL: http://online-judge.uva.es/p/v5/543.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan rápidamente los primos en el rango 0-999999.
   + Para cada número n de entrada, se comienza comprobando desde a = 3 y se
   busca ascendentemente un a primo, tal que se cumpla que (b = n - a) sea primo.
	
**/

#include <iostream>
#include <cmath>
#include <cstring>

#define SIZE 1000000
             
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
		
		unsigned a = 3;

		while (a <= (num - 3)){ 
			if (1 == list[num - a])	break; //it's prime
			else while (1 != list[++a]); // next 'a' prime
		}
		
		cout << num << " = " << a << " + " << num - a << endl;
	}
	

   return 0;
}


