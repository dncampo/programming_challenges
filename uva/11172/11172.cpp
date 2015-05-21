/**
 * Title: Relational Operators
 * URL: http://uva.onlinejudge.org/external/111/11172.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Direct approach.

**/


#include <iostream>

using namespace std;

int main(){
	int n_cases = 1, a, b;

	cin >> n_cases;

	for (int i=0; i<n_cases; i++) {
		cin >> a >> b;
		
		if (a > b) cout << ">\n";
		else if (a < b) cout << "<\n";
		else cout << "=\n";
	}
	
	return 0;
}

