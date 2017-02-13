/**
 * Title: Mispelling
 * URL: https://www.spoj.pl/problems/GNY07A/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Remover la letra indicada :)

**/

#include <iostream>

using namespace std;

int main(){
	unsigned cases;
	cin >> cases;
	for (unsigned i = 0; i < cases; i++){
		unsigned index;
		string word;
		cin >> index >> word;
		
		cout << i + 1 << " " << word.substr(0,index - 1) << word.substr(index) << endl;
	}
	return 0;
}
