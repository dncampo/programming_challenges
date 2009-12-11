/** 
 * Title: Polynomial Showdown
 * URL: http://online-judge.uva.es/p/v3/392.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Apegarse al formato especificado de salida. Verificar bien los casos del primer
   y último coeficiente a imprimir, así como espacios en blancos.
	
**/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int coef[9];
	
	while (cin >> coef[0] >> coef[1] >> coef[2] >> coef[3] >> coef[4] \
		>> coef[5] >> coef[6] >> coef[7] >> coef[8]){
		
		bool prints = false;

		unsigned i = 0;
		while(0 == coef[i] && i < 9) i++;
		
		if(9 == i) { //all zeros
			cout << "0" << endl;
			continue;
		}
		
		// fisrt coef != 0
		if(8 > i){
			if(coef[i] < 0) {
				cout << "-";
				prints = true;
			}
			if(1 < abs(coef[i])) {
				cout << abs(coef[i]);
				prints = true;
			}
			if(i < 7) {
				cout << "x^" << 8-i;
				prints = true;
			}
			else if(7 == i) { 
				cout << "x";
				prints = true;
			}
		}
		
		i++;
		while(i < 8){
			if(0 == coef[i]) {
				i++;
				continue;
			}
			
			if(0 > coef[i]) cout << " - ";
			else cout << " + ";
			
			if(1 < abs(coef[i])) cout << abs(coef[i]);
			
			cout << "x";
			if (i < 7) cout << "^" << 8-i;
		
			i++;
			prints = true;
		}
		
		if(0 != coef[8]){
			if (prints == false){
				if (coef[8] < 0) cout << "-";
			}
			else{
				if (coef[8] < 0) cout << " - ";
				else cout << " + ";
			}
			cout << abs(coef[8]);
		}
		
		cout << endl;
	}

	return 0;
}

