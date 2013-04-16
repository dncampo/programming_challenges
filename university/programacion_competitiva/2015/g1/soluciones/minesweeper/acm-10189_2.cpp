/**
 * Title: 
 * URL: http://acm.uva.es/p/v101/10189.html
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
 	Se representa el juego del buscaminas con una matriz de x,y dimensiones.
 	Luego si la entrada es * se suma uno a los lugares adyacentes.
 	Luego se imprime la matriz.
**/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vector<int> > data;
	int x, y, field = 0;
	char c;
	
	cin >> x >> y;
	
	while(  x > 0 && y > 0){
		// inicializar datos
		data.resize(x);
		
		for(int i = 0; i < x; i++)
			data[i].assign(y, 0);
		field++;
		
		// leer y resolver al mismo tiempo
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){	
				cin >> c;
				
				if('*' == c){
					for(int dx = -1; dx <= 1; dx++){
						for(int dy = -1; dy <= 1; dy++){
							if(dx == 0 && dy == 0){
								data[i][j] = -1;
							} else{
								int xx =i+dx, yy = j+dy;
								
								if(xx >= 0 && yy >=0 && xx < x && yy < y)
									if(data[xx][yy] != -1)
										++data[xx][yy];
							}
						}
					} 
				}
			}
		}
		// imprimir la solucion
		cout << "Field #" << field << ":" << endl;
		
		for(unsigned i = 0; i < x; i++){
			for(unsigned j = 0; j < y; j++){
				if(data[i][j] == -1) cout << "*";
				else cout << data[i][j];
			}
			cout << endl;
		}
		cin.ignore();
		cin  >> x >> y;
		
		if(x > 0 && y > 0)
			cout << endl;
	}
	return 0;
}
