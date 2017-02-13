/** 
 * Title: K-In-A-Row
 * URL: http://www.spoj.pl/problems/KROW/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution: 
   + De las 8 posibles direcciones de verificación (arriba, abajo, izquierda, derecha,
     arriba+izquierda, ..., etc) sólo se verifican 4 (abajo, derecha, abajo+izq, abajo+der) para 
     no repetir los chequeos de forma innecasaria. Es decir es lo mismo chequear una serie de x's
     sea de atrás hacia delante como de forma inversa.
	
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned hansel_x, gretel_o;

bool to_right(string &line, int b, int k, char c){
	for(int i = 0; i < k; i++){
		if(line[b + i] != c)
			return false;	
	}
	return true;
}

bool to_down(vector<string> &mat, int a, int b, int k, char c){
	for(int i = 0; i < k; i++){
		if(mat[a + i][b] != c)
			return false;	
	}
	return true;
}

bool to_down_right(vector<string> &mat, int a, int b, int k, char c){
	for(int i = 0; i < k; i++){
		if(mat[a + i][b + i] != c)
			return false;
	}
	return true;
}

bool to_down_left(vector<string> &mat, int a, int b, int k, char c){
	for(int i = 0; i < k; i++){
		if(mat[a + i][b - i] != c)
			return false;
	}
	return true;
}

void compute_win(char c){
	if(c == 'x')
		hansel_x++;
	else
		gretel_o++;
}

int main(){
	int n_cases;
	cin >> n_cases;

	for (int i = 0; i < n_cases; i++){
		int m,n,k;


		cin >> m >> n >> k;		
		
		vector<string> matrix(n);
		
		for(int j = 0; j < n; j++){
			cin >> matrix[j];
		}

		
		bool win = false;
		char c;
		for(int a = 0; (a < n) && !win; a++){
			for(int b = 0; (b < m) && !win; b++){
				c = matrix[a][b];
				if('.' != c){
					
					if(1 == k){
						compute_win(c);
						win = true;
						break;
					}
					
					if(b + k <= m) { //der
						win = to_right(matrix[a], b + 1, k - 1, c);
						if(win) {
							compute_win(c);
							break;
						}
					}
					
					if(a + k <= n){ //aba
						win = to_down(matrix, a + 1, b  , k - 1, c);
						if(win) {
							compute_win(c);
							break;
						}
					}
					
					if( (a + k <= n) && (b + k <= m)){ //aba + der
						win = to_down_right(matrix, a + 1, b + 1 , k - 1, c);
						if(win) {
							compute_win(c);
							break;
						}
					}
					
					if( (a + k <= n) && ((b + 1) - k >= 0)){ //aba + izq
						win = to_down_left(matrix, a + 1, b - 1 , k - 1, c);
						if(win) {
							compute_win(c);
							break;
						}
					}
				
				}
			}
		
		}
		
	}
	cout << hansel_x << ":" << gretel_o << endl;
	return 0;
}
