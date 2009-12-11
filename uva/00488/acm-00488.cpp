/**
 * Title: Triangle Wave
 * URL: http://online-judge.uva.es/p/v4/488.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacenan las posibles amplitudes en un arreglo. Luego con un doble for se imprimen las correspondientes
	secueciencias.

**/

#include <iostream>

using namespace std;

unsigned values[] = { 0, 1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999 };

int main () {
	unsigned n_cases, amp, frec;
	
	cin >> n_cases;
	
	for (unsigned i = 0; i < n_cases; i++) {
		cin >> amp >> frec;
		
		for (unsigned j = 0; j < frec; j++) { //frecuencias
			for (unsigned k = 1; k < amp; k++) //creciente
				cout << values[k] << endl;
			for (unsigned k = amp ; k > 0; k--) //decreciente
				cout << values[k] << endl;
		
			if (j < frec - 1) cout << endl;
		}
		if (i < n_cases - 1) cout << endl;	
	}
}