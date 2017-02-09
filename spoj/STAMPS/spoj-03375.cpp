/**
 * Title: Stamps
 * URL: https://www.spoj.pl/problems/STAMPS/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se ordena el vector de 'préstamos' y se calcula cuántos son necesarios para igualar o superar la
	cantidad 'borrow'.

**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned cases, borrow, friends;
	
	cin >> cases;
	for(unsigned i = 0 ; i < cases; i ++){
		cin >> borrow >> friends;
		vector <unsigned> friend_stamps(friends);
		for (unsigned j = 0; j < friends; j++){
			cin >> friend_stamps[j];
		}
		sort(friend_stamps.begin(), friend_stamps.end());
		
		cout << "Scenario #" << i+1 << ":" << endl;
		
		unsigned sum = 0, k=1;		
		for(int l = friends - 1; l >= 0; k++, l--){
			sum += friend_stamps[l];

			if(sum >= borrow){
				cout << k << endl;
				break;
			}
		}
		if(sum < borrow)
			cout << "impossible" << endl;
		
		cout << endl;
	}
	return 0;
}
