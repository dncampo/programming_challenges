/** 
 * Title: Self Numbers 
 * URL: http://online-judge.uva.es/p/v6/640.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para cada número N del 1 al 1000000 se generea el próximo d(N). Luego en un
   arreglo, not_self, se guarda en la posición d(N) un valor verdadero. not_self[d(N) = 1
   quiere decir que el número d(N) no es self number (ya que se puede generar a partir de N.
   Luego se recorre dicho arreglo y se imprimen los índeces que posean un 0 como valor (self
   numbers)   
	
**/


#include <iostream>

#define SIZE 1000001

using namespace std;

int not_self[SIZE];

int main () {

	not_self[0] = 1;

	for (unsigned i = 1; i < SIZE; i++){
		unsigned sum = i, tmp = i;
		while (tmp > 0){
			sum += tmp % 10;
			tmp /= 10;
		}
		not_self[sum] = 1;
	}
	
	for (unsigned j = 0; j < SIZE; j++){
		if (0 == not_self[j]) cout << j << endl;
	}
	return 0;
}

