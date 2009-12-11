/**
 * Title:  Ugly Numbers 
 * URL: http://online-judge.uva.es/p/v1/136.html 
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	Abajo se describen dos soluciones que resuelven el problema en
	el mismo tiempo:
	- primera solucion:
		* basica, importante, no esta limitada con la memoria.
		* pero es complicado encontrar los limites...
		* primero de debe ejecutar el algoritmo para encontrar el MAX.
		* se puede utilizar un contador de numeros que sean < a MAX, en este caso
		* debemos encontrar un MAX tal que el contador llegue a 1500.
		* luego se calcula los limites para i,j,k de la siguiente forma:
		* 12 = floor(log(MAX)/log(5))
		* 18 = floor(log(MAX)/log(3))
		* 29 = floor(log(MAX)/log(2))
		* luego el algoritmo es intuitivo, se obtiene el maximo entre los
		* 1500 numeros que son menor a MAX.
	- segunda solucion: 
		* solucion con programacion dinamica...
		* inicializa ugly[1] a uno y luego a partir de un indice 2
		* se va obteniendo el siguiente ugly number como el minimo
		* entre (ugly2*2, ugly3*3, ugly5*5).
		* Donde ugly2, 3 y 5 son los indices a los ugly numbers ya calculados
		* que previamente se multiplicaron por 2,3 o 5 respectivamente y
		* luego se incrementa el indice asociado. Notar que 2*5 es igual a 5*2
		* es decir 10, en este caso se incremente el indice de 5 y el indice de 2.
		* Es una de las soluciones mas adecuadas para el problema, pero
		* tiene un problema en el uso de memoria adicional para calcular
		* los numeros. Esto se puede optimizar utilizando tres temporales
		* (y eliminar el vector ugly) para reducir el uso de memoria
		* y asi poder calcular ugly numbers indefinidamente.
		* 
**/

/*

#include <stdio.h>
#include <math.h>
#define MAX 860000000

int main(){
	unsigned max = 0, tmp, tmp2;
	
	for(unsigned i = 0; i <= 12; i++){
		for(unsigned j = 0; j <= 18; j++){
			tmp = pow(5, i) * pow(3, j);
			
			for(unsigned k = 0; k <= 29; k++){
				if( tmp > MAX) {
					k = 30;
				} else {
					if(tmp > max)
						max = tmp;

					tmp <<= 1;
				}
			}
		}
	}
	
	printf("The 1500'th ugly number is %u.\n", max);
	return 0;
}*/


#include <iostream>
using namespace std;
#define MAX 1501

int main(){
	unsigned ugly[MAX];
	unsigned p2, p3, p5; // indices a los ultimos calculados..
	unsigned  tmp2, tmp3, tmp5; //temporales...

	ugly[1] = 1;
	p2 = p3 = p5 = 1;
	
	for(int n = 2; n < MAX; n++){
		tmp2 = ugly[p2] * 2;
		tmp3 = ugly[p3] * 3;
		tmp5 = ugly[p5] * 5; 

		if(tmp2 < tmp3){
			if(tmp2 < tmp5)
				ugly[n] = tmp2;
			else
				ugly[n] = tmp5;
		} else if(tmp3 < tmp5){
			ugly[n] = tmp3;
		} else {
			ugly[n] = tmp5;
		}
		
		if(ugly[n] == tmp2) ++p2;
		if(ugly[n] == tmp3) ++p3;
		if(ugly[n] == tmp5) ++p5;	
	}
	cout << "The 1500'th ugly number is "<< ugly[MAX-1] << "." << endl;
	return 0;
}
