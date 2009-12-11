/**
 * Title: Number Steps 
 * URL: http://www.spoj.pl/problems/NSTEPS/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + 
**/


#include <iostream>

using namespace std;

int main(){
	unsigned x, y, cases;
	cin >> cases;
	
	for (unsigned i = 0; i < cases; i++){
		cin >> x >> y;
		
		if( (x != y) && !(x - 2 == y)){
			cout << "No Number" << endl;
			continue;
		}
		
		if(x == y){
			if (x & 1) {//odd
				cout << 2 * (x-1) + 1 << endl;
			}
			else {
				cout << 2 * x << endl;
			}
		}
		else {
			if(x & 1) {//odd
				if(x == 1) cout << "1" << endl;
				else cout << 1 + (2 * (x - 2)) << endl;
			}
			else {
				cout << 2 + (2 * (x - 2)) << endl;
			}
		}
	
	}	
	return 0;
}
