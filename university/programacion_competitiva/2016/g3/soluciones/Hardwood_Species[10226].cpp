#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	//Numero de casos de prueba y la poblacion total de árboles.
	int casos,poblacion_total = 0;
	cin >> casos;
	//Ignoramos la lectura doble de los casos y el primer salto de linea.
	cin.ignore();
	cin.ignore();
	//Creamos el map que guardara las especies de arboles y la cantidad.
	map<string,int> listado_arboles;
	string arbol;
	while(casos > 0){
		//Se lee cada arbol
		getline(cin,arbol);
		//Si se lee un salto de linea, el arbol es vacio, por lo tanto termina
		//el caso de prueba y se imprime el resultado.
		if(arbol.empty()){
			for(map<string,int> :: iterator iterador = listado_arboles.begin(); iterador != listado_arboles.end(); iterador++){
				cout << iterador -> first << " " << fixed << setprecision(4) << 100.00 * iterador -> second / poblacion_total << "\n";
			}
			//Restamos en uno los casos.
			casos--;
			//Si debemos esperar por mas casos, imprimimos un salto de linea, 
			//reseteamos contadores y estructuras.
			if(casos){
				cout << "\n";
				listado_arboles.clear();
				poblacion_total = 0;
			}
		}else{
			//Guardamos la especie de arbol, si ya existe, aumentamos en uno
			//su contador. Y tambien aumentamos la poblacion total.
			listado_arboles[arbol]++;
			poblacion_total++;
		}
	}
	return 0;
}

