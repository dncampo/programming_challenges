/**
 * Title: Machined Surfaces
 * URL: http://online-judge.uva.es/p/v4/414.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para cada fila se cuentan los espacios y se almacena este resultado en un vector. Al mismo tiempo
	se va contando la mínima cantidad de estos espacios (es decir la fila con menos blancos).
	Al finalizar la entrada de un caso, en min queda almacenada la cantidad de espacios que se pueden remover
	de cada fila, con lo que se recorre el vector que cuenta los espacios en blanco de cada fila y se le 
	resta el min. La suma de estas restas corresponde al resultado.

**/



#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

unsigned count_blanks (string &line) {
	unsigned i = 0, count = 0;
	while ((' ' != line[i]) && (i < 25) ) i++;
	
	while (' ' == line[i]) {
		i++;
		count++;
	}
	return count;
}


int main () {

	string line, rows;
	while (getline (cin,rows) ) {
		unsigned r = atoi(rows.c_str());
		if (0 == r) return 0;
		
		vector <unsigned> count (r);
		unsigned min = numeric_limits<unsigned>::max(), res = 0;
		for (unsigned i = 0; i < r; i++) {
			getline (cin, line);
			count [i] = count_blanks (line);
			if (count[i] < min) min = count[i];
		}
		
		for (unsigned i = 0; i < count.size(); i++)
			res += count[i] - min;
			
		cout << res << endl;
	}

	return 0;
}
