/**
 * Title: He is offside!
 * URL: http://www.spoj.pl/problems/OFFSIDE/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se guardan las posiciones de los defensores y se las ordena de menor a mayor. Si la posición del
	atacante más adelantado es menor que la del 2do defensor más retrasado, entonces se encuentra en 
	offside; de otra forma no.
**/

 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned short a,d, tmp;

int main(){
	
	while(1){
		cin >> a >> d;
		
		if (a == 0) break;

		vector<unsigned short> defenders;
		unsigned short attackers = 10000;
		
		defenders.resize(d);
		
		for(int i = 0; i < a; i++) { //se cargan las posiciones de los atacantes
			cin >> tmp;
			if (tmp < attackers)
				attackers = tmp;
		}
		for(int j = 0; j < d; j++) { //se cargan las posiciones de los defensores
			cin >> tmp;
			defenders[j] = tmp;
		}
		
		sort(defenders.begin(), defenders.end());
		
		if(attackers < defenders[1])
			cout << "Y" << endl;
		else
			cout << "N" << endl;	
		}
	
	return 0;
}
