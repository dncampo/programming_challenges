/**
 * Title: The 3n + 1 problem 
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/1/100.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Calculamos la subsecuencia de cada número y lo almacenamos en un arreglo (res[]),
		despues leemos la entrada estandar y buscamos la maxima subsecuencia 
		en el intervalo [n1, n2].
**/


#include <iostream>
using namespace std;

unsigned short res[1000001];

int main(int argc, char** argv) {
	// resuelve todas las subsecuencias.
	res[1]=1;
	
	for(register unsigned i=2; i< 1000001; i++){ 
		unsigned subsec = i;
		unsigned short count = 0;
		
		while(subsec >= i){
			count++;
			
			if(0 == subsec % 2) // par
				subsec = subsec >> 1;
			else // impar
				subsec = 3 * subsec + 1;
		}		
		res[i] = count + res[subsec];
	}
	
	unsigned int n1;
	unsigned int n2;	
	
	while(cin >> n1 >> n2) {
		cout << n1 << " " << n2 << " ";
		
		if (n1 > n2){
			unsigned temp = n1;
			n1 = n2;
			n2 = temp;
		}		
		unsigned int max = 0;
	
		for(register unsigned i=n1; i<=n2; i++)
			if (res[i] > max) max = res[i];
		
		cout << max << endl;
	}
	
	return 0;
}

//end!!
