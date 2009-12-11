/**
 * Title: Decode the tape
 * URL: http://online-judge.uva.es/p/v108/10878.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Notar que cada línea corresponde a un caracter, y se encuentra en formato binario. Cada 'o' representa
	un 1 y cada ' ' representa un 0.
	+ Luego se accede una tabla de potencias para cada 'o' encontrada para cada caracter, indexada a partir
	de la posición de la 'o' dentro de la línea.

**/

#include <iostream>
#include <string>

char pows[] = {0, 128, 64, 32, 16, 8, 0, 4, 2, 1};

using namespace std;

int main () {
	string line;
	getline (cin,line);
	
	while (getline (cin, line)) {
		if (line[0] == '_') return 0;

		char c = 0;
		for (unsigned i = 2; i < 6; i++) {
			if ('o' == line[i])
				c += pows[i];
		}
		
		for (unsigned i = 7; i < 10; i++){
			if ('o' == line[i])
				c += pows[i];
		}
	
		cout << c;
	}
  return 0;
}
