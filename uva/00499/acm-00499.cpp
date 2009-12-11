/** 
 * Title: What's The Frequency, Kenneth?
 * URL: http://online-judge.uva.es/p/v4/499.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Tener en cuenta que se ordena la salida primero por mayúsculas y luego por 
   minúscalas. El segundo criterio de ordenamiento es alfabético
	
**/

#include <iostream>

using namespace std;

int main(){
	string line;	
	
	while (getline(cin, line)){
		unsigned up[26], low[26];
		for (unsigned i = 0; i < 26; i++) up[i] = low[i] = 0;

		for (unsigned i = 0; i < line.size(); i++){
			char c = line[i];
			if (isalpha(c)){
				if (isupper(c))	up[c - 'A']++;
				else low[c - 'a' ]++;			
			}	
		}
		unsigned max = 0;
		for(unsigned i = 0; i < 26; i++){
			if (low[i] > max) max = low[i];
			if (up[i] > max) max = up[i];
		}
		
		for(unsigned i = 0; i < 26; i++)	if (max == up[i]) cout << (char)('A' + i);
		for(unsigned i = 0; i < 26; i++)	if (max == low[i]) cout << (char)('a' + i);
		cout << " " << max << endl;
	}

	return 0;
}

