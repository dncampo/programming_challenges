/**
 * Title: Jolly Jumpers
 * URL: http://online-judge.uva.es/p/v100/10038.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se guardan los n números de la entrada en un vector
	+ Se guardan las n-1 diferencias secesivas en otro vector
	+ Se ordena el vector de diferencias y se verifica que la secuencia contenga todos los valores
	  entre 1 y n-1.

**/


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool is_jolly(vector<int>&);

int main(){
	unsigned nums;
	
	while(cin >> nums){
		vector <int> data;

		for (unsigned i = 0; i < nums; i++){
			int dat;
			cin >> dat;
			data.push_back(dat);
		}
		
		if(is_jolly(data)) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;	
	}
	return 0;
}

bool is_jolly(vector<int>& data){
	vector<unsigned> diff(data.size()-1,0);
	
	for(unsigned j = 0; j < diff.size(); j++){
		diff[j] = abs(data[j] - data[j + 1]);
	}
	
	sort(diff.begin(), diff.end());
	for(unsigned k = 0; k < diff.size(); k++){
		if (k+1 != diff[k]) return false;
	}
	return true;
}
