/**
 * Title: Back to High School Physics
 * URL: http://online-judge.uva.es/p/v100/10071.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Dado un tiempo t y una velocidad constante v, se calcula la distancia recorrida por una 
	partícula en el tiempo 2*t.

**/

#include <iostream>

using namespace std;

int main(){
	short t,v;
	
	while(cin >> v){
		cin >> t;		
		cout << (2*t*v) << endl;	
	}	
	return 0;
}
