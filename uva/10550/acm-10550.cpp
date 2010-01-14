/**
 * Title: Combination Lock 
 * URL: http://online-judge.uva.es/p/v105/10550.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Dado que se deben realizar sí o sí 3 vueltas completas (2 sentido horario al principio
	y 1 sentido antihorario antes de introducir el 2do. número de la clave) se almacena inicialmente
	en el resultado el valor de 1080 grados (3 * 360 grados).
	+ Al ser 40 números (0 a 39) por cada número se hacen 360 grados / 40 = 9 grados de giro.
	+ Tener en cuenta sí se debe hacer un giro horario o antihorario dependiendo del número del código
	que se esté introduciendo.
	+ Por ejemplo si se pasa de 0 a 30 y se debe girar sentido horario se harán 10 * 9 grados = 90 grados 
	(el 10 es debido a 40 - 30 + 0. Ver dibujo en descripción del problema), pero si se debe girar 
	en sendido antihorario se harán 30 * 9 grados = 270 grados.
	+ Luego, considerando lo anterior, se cuentan los grados que se realizan pasando de un número a 
	otro del código.
**/


#include <iostream>

using namespace std;

int main() {

	int start, a, b, c, degress;
	
	while (cin >> start >> a >> b >> c) {
		if (0 == start && 0 == a && 0 == b && 0 == c) return 0;
	
		degress = 1080;

		// start ==> a
		if (a >= start) {
			degress += (40 - a + start) * 9;
		}
		else {
			degress += (start - a) * 9;
		}

		// a ==> b	
		if (b <= a) {
			degress += (40 - a + b) * 9;
		}
		else {
			degress += (b - a) * 9;
		}


		// b ==> c
		if (c >= b) {
			degress += (40 - c + b) * 9;
		}
		else {
			degress += (b - c) * 9;
		}


		cout << degress << endl;
	}


	return 0;
}
