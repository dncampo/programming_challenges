/**
 * Title: Hangover
 * URL: https://www.spoj.pl/problems/HANGOVER/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se va sumando el resultado de aplicar '1/(n + 1)' hasta igualar o sobrepasar el valor 'c'
	requerido, devolviendo el número 'n' de cartas.

**/

#include <iostream>

using namespace std;

int main(){
	float c;
	
	while(1){
		cin >> c;
		unsigned cant = 0;
		float sum = 0.00f;
		
		if(0.00f == c)
			return 0;
		
		while(sum < c){
			cant++;
			sum += 1.00f / (float)(cant + 1);	
		}
		
		cout << cant << " card(s)" << endl;
	}
	return 0;
}
