/**
 * Title: List of Conquests
 * URL: http://online-judge.uva.es/p/v104/10420.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacenan los nombres de los países en un map. Cada vez que se lee el nombre de un 
	país en una línea se le incrementa un contador.

**/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
	unsigned n;
	cin >> n; cin.ignore ();

	string line;
	map <string, unsigned> conquests;
	for (unsigned i = 0; i < n; i++) {
		cin >> line;
		conquests[ line ]++;
		cin.ignore (100, '\n'); //who cares the name ;)
	}

	for (map<string, unsigned>::iterator it = conquests.begin (); it != conquests.end (); it++)
		cout << it->first << " " << it->second << endl;

	return 0;
}
