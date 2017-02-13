/**
 * Title: Harry and big doughnuts
 * URL: http://www.spoj.pl/problems/DOUGHNUT/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se multiplica la cantidad de gatos por el peso de cada dona. Si es menor o igual al peso que
	Harry puede llevar se imprime 'yes'. Caso contrario se imprime 'no'.
**/

#include <iostream>

using namespace std;
int t,c,k,w,a;
int main(){	
	cin >> t;
	for(; a < t; a++){
		cin >> c >> k >> w;
		c*w <= k ? cout << "yes" : cout << "no";
		cout << endl;
	}
	return 0;
}

//EOF
