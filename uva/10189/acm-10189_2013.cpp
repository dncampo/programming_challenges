/**
 * Title: Minesweeper
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/101/10189.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Dado un 'field' de N x M, creo una matriz booleana de (N + 2) x (M + 2) que lo representa. Las dos
	filas y dos columnas que sobran son para poder centrar el 'field' y no tener que hacer ninguna pregunta
	para ver si estoy en algún borde, al contar las minas de los 8 lugares adyacentes al actual. 
	Esto facilita mucho el trabajo de procesar la matriz ya que se eliminan muchas condiciones relacionadas 
	con los lugares extremos (como ser la pos (n,m)). En esta matriz, se coloca un false en la pos i,j si no 
	hay una 'mina' en dicha posición. Caso contrario se coloca true.
   + Luego se crea una matriz para contar en la posición i,j la cantidad de 'minas' que hay en sus 8 lados
	adyacentes. En este caso la matriz se crea del tamaño normal del 'field', ya que al recorrerla no hay que
	considerar ningún caso de borde o extremo (como sí en la matriz booleana).	
**/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef unsigned uns;

int main (void){	
	uns n,m, field_num=0;
	char tmp;
	
	while(1){
		cin >> n >> m;
		
		if((m == 0)&&(n == 0))	return 0;		
		bool field[n + 2][m + 2];		
		char count[n][m];
		memset(field,false, (n+2)*(m+2));
		
		
		for(uns c = 1; c <= n; c++){
			for(uns d = 1; d <= m; d++){
				cin >> tmp;				
				field[c][d] = tmp=='*' ? true : false;
				count[c-1][d-1] = '0';
			}
		}
		
		for(uns c=1; c <= n; c++){
			for(uns d=1; d <= m ; d++){
				if(field[c][d]) {
					count[c-1][d-1] = '*';
				}
				else{
					count[c-1][d-1] += field[c-1][d-1]; //up + left
					count[c-1][d-1] += field[c-1][d]; //up
					count[c-1][d-1] += field[c-1][d+1]; //up + right
					count[c-1][d-1] += field[c][d-1]; //left
					count[c-1][d-1] += field[c][d+1]; //right
					count[c-1][d-1] += field[c+1][d-1]; //down + left					
					count[c-1][d-1] += field[c+1][d]; //down
					count[c-1][d-1] += field[c+1][d+1]; //down + right
				}
			}
		}
		if(0!=field_num) cout << endl;		
		cout << "Field #" << ++field_num << ":" << endl;		
		for(uns c=1; c <= n; c++){
			for(uns d=1; d <= m; d++){
				cout << count[c-1][d-1];
			}
			cout << endl;
		}
	}
}
