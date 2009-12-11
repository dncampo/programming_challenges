/**
 * Title: Ecological Premium
 * URL: http://online-judge.uva.es/p/v103/10300.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ La clave de este sencillo problema es darse cuenta de que para calcular el premio que recibe
	cada persona sólo se depende del tamaño de la granja y del 'friendliness' del agricultor, 
	siendo no necesaria la cantidad de animales ya que en la fórmula que da el problema primero 
	se divide y luego se multiplica por dicha cantidad.

**/


#include <iostream>

using namespace std;

int main (){
	unsigned cases, farmers, farmyard, animals, friendliness;
	unsigned total;
	
	cin >> cases;
	
	for (unsigned i = 0; i < cases; i++){
		cin >> farmers;
		total = 0;
		for (unsigned j = 0; j < farmers; j++){
			cin >> farmyard >> animals >> friendliness;
			total += farmyard * friendliness;
		}
		cout << total << endl;
	}

	return 0;
}
