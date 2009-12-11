/**
 * Title: To and Fro
 * URL: https://www.spoj.pl/problems/TOANDFRO/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Una forma sencilla y, sobre todo, rápida de resolver este problema es crear la matriz apropiada e ir
	llenándola (verticalmente) con los caracteres a medida que vamos leyéndolos. Luego se la recorre en la
	forma indicada en el problema (en el ciclo "izquierda a derecha"-"derecha a izquierda").
**/


#include <iostream>

using namespace std;

int main(){
	short cols;
	string line;
	while(1){
		cin >> cols;
		if(0 == cols) return 0;
		cin >> line;
		short rows = line.size()/cols, cont=0;
		char data[rows][cols];
		bool flag=true;
		
		for(short a=0; a < rows; a++){
			if(flag)
				for(short b=0; b < cols; b++)
					data[a][b] = line.at(cont++);
			else
				for(short b=cols-1; b >= 0; b--)
					data[a][b]=line.at(cont++);
		flag = !flag;
		}
		for(short j=0; j < cols; j++)
			for(short i=0; i < rows; i++)
				cout << data[i][j];
		cout << endl;
	}
	return 0;
}

//EOF
