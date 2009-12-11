/** 
 * Title: Power et al.
 * URL: http://online-judge.uva.es/p/v105/10515.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Tener cuidado debido a que los números m y n pueden llegar a ser muy grandes (< 10^101), 
   y sólo nos interesan las últimas cifras de dichos números. Es por esto que debemos leerlos
   como string.
   + Luego precalculamos los valores de las potencias para distintas bases, ya que se producen 
   ciclos. Los ciclos (del último número) dependen de la base y el exponente de la potencia que
   estamos calculado, así:
   por ejemplo cualquier base que termine en 4, tendrá ciclos entre 4 y 6:
   4^1 = 4, 4^2 = 16, 4^3 = 64, 4^4 = 256, ....., 4^27 = 18014398509481984, ...
**/

#include <iostream>
#include <cstdlib>

//ciclos
unsigned two[]   = {6, 2, 4, 8,};
unsigned three[] = {1, 3, 9, 7,};
unsigned four[]  = {6, 4};
unsigned seven[] = {1, 7, 9, 3};
unsigned eight[] = {6, 8, 4, 2};
unsigned nine[]  = {1, 9};

using namespace std;

int main(){
	string base, exp;

	while (cin >> base >> exp){
		if ("0" == base && "0" == exp) return 0;
		
		if ("0" == exp) {
			cout << "1" << endl;
			continue;
		}

		int b = base[base.size() - 1] - '0';
		int e;

		if (1 == exp.size()) e = atoi(exp.substr(exp.size() - 1).c_str());
		else e = atoi(exp.substr(exp.size() - 2).c_str());
		
		switch (b) {
			case 0:
			case 1:
			case 5:
			case 6:
				cout << b << endl; //Estos números no tienen ciclo, terminan siempre igual
				break;

			case 2:
				cout << two[e % 4] << endl;
				break;

			case 3:
				cout << three[e % 4] << endl;
				break;
		
			case 4:
				cout << four[e % 2] << endl;
				break;

			case 7:
				cout << seven[e % 4] << endl;
				break;
				
			case 8:
				cout << eight[e % 4] << endl;
				break;

			case 9:
				cout << nine[e % 2] << endl;
				break;
		};
	}
	
	return 0;
}

