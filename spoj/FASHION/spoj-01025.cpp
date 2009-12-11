/**
 * Title: Fashion Shows
 * URL: https://www.spoj.pl/problems/FASHION/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Hay que ordenar los vectores de hombres y mujeres para maximizar el 'bond'

**/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
	int cases, quant;
	cin >> cases;
	for(int a = 0; a < cases; a++){
		cin >> quant;
		vector<int> men(quant), women(quant),bond(quant);
		for(int b = 0; b < quant; b++) cin >> men[b];
		for(int c = 0; c < quant; c++) cin >> women[c];
		sort(men.begin(),men.end());
		sort(women.begin(),women.end());
		
		for(int d = 0; d < quant; d++) bond[d] = men[d] * women[d];
		cout << accumulate(bond.begin(), bond.end(),0) << endl;
	}
	return 0;
}
