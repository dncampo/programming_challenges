/**
 * Title: Prime Ring Problem
 * URL: http://online-judge.uva.es/p/v5/524.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la técnica de backtracking para resolver este problema.
	+ Para los casos impares de n no hay solución, excepto para 1.

**/


#include <cstdio>
#include <vector>

using namespace std;

vector<unsigned> data;
unsigned filled, n;


bool is_solution(){
	if (n == filled) return true;
	return false;
}


void process_solution(){
	for (unsigned i = 0; i < n - 1; i++) printf ("%u ", data[i]);
	printf ("%u\n", data[n-1]);
}


inline bool is_prime (unsigned i) { //para el rango que se trabaja es suficiente con estos primos
	return (3 == i || 5 == i || 7 == i || 11 == i || 13 == i || 17 == i || \
		19 == i || 23 == i || 29 == i || 31 == i);
}


void get_candidates(vector<int> &candidates){
	vector <bool> possibles (n + 1, false);

	unsigned last = data[filled - 1];
	//si el último fue par, uso un impar y viceversa. Luego incrementamos de a dos
	for (unsigned i = (last & 1)?  2: 3; i <= n; i += 2) {

		unsigned sum = i + last;
		if (n - 1 == filled) { //si es la última posición a llenar, verificar con el primero y el último...
			if (is_prime (i + 1) && is_prime (sum)) {
				possibles[i] = true;
			}
		}
		else { //..sino sólo verificar que el candidato sea primo si se suma al último.
			if (is_prime (sum)) {
				possibles[i] = true;
			}
		}
	}

	for (unsigned i = 0; i < filled; i++) //los ya usados, los descartamos
		possibles[ data[i] ] = false;

	for (unsigned i = 2; i < n + 1; i++) { //por fin, los candidatos
		if (possibles[i])
			candidates.push_back (i);
	}
}


void backtracking(){
	if(is_solution()){
		process_solution();
	}else{

		vector<int> candidates;

		get_candidates(candidates);

		for(unsigned i = 0; i < candidates.size(); i++){
			data[ filled++ ] = candidates[i];
			backtracking();
			filled--;
		}
	}
}


int main(){
	unsigned n_case = 1;

	while (~scanf ("%u", &n)) {
		if (1 != n_case) printf ("\n");
	
		printf ("Case %u:\n", n_case++);
		if (n & 1) { //para los impares no hay solución...
			if (1 == n) printf ("1\n"); //...excepto en el caso 1
		}
		else {
			data = vector<unsigned> (n, 0);
			data[0] = 1;
			filled = 1;
			backtracking ();
		}
	}
	return 0;
}

