/**
 * Title: Prime Frequency
 * URL: http://online-judge.uva.es/p/v107/10789.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacenan los caracteres y sus frecuencias en un map y luego se lo recorre para imprimir las
	frecuencias que sean "primos"

**/


#include <iostream>
#include <cmath>
#include <map>

using namespace std;

bool is_prime(unsigned n){
   if(n < 2 ) return false;

   for (unsigned i = 2; i < (unsigned)sqrt(n) + 1; i++){
      if (n % i == 0)
         return false;
   }
   return true;
}

int main () {
	unsigned n_cases, cnt = 1;;
	cin >> n_cases;

	string line;
	for (unsigned i = 0; i < n_cases; i++, cnt++) {
		cin >> line;
		map <char,unsigned> m;
		
		for (unsigned j = 0; j < line.size (); j++) {
			m[ line[j] ]++; //una ocurrencia más...
		}
		cout << "Case " << cnt << ": ";

		unsigned c = 0;
		for (map<char, unsigned>::const_iterator it = m.begin (); it != m.end (); it++) {
			if (is_prime (it->second) ) { //si es primo..
				cout << it->first;
				c++;
			}
		}

		if (0 == c) {
			cout << "empty";
		}
		cout << endl;
	}

	return 0;
}
