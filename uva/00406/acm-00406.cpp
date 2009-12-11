/**
 * Title: Prime Cuts
 * URL: http://uva.onlinejudge.org/external/4/406.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se generan los número primos hasta el límite N y se los carga en un vector.
	+ Se setean los índices a y b que se corresponden con el rango a imprimir.

**/


#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define SIZE 1001

using namespace std;

char list[SIZE];

vector<unsigned> criba (unsigned limit){

   memset (list, 1, sizeof(list));
   unsigned d_limit = (unsigned) (sqrt(limit));
   for (unsigned i = 2; i <= d_limit; i++){ //se descarta los que no son primos
      if (list[i]){
         for (unsigned j = 2; j*i <= limit; j++){
            list[j*i] = 0;
         }
      }
   }

	vector <unsigned> primes;
	for (unsigned i = 1; i <= limit; i++) { //juntar los primos en un vector;
			if (list[i])
				primes.push_back(i);
	}

	return primes;
}

int main () {

	unsigned  N, C;
	while (cin >> N >> C) {
		vector<unsigned> primes = criba(N);
		
		cout << N << " " << C << ": ";

		C = (primes.size() & 1) ? (C << 1) - 1: C << 1; //Actualizar el valor de C: cantidad a imprimir

		unsigned a,b;
		if (C > primes.size()) {
			a = 0; b = primes.size() - 1; //imprimir todos los primos
		}
		else { //imprimir el rango correspondiente
			a = (primes.size() - C) >> 1;
			b = a + C - 1;
		}

		for (unsigned i = a; i < b; i++ ) //imprimir!
			cout << primes[i] << " ";
		cout << primes[b] << endl << endl;
	}
	return 0;
}
