/** 
 * Title: To Carry or not to Carry
 * URL: http://online-judge.uva.es/p/v104/10469.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Realizar el XOR de los operandos
	
**/

#include <iostream>

using namespace std;

int main () {
	unsigned a, b;
	
	while (cin >> a >> b)
		cout << (a^b) << endl;
	return 0;
}

