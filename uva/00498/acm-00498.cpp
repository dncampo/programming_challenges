/**
 * Title: Polly the Polynomial
 * URL: http://online-judge.uva.es/p/v4/498.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utilizan los flujos de C++ para el tratamiento de la entrada.
	+ Los coeficientes se almacenan en un vector.
	+ La función evaluate, evalúa el polinomio en un punto x, dados ambos como parámetro.
	Además imprime	el resultado.

**/


#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void evaluate (vector<int> &coef, int val) {
	int res = 0;
	for (unsigned i = 0, j = coef.size() - 1; i < coef.size(); i++, j--)
		res += (int)pow((double)val, (double)j) * coef[i];

	cout << res;
}

int main () {
	string coefs, values;
	
	while (getline (cin, coefs)){
		getline (cin, values);
		stringstream ss1(coefs), ss2(values);
		
		vector <int> int_coef;
		int num;
		while (ss1 >> num)
			int_coef.push_back (num);
	
		int a_val;
		bool first = true;
		while (ss2 >> a_val) {
			if (!first)
				cout << " ";
			first = false;
			evaluate (int_coef, a_val);
		}

		cout << endl;
	}

	return 0;
}
