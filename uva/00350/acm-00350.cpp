/** 
 * Title: Pseudo-Random Numbers
 * URL: http://online-judge.uva.es/p/v3/350.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se van generando los números pseudo-aleatorios y se verifica si ya se han
   generado. Si ya fueron producidos, entonces se busca en un arreglo, que mantiene
   el orden real de creación de los números, el número repetido en cuestión; 
   para poder retornar el tamaño del ciclo.
	
**/


#include <iostream>
#include <set>
#include <vector>

using namespace std;

unsigned get_length(int Z, int I, int M, int L) {
	set <int> sorted_data;
	vector<int> data;
	sorted_data.insert(L);
	data.push_back(L);
	
	while (true) {
		L = (Z * L + I) % M;
		set<int>::iterator element = sorted_data.find(L);
		
		if (sorted_data.end() == element) { //si el nuevo número no fue generado..
			sorted_data.insert(L);
			data.push_back(L);
		}
		else { // ya se genero un número igual al último
			unsigned i = 0;
			for (; i < data.size(); i++) // buscar cuando se genero
				if (data[i] == *element) break;
			return data.size() - i; // retornar el tamaño del ciclo
		}
	}
}


int main() {
	int Z, I, M, L, n_case = 1;
	
	while (cin >> Z >> I >> M >> L){
		if (0 == Z + I + M + L) return 0;		
		cout << "Case " << n_case++ << ": " << get_length(Z, I, M, L) << endl;	
	}

	return 0;
}

