/**
 * Title: Ananagrams
 * URL: http://online-judge.uva.es/p/v1/156.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se llena el diccionario en un multimap (por si hay casos de entrada como 'b' y 'B') y se los almacena
	de la siguiente manera: la "clave" es la palabra leída pero en minúsculas, y el "valor" del multimap es
	la palabra tal cuál se leyo. Esto permite almacenar la siguiente entrada "b B b b B B" como los dos pares:
	(b, B), (b, b). De esta forma se puede chequear si una palabra es anagrama de otra con sólo mirar las palabras
	minúsculas, pero sin perder la palabra original (que puede ser tan extravagante como: pALabRa).
	+ Para ver si una palabra es anagrama (no ananagrama) de otra se lo hace en O(N) (nada de permutaciones :).
	Si las palabras a comprobar son de distinto tamaño, no pueden ser anagramas. Si son de igual longitud se las 
	inserta cada una en un multiset (es ordenado) y despues se comprueba si ambos multisets son iguales.
	+ Luego por cada palabra del diccionario se busca un anagrama en dicho diccionario.

**/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

using namespace std;

//pasar el argumento a minúsculas y devolverlo en un nuevo string
string all_lowercase (const string& s) {
	string ret;

	for (unsigned i = 0; i < s.size (); i++)
		ret.push_back ( tolower (s[i]) );

	return ret;
}

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

	multimap<string, string> dictionary;
	set<string> ananagram;
	string word;
	while (cin >> word) {
		if ("#" == word) break;

		dictionary.insert ( pair<string, string> (all_lowercase (word), word) );
	}

	for (map<string, string>::const_iterator it1 = dictionary.begin (); it1 != dictionary.end (); it1++) {
		bool found = false;

		for (map<string, string>::iterator it2 = dictionary.begin (); it2 != dictionary.end (); it2++) {
			if (it1 == it2) continue; //don't check against itself

			if (is_anagram (it1->first, it2->first)) {//para cada palabra del diccionario ver si hay un anagrama
				found = true;
				break;
			}
		}
		if (!found) ananagram.insert (it1->second); //si no hay anagrama, se prepara para imprimir
	}

	for (set<string>::const_iterator it = ananagram.begin (); it != ananagram.end (); it++) {
		cout << *it << endl;
	}

	return 0;
}
