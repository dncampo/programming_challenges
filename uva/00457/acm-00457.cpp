/**
 * Title: Linear Cellular Automata
 * URL: http://online-judge.uva.es/p/v4/457.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Problema de simulación.
	+ Se utiliza un vector para guardar los datos correspondientes a cada día. También se utiliza un
	vector auxiliar para no ir sobreescribiendo los valores del día anterior que se necesitan para obtener
	los valores del día actual.
	+ El vector de "dishes" tiene un elemento más por izquierda y por derecha para poder hacer con facilidad
	las sumas del elemento actual con el anterior y el posterior sin necesidad de hacer verificación de
	rangos del mismo.
**/

#include <iostream>
#include <vector>

using namespace std;

int main () {
	unsigned n_cases;
	cin >> n_cases;

	for (unsigned i = 0; i < n_cases; i++) {
		vector<unsigned> DNA (10);
		for (unsigned j = 0; j < 10; j++)
			cin >> DNA[j];

		vector <unsigned> dishes (42,0); //guardo lugar para almacenar un primero y último "ficticio"
		dishes[20] = 1;

		for (unsigned m = 0; m < 50; m++) {
			//imprimir la simulación del día.
			for (unsigned i = 1; i < 41; i++) {
				switch (dishes[i]) {
					case 0: cout << " "; break;
					case 1: cout << "."; break;
					case 2: cout << "x"; break;
					case 3: cout << "W"; break;
				}
			}
			cout << endl;

			//simular día siguiente..
			vector <unsigned> actual_day = dishes; //para no sobreescribir los valores actuales.
			for (unsigned p = 1; p < 41; p++) {
				unsigned K = dishes[p - 1] + dishes[p] + dishes[p + 1];
				actual_day[p] = DNA[K];
			}
			dishes = actual_day;
		}

		if (i < n_cases - 1) cout << endl;
	}
	return 0;
}
