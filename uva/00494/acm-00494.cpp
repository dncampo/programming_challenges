/** 
 * Title: Kindergarten Counting Game
 * URL: http://online-judge.uva.es/p/v4/494.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se recorre completamente una línea de entrada y cada vez que encontramos una nueva letra
   se actualiza un contador de palabras (las letras consecutivas de la letra inicial de una 
   palabra se pasan por alto)
	
**/


#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string line;

	while (getline (cin, line)){
		if(line.size() == 0) continue;
		unsigned count = 0;
		unsigned i = 0;
		
		while( i < line.size()){
			if (isalpha(line[i++])){
				count++;				
				while(isalpha(line[i])) i++; //ignorar las letras contiguas de una palabra		
			}
		}
		cout << count << endl;
	}
	
	return 0;
}

