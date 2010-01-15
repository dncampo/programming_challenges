/**
 * Title: Vito's family
 * URL: http://online-judge.uva.es/p/v100/10041.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacena la entrada en un vector, y se la ordena.
   + Se obtiene la mediana y se acumulan las diferencias con cada elemento
     del vector.

**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned n_cases, r;
	cin >> n_cases;

	for (unsigned i = 0; i < n_cases; i++) {
		cin >> r;
		vector<unsigned> vito(r);

		for (unsigned j = 0; j < r; j++) {
			cin >> vito[j];
		}
		sort(vito.begin(), vito.end());
		unsigned median = vito[r >> 1], result = 0;
	
		for (unsigned k = 0; k < r; k++) {
			result += (median < vito[k]? vito[k] - median : median - vito[k]);
		}
		cout << result << endl;
	}
	return 0;
}

