/** 
 * Title: Diagonal
 * URL: http://uva.onlinejudge.org/external/107/10784.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Observando los casos pequeños de n se puede ver que la cantidad de diagonales 'd' en un n-gono 
	(n lados) es: d = (1 / 2) * (n * (n - 3)). Luego despejando n, tenemos:
	n = (3 + sqrt(9 + 8*d)) / 2.
	Luego como debe ser n un número entero de lados, se le aplica la función techo(n) para dar con la
	respuesta.
**/


#include <iostream>
#include <cmath>

using namespace std;

int main(){
	unsigned long long diag;
	unsigned n_case = 1;
	while(1){
		cin >> diag;
		if(0 == diag) return 0;

		double sides = (3.0 + sqrt(9.0 + 8.0 * (double)diag ) ) / 2.0;
		unsigned res_sides = ceil(sides);
		
		cout << "Case " << n_case++ << ": " << res_sides << endl;
	}
	return 0;
}
