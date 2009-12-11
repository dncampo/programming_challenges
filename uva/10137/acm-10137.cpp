/**
 * Title: The Trip
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/101/10137.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Se calcula la diferencia de cada gasto con respecto al promedio y se van acumulando las diferencias
	positivas y negativas. Luego se imprime la mayor en valor absoluto.
**/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	cout.setf(ios::fixed);   
	cout.precision(2);

	while(1){
		unsigned c;
		double spending,sum=0, avg, result_neg=0.00, result_pos=0.00;
 
		cin >> c;
		if(0 == c) 
			return 0;
		double all[c];
		for (unsigned i = 0; i < c; i++){
			cin >> spending;
			all[i]=spending;
			sum +=spending;
		}

		avg = sum / c;

		for(unsigned j=0; j<c; j++){
			if(all[j] < avg)		 
				result_neg += (double)(int)((all[j] - avg) * 100.00) / 100.00;
			else
				result_pos += (double)(int)((all[j] - avg) * 100.00) / 100.00;
		}
		cout << "$";
		(-result_neg > result_pos ) ? cout << -result_neg : cout << result_pos;
		cout << endl;
	}
	return 0;
}

//EOF
