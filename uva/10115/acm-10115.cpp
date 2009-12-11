/**
 * Title: Automatic Editing
 * URL: http://online-judge.uva.es/p/v101/10115.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se cargan las reglas (cada patrón y su reemplazo) en dos vectores distintos.
	+ Se usa una de las funciones para buscar en strings: find (), y se reemplaza cada patrón
	encontrado por su correspondiente 'reemplazo'.

**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve (vector<string> &patterns, vector<string>& replaces, string& line) {

	for (unsigned i = 0; i < patterns.size (); i++) {
	
		size_t pos = 0;
		while (string::npos != (pos = line.find (patterns[i], pos))) { //buscar una ocurrencia de la regla i

			string first, last;
			first = line.substr (0, pos);
			last = line.substr (pos + patterns[i].size ());
			line = first + replaces[i] + last; //aplicar la regla
		}
	}
	cout << line << endl;
}

int main () {
	unsigned n_rules;

	while (cin >> n_rules) {
		cin.ignore ();
		if (0 == n_rules) return 0;

		vector <string> patterns (n_rules), replaces (n_rules);
		for (unsigned i = 0; i < n_rules; i++) {
			getline (cin, patterns[i]);
			getline (cin, replaces[i]);
		}

		string line;
		getline (cin, line); //texto a modificar
		solve (patterns, replaces, line);
	}
	return 0;
}
