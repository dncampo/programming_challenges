/**
 * Title: Anagrams (II)
 * URL: http://online-judge.uva.es/p/v6/630.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se llena el diccionario en un vector (NO deben estar ordenadas las palabras)
	+ Para ver si una palabra es anagrama de otra se lo hace en O(N) (nada de permutaciones :).
	Si las palabras a comprobar son de distinto tamaño, no pueden ser anagramas. Si son de igual longitud se las 
	inserta cada una en un multiset (es ordenado) y despues se comprueba si ambos multisets son iguales.
	+ Luego por cada palabra del test se busca un anagrama en el diccionario, si existe.

**/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//true si a y b son anagramas, false en otro caso
bool is_anagram (const string &a, const string &b) {
	if (a.size () != b.size ()) return false;
	multiset <char> sa, sb;

	for (unsigned i = 0; i < a.size (); i++) {
		sa.insert ( a[i] );
		sb.insert ( b[i] );
	}
	return sa == sb;
}

int main () {
	unsigned n_cases, dic_size;
	cin >> n_cases;

	for (unsigned i = 0; i < n_cases; i++) {
		vector<string>dictionary;
		cin >> dic_size;
		string s;
		for (unsigned j = 0; j < dic_size; j++) { //fill up the dictionary
			cin >> s;
			dictionary.push_back (s);
		}
		while (cin >> s) { //read tests words
			if ("END" == s) break;
			
			vector<string> anagram;
			for (vector<string>::const_iterator it = dictionary.begin (); it != dictionary.end (); it++) {
				if (is_anagram (s, *it)) {
					anagram.push_back (*it);
				}
			}

			cout << "Anagrams for: " << s << endl;
			if (0 == anagram.size ()) {
				cout << "No anagrams for: " << s << endl;
			}
			else {
				unsigned c = 1;
				for (vector<string>::const_iterator it = anagram.begin (); it != anagram.end (); it++, c++){
					cout.width(3); cout << c << ") " << *it << endl;
				}
			}
		}
		if (i < n_cases - 1) cout << endl;
	}
	return 0;
}
