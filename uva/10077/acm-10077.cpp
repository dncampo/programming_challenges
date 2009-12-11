/**
 * Title: The Stern-Brocot Number System
 * URL: http://online-judge.uva.es/p/v100/10077.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se hace una búsqueda binaria con el valor al que se desea llegar. Se empieza con los valores
	iniciales de: (rama izquierda) L = 0/1, (centro) C = 1/1, (rama derecha) R = 1/0. Luego si el valor
	al que deseo llegar (goal) es menor que el actual (C) voy por rama izquierda, sino por rama derecha.
	Al ir por una rama (sea izquierda o derecha) se llama recursivamente a solve con los nuevos valores
	de cada rama.

**/

#include <iostream>
#include <string>

using namespace std;

void solve (const unsigned goal[], const double g, const unsigned L[], \
	const unsigned C[], const unsigned R[], string& res) {

	if (C[0] == goal[0] && C[1] == goal[1]) {
		cout << res << endl;
		return;
	}

	unsigned LB[2] = { L[0] + C[0], L[1] + C[1] }; //posible próxima rama izquierda...
	unsigned RB[2] = { R[0] + C[0], R[1] + C[1] }; //...y derecha
	double c  =    (double)C[0] /  (double)C[1];

	if (g <= c) { //left branch
		res += 'L';
		solve (goal, g, L, LB, C, res);
	}

	else {
		res += 'R';
		solve (goal, g, C, RB, R, res);
	}
}

int main () {
	unsigned goal[2];
	unsigned L[2]  = {0,1}; //valores iniciales
	unsigned C[2]  = {1,1};
	unsigned R[2]  = {1,0};

	while (cin >> goal[0] >> goal[1]) {
		if ( (1 == goal[0]) && (1 == goal[1]) ) return 0;

		string res = ""; //solución inicial
		double g  = (double)goal[0] / (double)goal[1];
		solve (goal, g, L, C, R, res);
	}

	return 0;
}
