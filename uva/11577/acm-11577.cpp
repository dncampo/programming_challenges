/**
 * Title: Problem A: Letter Frequency
 * URL: http://uva.onlinejudge.org/external/115/11577.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	 + Para cada letra del alfabeto (26 en total) se almacena en un vector la cantidad de veces que 
	 ocurre en la oración de entrada, indexado por el valor de la letra (a = 0, b = 1, ..., z = 25)
	 y convirtiendo las letras mayúsculas a minúscula. 
	 Luego se imprime la/s letra/s con más ocurrencias.
**/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
	
	string cases;
	
	getline(cin,cases);
	for(unsigned i = 0; i < atoi(cases.c_str()); i++){
		string line;
		vector<unsigned> values;
		values.resize(26,0);

		getline(cin, line);
		
		for(unsigned j = 0; j < line.size(); j++){
			char ch = line.at(j);
			
			if( (ch > 64 && ch < 91) || (ch < 123 && ch > 96)){

				if (ch > 90)
					ch -= 32;
					
				ch -= 65;
				values[(int)ch]++;
			}
		}
		
		unsigned max = *max_element(values.begin(), values.end());

		for(unsigned j = 0; j < 26; j++){
			if(values[j] == max) cout << (char)(j + 97);
		}
	cout << endl;
	}
	return 0;
}
