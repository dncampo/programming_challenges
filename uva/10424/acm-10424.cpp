/**
 * Title: Love Calculator
 * URL: http://online-judge.uva.es/p/v104/10424.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se modulariza el problema con funciones para obtener la suma de las letras de una palabra y el valor
	en una unidad de dicha suma.

**/


#include <iostream>
#include <cctype>

using namespace std;

float ratio (unsigned a, unsigned b) {
	if (a > b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return ((float)a / b) * 100;
}

unsigned one_digit (unsigned sum) {
	unsigned res = 0;
	while (sum > 0) {
		res += sum % 10;
		sum /= 10;
	}

	while (res > 9) {
		res = one_digit (res);
	}
	return res;
}

unsigned sum (string& l) {
	unsigned sum = 0;
	for (unsigned i = 0; i < l.size (); i++) {
		if (isalpha (l[i])) {
			sum += tolower (l[i]) - 'a' + 1;
		}
	}
	return sum;
}

int main () {
	string line1, line2;
	
	while (getline (cin, line1)) {
		getline (cin, line2);
		printf ("%.2f %%\n", ratio (one_digit ( sum (line1) ), one_digit (sum (line2) )));
	}

	return 0;
}
