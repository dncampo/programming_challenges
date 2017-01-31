/** 
 * Title: Happy Sequence
 * URL: http://www.spoj.pl/problems/KZHAPPY/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza un vector para no recalcular valores. 
	+ Si la suma de los cuadrados de los dígitos de un número 'n' da un valor 'b', menor que 'n', 
	entonces ya se sabe si 'b' es o no un happy number, por lo que se consulta una tabla para 
	retornar al valor apropiado para 'n'. Si el valor 'b', es mayor que 'n' se sigue calculando 
	la suma de los cuadrados de los dígitos de 'b' (como explica el enunciado) hasta que lleguemos a 
	un valor menor que el 'n' actual.
**/


#include <iostream>
#include <vector>
#include <cstring>

#define SIZE 3318

using namespace std;

// is_happy almacena en la pos 'n' si el número 'n' es o no happy number
//  0 -> no es happy number, o no se computo hasta el momento
//  1 -> es happy number.
int is_happy[SIZE];

vector<unsigned> happy(501, 0); //para almacenar los primeros 500 happy numbers
unsigned power[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81}; //cuadrados de 0 a 9
unsigned cnt = 12; // por el enunciado sólo conozco los primeros 11 happy numbers

bool is_a_happy_num(unsigned const a){

	unsigned div = a, mod, sum = a;
	
	while( sum >= a )  {
		sum = 0;
		mod = div % 10, div = div / 10;
		
		while(1){		
			if(0 == div) {
				sum += power[mod];
				break;
			}
			else sum += power[mod];
		
			mod = div % 10, div = div / 10;
		}
		div = sum;

	}
	
	if(0 < is_happy[sum]) {
		is_happy[a] = 1;
		happy[cnt++] = a;
		return true;
	}

	is_happy[a] = 0;
	return false;
}

int main(){
	unsigned n_cases, num;

	// luego pongo > 0 los que son <= 49 y son happy numbers.
	happy[1] = 1,  is_happy[1]  = 1;
	happy[2] = 7,  is_happy[7]  = 1;
	happy[3] = 10, is_happy[10] = 1;
	happy[4] = 13, is_happy[13] = 1;
	happy[5] = 19, is_happy[19] = 1;
	happy[6] = 23, is_happy[23] = 1;
	happy[7] = 28, is_happy[28] = 1;
	happy[8] = 31, is_happy[31] = 1;
	happy[9] = 32, is_happy[32] = 1;
	happy[10]= 44, is_happy[44] = 1;
	happy[11]= 49, is_happy[49] = 1;
	
	for(unsigned i = 50; i < SIZE; i++)	is_a_happy_num(i); // calculo los happy numbers...
	
	cin >> n_cases;	
	for(unsigned j = 0; j < n_cases; j++){
		cin >> num;
		cout << happy[num] << endl;
	}
	return 0;
}

