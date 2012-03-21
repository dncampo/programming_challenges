/**
 * Title: So Doku Checker
 * URL: http://online-judge.uva.es/p/v109/10957.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Descripcion de la solucion: 
 *	 + Primero se checkea si es un tablero válido, luego se utiliza la tecnica de backtracking para 
      resolver el problema.
*/
#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
int solved;

void getCandidates(vector<int> &candidates, int i, int j){
	short opt[10] ={0};

	// eliminar los numeros de la fila j y la columna i.
	for(unsigned index = 0; index < 9; index++){
		opt[sudoku[i][index]] = 1;
		opt[sudoku[index][j]] = 1;
	}

	while(i % 3 != 0) i--;
	while(j % 3 != 0) j--;

	// eliminar los numeros del cuadrado.
	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
				opt[ sudoku[i+x][j+y] ] = 1;
		}
	}
	// preparar el retorno.
	for(unsigned index = 1; index <= 9; index++){
		if(~opt[index] & 1 )
			candidates.push_back(index);
	}
} 

/* True si es una solucion al problema del su doku.
*/ bool solution(int i, int j){
	return ( i == 9 && j == 0);
}

/* Algoritmo que prueba todas las combinaciones hasta que encuentra una 
   que resuelve el su doku.
*/ void backtracking(int i, int j){
	 
   // chequear si es una solucion
	if(solution(i, j)){
		++solved;
	} else{
		if(solved > 1 ) return;
		int x = i, y = j;		

		vector<int > candidates;
		
		// obtener los candidatos
		if(sudoku[x][y] == 0) {
			getCandidates(candidates, x, y);
			if(candidates.size() == 0) return;
		}
				
		// actualizar los indices.
		if(++j == 9){
		   j = 0;
		   i++;
		}
		
		// probar con todas las combinaciones.
		for(unsigned index = 0; index < candidates.size(); index++){
			sudoku[x][y] = candidates[index];
			backtracking(i, j);
			sudoku[x][y] = 0;  // dejar todo consistente por las dudas...
		}

		// si el casillero ya estaba asignado por la entrada.
		if(candidates.size() == 0)
			backtracking(i, j);
	}
}


bool legal(){
	for(int k = 0; k < 9; k++){
		for(int i = 0; i < 9; i++){
			if(sudoku[k][i] != 0){
				for(int ii = i+1; ii < 9; ii++){
					if(sudoku[k][i] == sudoku[k][ii]){
						return false;
				   }
				}
			}
		}
	}
   for(int k = 0; k < 9; k++){
 		for(int i = 0; i < 9; i++){
      	if(sudoku[i][k] != 0){
         	for(int ii = i+1; ii < 9; ii++){
            	if(sudoku[i][k] == sudoku[ii][k]){
               	return false;
               }
            }
         }
      }
   }
	
	for(int i = 0; i < 7; i += 3){
		for(int j = 0; j < 7; j += 3){
			for(int di = 0; di < 3; di++){
				for(int dj =0; dj < 3; dj++){
					if(sudoku[i+di][j+dj] != 0){
						for(int x = di, y = dj+1; x < 3; y++){							
							if(y == 3){
								y = 0;
								x++;
							}
							if(x < 3 && sudoku[i+di][j+dj] ==sudoku[i+x][j+y]){
								return false;
							}
							
						}
					}
				}
			}
		}
	}
	return true;
}

string solve(){
	if(legal()){
	   solved = 0;
	   backtracking(0, 0);
	   if(solved == 0)
	      return "Impossible";
	   return solved  == 1 ? "Unique" : "Ambiguous";
	} else return "Illegal";

	return "";
}
bool read_sudoku(){
	int count = 0, n, i = 0, j = -1;
	
	while(i != 9 && cin >> sudoku[i][++j]){
	  if(j == 8){
			j = -1;
			i++;
		}
	}
	return i == 9;
}

int main(){
	int cases = 1;
	while(read_sudoku()){
		cout << "Case " << cases++ << ": " << solve() << "." << endl;
	}	
}
