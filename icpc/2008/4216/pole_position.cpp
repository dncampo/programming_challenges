/**
 * Title: 4216 - Pole Position
 * URL: http://acmicpc-live-archive.uva.es/nuevoportal/region.php?r=sa&year=2008
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se va actualizando un vetor con las posiciones originales, verificando que no existan
   posiciones fuera de rango (es decir que la posición de un auto sea mayor que la cantidad de autos
   o que sea menor a 0) y que ninguna posición esté ocupada par más de un auto.

**/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned n_cars, car_num;
	int relative_pos;
	bool defective;
   vector<unsigned> original;
		   
   while (cin >> n_cars) {

	   if (0 != n_cars) {	      
		   defective = false;
		   original.assign(n_cars,0);

		   for (int i = 0; i < (int)n_cars; i++) {
			   cin >> car_num >> relative_pos;
			   if (!defective && i + relative_pos >= 0 && i + relative_pos < (int)n_cars && 0 == original[i + relative_pos]) {
				   original[i + relative_pos] = car_num;
			   }
			   else {
				   defective = true;
			   }
		   }		
	   }
	   else {
		   return 0;
	   }
	   
	   if (defective) {
	      cout << "-1" << endl;
	   }
	   else {
	      cout << original[0];
	      for (unsigned i = 1; i < n_cars; i++) {
	         cout << " " << original[i];
	      }
	      cout << endl;
	   }
   }
}

