/** 
 * Title: Tic-Tac-Toe ( I )
 * URL: http://www.spoj.pl/problems/TOE1/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para solucionar este problema es importante darse cuenta de:
   	* Si hay más O's que X's, entonces NO es una conf. válida.
   	* Si cant. X's menos cant. O's es mayor que 1, entonces NO es conf. válida.
   	* Si tanto X como O se encuentran en una posición ganadora, entonces no es conf. válida.
   	* Si sólo gana O, entonces la cant. de O's y X's debe ser la misma.	
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
	int n_cases;
	cin >> n_cases;
	
	for(int i = 0; i < n_cases; i++){
		vector<char> mat(9);
		int x = 0, o = 0;
		
		for(int j = 0; j < 9; j++) {
			char c;			
			cin >> c;
			
			mat[j] = c;
			
			if ('X' == c) x++;
			else if ('O' == c) o++;
		}
		
		if (o > x) {
			cout << "no" << endl;
			continue;
		}
		
		if (x > (o + 1)) {
			cout << "no" << endl;
			continue;
		}
		
		if (win(mat,'O') && (x > o) ){
			cout << "no" << endl;
			continue;		
		}
		
		if (both_wins(mat)){
			cout << "no" << endl;
			continue;
		}
		
		cout << "yes" << endl;
	}

	return 0;
}
