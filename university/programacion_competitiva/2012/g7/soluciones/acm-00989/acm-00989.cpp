/**
 * Title: su doku 
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/9/989.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Descripcion de la solucion: 
 *	 + Utilizo la tecnica de backtracking para resolver el problema.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* True si ya se consiguio una solucion
*/ bool solved = false;

/* Matriz que almacena la entrada. 
   Tambien sirve para ir probando las posibles
   soluciones con el algoritmo de backtracking
*/ vector< vector<int > > sudoku;

/* Imprime la solucion
*/ void print(){
	for(unsigned i = 0; i < sudoku.size(); i++){
		for(unsigned j = 0; j < sudoku.size(); j++){
			cout << sudoku[i][j];
			if(j+1 < sudoku.size()) cout << " ";
			
		}
		cout << endl;
	}
}

/* Retorna los posibles numeros que se pueden agregar a un casillero
   de acuerdo a las reglas del Su Doku
*/ void getCandidates(vector<int> &candidates, int i, int j){
	short opt[10] ={0};

	// eliminar los numeros de la fila j y la columna i.
	for(unsigned index = 0; index < sudoku.size(); index++){
		opt[sudoku[i][index]] = 1;
		opt[sudoku[index][j]] = 1;
	}

	int size = sqrt(sudoku.size());
	int di = size*(i/size), dj = size*(j/size);

	// eliminar los numeros del cuadrado.
	for(int x = 0; x < size; x++){
		for(int y = 0; y < size; y++){
				opt[ sudoku[di+x][dj+y] ] = 1;
		}
	}
	// preparar el retorno.
	for(unsigned index = 1; index <= sudoku.size(); index++){
		if(~opt[index] & 1 )
			candidates.push_back(index);
	}
} 

/* True si es una solucion al problema del su doku.
*/ bool solution(int size, int i, int j){
	return ( i == size && j == 0);
}

/* Algoritmo que prueba todas las combinaciones hasta que encuentra una 
   que resuelve el su doku.
*/ void backtracking(int i, int j){
	 
   // chequear si es una solucion
	if(solution(sudoku.size(), i,j)){
		print();
		solved = true; 
	} else{
		if(solved ) return;  // si no se ha resuelto todavía el problema
		int x = i, y = j;		

		vector<int > candidates;
		
		// obtener los candidatos
		if(sudoku[x][y] == 0) {
			getCandidates(candidates, x, y);
			if(candidates.size() == 0) return;
		}
				
		// actualizar los incides.
		j = (j+1) % sudoku.size();
		if(j == 0) ++i;
		
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

/* funcion auxiliar de valid().
*/ int check(unsigned i, unsigned j, int value){
	if (value == 0) return 0; 

	for(unsigned x = 0; x <sudoku.size(); x++){
		if(x == i ) continue;
		if(value == sudoku[x][j]) return 1;
	} 
	for(unsigned y = 0; y <sudoku.size(); y++){
		if(y == j ) continue;
		if(value == sudoku[i][y]) return 1;
	} 

	unsigned size = sqrt(sudoku.size());
	
	unsigned x = size * (i/size), y = size*(j/size);

	for(unsigned dx = 0; dx < size; dx ++){
		for(unsigned dy = 0; dy < size; dy ++){
			if(x + dx == i && y + dy == j) continue;
			if(sudoku[x + dx][y + dy]== value) return 1;
		}
	}
	return 0;
}

/* chequea si para los datos ingresados se puede
   obtener una solucion al su doku.
*/ bool valid (){
	for(unsigned i = 0; i < sudoku.size(); i++){
		for(unsigned j = 0; j < sudoku.size(); j++){
			if(1 & check(i,j, sudoku[i][j]))	return false;
		}
	}

	return true;
}

int main(){	
	bool first = true;
	unsigned size;

	// para todos los casos de prueba
	while (cin >> size){
		// imprimir espacios entre soluciones
		if(!first ) cout << endl;
		else first = false;
	
		// actualizar variables iniciales
		solved = false;
		sudoku.clear(); 
		sudoku.resize(size*size);

		//obtener la matriz de entrada
		for(unsigned i = 0; i < size*size; i++){
			sudoku[i].resize(size*size);
			for(unsigned j = 0; j < size*size; j++){
				cin >> sudoku[i][j];
			}
		}
		// resolver el probema...
		if(valid())
			backtracking(0, 0);	

		if(!solved)
			cout << "NO SOLUTION" << endl;

	}

	return 0;
}


