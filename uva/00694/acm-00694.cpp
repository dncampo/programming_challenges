/**
 * Title: The Collatz Sequence
 * URL: http://online-judge.uva.es/p/v6/694.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Problema muy parecido al "3n + 1", en el que se genera la secuencia hasta llegar a 1 ó
	hasta que se sobrepasa un límite L.
	+ Se cuentan los términos a medida que se generan.

**/

#include <iostream>

using namespace std;

int main () {
	long long A, L;
	unsigned n_case = 1, terms;

	while (cin >> A >> L) {
		if (-2 == A + L) return 0; //both are -1
		
		cout <<  "Case " << n_case << ": A = " << A << ", limit = " << L;
		n_case++;
		terms = 1;
		while (A <= L && A != 1) {
			if (A & 1) //A is odd
				A = 3 * A + 1;
			else
				A >>= 1;

			terms++;
		}
		if (A > L) terms--; //Last term does not count

		cout << ", number of terms = " << terms << endl;
	}

  return 0;
}
