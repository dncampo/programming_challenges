/**
 * Title: Tables
 * URL: https://www.spoj.pl/problems/AE1B/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se ordena el vector de tornillos y se empieza a sumar desde el mayor valor, hasta igualar o
	superer el valor k*s (cant. de tornillos por mesa y cant. de mesas a construir)

**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n,k,s;
	
	while(cin >> n >> k >> s){
		vector<unsigned> screws(n);
		for(unsigned i = 0; i < n; i++){
			cin >> screws[i];
		}	
		sort(screws.begin(), screws.end());

		unsigned sum = 0, m=1, need = k*s;

		for(int l = n - 1; (l >= 0) && (sum < need); m++, l--){
			sum += screws[l];

			if(sum >= need){
				cout << m << endl;
				//break;
			}
		}
	}	
	return 0;
}
