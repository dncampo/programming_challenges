/** 
 * Title: Tic-Tac-Toe ( II )
 * URL: http://www.spoj.pl/problems/TOE2/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para solucionar este problema es importante darse cuenta de:
   	* Si hay más O's que X's, entonces NO es una conf. válida.
   	* Si cant. X's menos cant. O's es mayor que 1, entonces NO es conf. válida.
   	* Si tanto X como O se encuentran en una posición ganadora, entonces no es conf. válida.
   	* Si sólo gana O, entonces la cant. de O's y X's debe ser la misma.
   	* Si nadie gana, para que el juego esté finalizado, deben estar todas las posiciones ocupadas 
   	con alguna ficha.
**/


#include <iostream>
#include <vector>

using namespace std;

bool win(vector<char>& m, char c){

	bool ret =  ( (m[0] == c) && (m[1] == c) && (m[2] == c) ) ||
					( (m[3] == c) && (m[4] == c) && (m[5] == c) ) ||
					( (m[6] == c) && (m[7] == c) && (m[8] == c) ) ||
					( (m[0] == c) && (m[3] == c) && (m[6] == c) ) ||
					( (m[1] == c) && (m[4] == c) && (m[7] == c) ) ||
					( (m[2] == c) && (m[5] == c) && (m[8] == c) ) ||
					( (m[0] == c) && (m[4] == c) && (m[8] == c) ) ||
					( (m[2] == c) && (m[4] == c) && (m[6] == c) );
	return ret;
}


bool both_wins(vector<char>& mat){
	return win(mat,'X') && win(mat, 'O');
}


int main(){

	while(1){
	
		vector<char> mat(9);
		int x = 0, o = 0;

		char c;

		cin >> c;
		if('e' == c) return 0;
		mat[0] = c;
		if ('X' == c) x++;
		else if ('O' == c) o++;
		
		for(int j = 1; j < 9; j++) {

			cin >> c;
			
			mat[j] = c;
			
			if ('X' == c) x++;
			else if ('O' == c) o++;
		}
		
		if (o > x) {
			cout << "invalid" << endl;
			continue;
		}
		
		if (x > (o + 1)) {
			cout << "invalid" << endl;
			continue;
		}
		
		bool win_o, win_x;
		
		win_o = win(mat,'O');
		win_x = win(mat,'X');
		
		
		if (win_o && (x > o) ){
			cout << "invalid" << endl;
			continue;		
		}
		
		if (win_o && win_x){
			cout << "invalid" << endl;
			continue;
		}
		
		if ((!win_o) && (!win_x) && ((x+o) < 9)){
			cout << "invalid" << endl;
			continue;		
		}
		
		cout << "valid" << endl;
	}

	return 0;
}
