/**
 * Title: What's Cryptanalysis?
 * URL: http://online-judge.uva.es/p/v100/10008.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Almaceno las latras (en mayúsculas) y sus ocurrencias en un map.
	+ Luego almaceno en un multimap todas las ocurrencias con sus letras (mapeo reverso al anterior)
	+ Recorro el multimap en orden inverso (así empiezo por la(s) letra(s) con más ocurrencias.
	+ Lo voy almacenando en un set, para luego imprimirlo (por si se más de una letra tienen la misma
	ocurrencia las imprimo lexicográficamente.

**/

#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <string>

using namespace std;

int main () {
	unsigned n_lines;
	cin >> n_lines; cin.ignore ();

	string line;
	map <char, unsigned> cnt;
	for (unsigned i = 0; i < n_lines; i++) {
		getline (cin, line);
		for (unsigned j = 0; j < line.size (); j++) {
			char c = line[j];
			if (isalpha (c)) {
				cnt[ toupper (c) ]++;
			}
		}
	}

	multimap <unsigned, char> res;
	for (map<char, unsigned>::const_iterator it = cnt.begin (); it != cnt.end (); it++) {
		res.insert ( pair <char,unsigned> ( it-> second, it->first ) );
	}

	if (! res.empty ()) {
		multimap<unsigned, char>::const_reverse_iterator it = res.rbegin ();

		set <char> r; //imprimir resultado
		while (it != res.rend ()) {
			unsigned val = it->first;
			while (val == it->first) {
				r.insert (it->second);
				it++;
			}
			for (set<char>::const_iterator it2 = r.begin (); it2 != r.end (); it2++ ) {
				cout << *it2 << " " << val << endl;
			}
			r.clear ();
		}
	}
	return 0;
}