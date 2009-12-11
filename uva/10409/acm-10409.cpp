/** 
 * Title: Die Game
 * URL: http://online-judge.uva.es/p/v104/10409.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Problema de simulación en el que se debe tratar de predecir como
   quedarán las caras del dado después de que este se rote varias veces en una 
   de las siguientes cuatro direcciones: norte, sur, este, oeste.
	
**/


#include <iostream>
#include <map>

using namespace std;

map<char, unsigned> dice;

void north() {
	unsigned T = dice['T'];
	
	dice['T'] = dice['S'];
	dice['S'] = dice['B'];
	dice['B'] = dice['N'];
	dice['N'] = T;
}

void south() {
	unsigned B = dice['B'];

	dice['B'] = dice['S'];
	dice['S'] = dice['T'];
	dice['T'] = dice['N'];
	dice['N'] = B;
}

void east() {
	unsigned T = dice['T'];

	dice['T'] = dice['W'];
	dice['W'] = dice['B'];
	dice['B'] = dice['E'];
	dice['E'] = T;
}

void west() {
	unsigned  B = dice['B'];

	dice['B'] = dice['W'];
	dice['W'] = dice['T'];
	dice['T'] = dice['E'];
	dice['E'] = B;
}

void init(){
	dice['N'] = 2;
	dice['S'] = 5;
	dice['E'] = 4;
	dice['W'] = 3;
	dice['T'] = 1;
	dice['B'] = 6;

}

int main(){
	unsigned c;
	while (cin >> c){
		if (0 == c) return 0;
		
		init();
		string comm;
		for (unsigned i = 0; i < c; i++){
			cin >> comm;
			
			if ('n' == comm[0]) north();
			else if ('s' == comm[0]) south();
			else if ('e' == comm[0]) east();
			else west();			
		}
		cout << dice['T'] << endl;	
	}
	
	return 0;
}


