#include <cstring>
#include <iostream>
using namespace std;

/**
 * Title: Divisor Summation
 * URL: http://www.spoj.pl/problems/DIVSUM/
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	- El algoritmo se basa en una modificación de la criba para calcular
	- numeros primos:
		* Se inicializa un vector de SIZE elementos a cero.
		* para cada elemento i del vector se suma en todas las posiciones
		* multiplos, el valor i.
		* Luego se lee y se imprime los resultados.
**/
#define SIZE 500001

int main(){
	int vector[SIZE];

	memset(vector, 0, sizeof(vector));

	for(int i = 2; i <= SIZE/2; i++){
		for(int j = 2*i; j < SIZE; j += i){
		 	vector[j] += i; 
		}
		++vector[i];
	}
	
	int cases, value;
	
	cin >> cases;
	
	for(int index = 0; index < cases; index++){
		scanf("%d", &value);
		printf("%d\n", vector[value]);
	}
	
	return 0;
}

