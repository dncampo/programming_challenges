/**
 * Title: The 3n + 1 problem 
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/1/100.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se va calculando la subsecuencia máxima a medida que se necesita y se la almacena en un arreglo
	 para acceder más rápido en caso de que se pida una nueva subsecuencia que se encuentre dentro
	 de los límites de lo calculado hasta el momento.
**/

#include <iostream>
#include <vector>
using namespace std;

unsigned short res[1000001];

int size;

void solve(int tope){
	unsigned subsec;
	unsigned short count = 0;
	
	for(register unsigned i = size; i <= tope; i++){ 
		subsec = i;
		count = 0;
		
		while(subsec >= i){
			count++;
			
			if(subsec & 1) // impar
				subsec = subsec + (subsec << 1) + 1;			
			else // par
				subsec = subsec >> 1;

		}		
		res[i] = count + res[subsec];
	}
		size = tope+1;
}	
int main() {
	res[1]=1;
	size = 2;
	
	unsigned int n1;
	unsigned int n2;	
	
	while(~scanf("%d%d", &n1, &n2)) {
		printf("%d %d ", n1, n2);
		
		if (n1 > n2){
			unsigned temp = n1;
			n1 = n2;
			n2 = temp;
		}
		
		if(n2 >= size)
			solve(n2);
		
		unsigned int max = 0;
	
		for(register unsigned i=n1; i<=n2; i++)
			if (res[i] > max) max = res[i];
		
		printf("%d\n", max);
	}
	
	return 0;
}

//end!!
