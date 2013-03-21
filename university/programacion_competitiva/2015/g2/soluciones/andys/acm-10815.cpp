/**
 * Title: Andy's First Dictionary
 * URL: http://online-judge.uva.es/p/v108/10815.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
    + Se va leyendo palabra por palabra (esto es una secuencia de caracteres visibles, es decir sin espacios)
    y luego se procesa cada una de estas "palabras" para dividirla si se encontrasen caracteres que no forman
    parte del alfabeto inglés.
    Luego, una vez que tenemos una secuencia de letras válidas, se las almacena en un set, que ya manaja 
    duplicados y además almacena los strings lexicográficamente.
**/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main () {
	string word, alphabet = "abcdefghijklmnopqrstuvwxyz";
	set<string> dictionary;
	
	while (cin >> word) {
		for (unsigned i = 0; i < word.size(); i++)
			word[i] = tolower(word[i]);

		unsigned long long end = string::npos;
		unsigned begin = 0;

      //voy sacando las palabras de un conjunto seguido de caracteres
		while ( (end = word.find_first_not_of (alphabet)) != string::npos) {
		      if (begin != end) { 
		         string new_word = word.substr (begin, end - begin);
               dictionary.insert (new_word);
            }
            
		      word = word.substr(end + 1);
		}

		if (0 == word.size ()) continue;
		dictionary.insert(word);
	}
	
	for (set<string>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
		cout << *it << endl;
	return 0;
}

