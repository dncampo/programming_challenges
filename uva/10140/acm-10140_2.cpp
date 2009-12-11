/**
 * Title: Prime Distance
 * URL: http://online-judge.uva.es/p/v101/10140.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan los primos en el rango necesitado y se conlocan en un vector. Luego se recorre dicho
	vector en busca de los primos adyacentes más cercanos y más lejanos.

**/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define SIZE 1000001

using namespace std;

char list[SIZE];

vector <int> criba(int L,int U){
	int d = U-L+1;
	int d_limit = (int) (sqrt(U));

	memset(list, 1, sizeof (char [d]));

	for(int i = (L & 1); i < d; i += 2){
		list[i] = 0;
	}

	for(int i = 3; i <= d_limit; i += 2) {
		if (i > L && !list[i-L]) continue;

		int j = L / i*i;

		if (j < L) j += i;
		if (j == i) j += i;
		j-=L;
		for (; j < d; j += i)
			list[j]=0;
	}

   if (L <= 1) list[1-L] = 0;
   if (L <= 2) list[2-L] = 1;

	vector <int> primes; //juntar los primos del rango en un vector
	for (int i = 0; i < d; i++) {
		if (list[i]) primes.push_back (L + i);
	}

	vector<int> pair (4, -1);
	pair[2] = -1,  pair[3] = -1;
	int min = 1000000, max = -1;

	for (unsigned i = 1; i < primes.size() ; i++) { //se los recorre
		if ( (primes[i] - primes[i - 1]) < min) { //en busca de los más cercanos
			pair[0] = primes[i - 1];
			pair[1] = primes[i];
			min = primes[i] - primes[i - 1];
		}

		if ( (primes[i] - primes[i - 1]) > max) { //y más lejanos
			pair[2] = primes[i - 1];
			pair[3] = primes[i];
			max = primes[i] - primes[i - 1];
		}
	}
	return pair;
}

int main () {

	unsigned L, U;

	while (cin >> L >> U) {
		vector<int> pair = criba (L, U);

		if (-1 == pair[0]) cout << "There are no adjacent primes." << endl;
		else cout << pair[0] << "," << pair[1] << " are closest, " \
			<< pair[2] << "," << pair[3] << " are most distant." << endl;
	}
	return 0;
}

