/**
 * Title: Conversions
 * URL: https://www.spoj.pl/problems/GNY07B/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Tener en cuenta la precisión y el 'fixed' (cantidad fija de decimales) de la salida.
**/


#include <iostream>
#include <iomanip>

#define kg_lb 2.2046
#define lb_kg 0.4536
#define l_g 0.2642
#define g_l 3.7854

using namespace std;

int main(){
	unsigned cases;
	cin >> cases;
	float val;
	string unit;
	for(unsigned i = 0; i < cases; i++){
		cin >> val >> unit;
		
		cout << fixed;
		if(unit == "kg")
			cout << i+1 << " " << setprecision (4) << val * kg_lb << " lb" << endl;
		else if(unit == "lb")
			cout << i+1 << " " << setprecision (4) << val * lb_kg << " kg" << endl;
		else if(unit == "l")
			cout << i+1 << " " << setprecision (4) << val * l_g << " g" << endl;
		else
			cout << i+1 << " " << setprecision (4) << val * g_l << " l" << endl;
	}
	return 0;
}
