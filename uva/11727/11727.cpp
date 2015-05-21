/**
 * Title: Cost cutting
 * URL: http://uva.onlinejudge.org/external/117/11727.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Direct approach.

**/


#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
	int n_cases, sal[30];

	cin >> n_cases;

	for (int i=0; i<n_cases; i++) {
		cin >> sal[0] >> sal[1] >> sal[2];
		sort(sal, sal+3);
		cout << "Case " << i+1 << ": " << sal[1] << "\n";
	}
	
	return 0;
}

