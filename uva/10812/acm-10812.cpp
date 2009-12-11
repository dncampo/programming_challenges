/**
 * Title: Beat the Spread!
 * URL: http://online-judge.uva.es/p/v108/10812.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Si la suma (s) es menor que la diferencia (d) o si (s - d) es impar entonces el resultado es imposible.
	+ En otro caso, se debe resolver un sencillo sistema de 2 ecuaciones lineales con 2 incógnitas.

**/


#include <iostream>

using namespace std;

int main () {
	int n_cases, s, d;
	cin >> n_cases;
	
	for (int i = 0; i < n_cases; i++) {
		cin >> s >> d;
		
		if ((s < d) || (s - d) & 1)
			cout << "impossible" << endl;
		else
			cout << ((s - d) / 2) + d << " " << (s - d) / 2 << endl;

	}
	return 0;
}
