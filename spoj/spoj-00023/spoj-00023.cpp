/**
 * Title: Pyramids 
 * URL:https://www.spoj.pl/problems/PIR/
 * Resources of interest:
	http://www.mathpath.net/tetrahedron.php
	
 * Solver group: Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Para cada caso de prueba, se calcula y imprime la solucion.
	+ Para calcular la solucion se aplica la formala que esta en 
	* la URL que se cita en "Resources of interest".
**/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int cases;
	double u, v, w, U, V, W; // por las dudas, puede ser int pero el enunciado no aclara.
	double result;

	cin >> cases;

	for(int i = 0 ; i < cases; i++) {
		cin >> v >> U >> W >> w >> u >> V;

		// calculamos el volumen con la formula correspondiente
		result = sqrt(4*u*u*v*v*w*w-u*u*(v*v+w*w-U*U)*(v*v+w*w-U*U) -
		              v*v*(w*w+u*u-V*V)*(w*w+u*u-V*V) - w*w*(u*u+v*v-W*W)*(u*u+v*v-W*W) +
                   (v*v+w*w-U*U)*(w*w+u*u-V*V)*(u*u+v*v-W*W))/12; 

		// imprimir el resultado de acuerdo al formato requerido por el problema
		cout << fixed << setprecision(4) << result  << endl;
	}

	return 0;
}
