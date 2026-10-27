/**
 * Title: 8 Queens Chess Problem
 * URL: http://uva.onlinejudge.org/external/7/750.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la técnica de backtracking para resolver este problema.
	+ Se usa un vector<int> de tamaño 8. En la posición i se almacena un valor j que representa la columna
	i y la fila j en la que se coloca una reina. Inicialmente el vector tiene -1's, excepto en la posición
	fija exigida por la entrada.
	+ A medida que con el backtracking se van "llenando" las correspondientes posiciones, se va contando
	la cantidad de reinas colocadas. Una solución es aquella en la que se llega a un estado con 8 reinas
	colocadas.
	+ La función get_candidates se encarga de llenar un vector con potenciales candidatos para una posición y
	estado del tablero dado.
	+ Un detalle de implementación: se trabaja con índices comenzando desde 0, hasta 7 inclusive.
**/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


vector<int> data;
unsigned filled;
unsigned solutions;


bool is_solution(){
	if (8 == filled) return true;
	return false;
}

void process_solution(){
	cout.width(2);
	cout << ++solutions << "     ";
	cout.width(0);
	for (unsigned i = 0; i < 8; i++)
		cout << " " << data[i] + 1;
	cout << endl;
}

void check_diagonal (unsigned i, unsigned pos, vector<bool> &possible_cand) {
	int a,b, delta;
	
	delta = abs(int(pos - i)); //a que distancia del lugar a verificar estoy?
	a = data[i] - delta; //me desplazo en la diagonal hacia arriba
	b = data[i] + delta; // y hacia abajo
	if (a >= 0) possible_cand[a] = false; //si no me "salí" del tablero..
	if (b <  8) possible_cand[b] = false; //idem anterior
}

void get_candidates(vector<int> &candidates, unsigned pos){
	vector <bool> possible_cand(8,true);

	for (unsigned i = 0; i < data.size(); i++) {
		if (-1 != data[i]) {
			possible_cand[ data[i] ] = false; //filas usadas... no me sirven..
			check_diagonal (i, pos, possible_cand); // y las diagonales de esas filas?
		}
	}
	for (unsigned i = 0; i < 8; i++)
		if (possible_cand[i]) candidates.push_back(i); //que filas podemos usar?
}

void backtracking(unsigned pos){
	if(is_solution()){
		process_solution();
	}else{

		unsigned new_pos = pos + 1;
		vector<int> candidates;

		if (-1 == data[pos]) { //si esta vacía la columna actual
			get_candidates(candidates, pos);
			if (0 == candidates.size()) return;
		}
		else {
			backtracking(new_pos); // sino pasamos a la siguiente columna
		}

		for(unsigned i = 0; i < candidates.size(); i++){
			data[pos] = candidates[i];
			filled++;
			backtracking(new_pos);
			data[pos] = -1; //se deshace la última rama del BT creada
			filled--;
		}
	}
}

int main(){
	unsigned n_cases, r, c;
	
	cin >> n_cases;
	
	for (unsigned i = 0; i < n_cases; i++) {
		filled = 0;
		solutions = 0;
		data.clear();
		data = vector<int>(8,-1);
		cin >> r >> c;
		data[--c] = --r; //índices a partir de 0
		filled++;
		
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		backtracking(0);
		if (i < n_cases - 1)
			cout << endl;
	}
	return 0;
}
