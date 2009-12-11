/** 
 * Title: A Graph Problem
 * URL: http://uva.onlinejudge.org/external/110/11069.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Es una recurrencia muy parecida a la de Fibonacci. El valor de n = (n - 3) + (n - 2).
	
**/



#include <iostream>

using namespace std;

int main(){
	unsigned cached[76] = {1, 2, 2, 3 , 4}, num;
	
	for(unsigned i = 5; i < 76; i++)
		cached[i] = cached[i - 3] + cached[i - 2];

	while(cin >> num){
		cout << cached[num - 1] << endl;
	}


	return 0;
}

