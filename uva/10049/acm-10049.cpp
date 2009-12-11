/**
 * Title: Self­describing Sequence 
 * URL: http://acm.uva.es/problemset/v100/10049.html
 * Resources of interest:
 * Solver group: Yeyo-David-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + La idea de la solucion es generar un vector con el intervalo[a,b] en 
	   el q f(n) = i donde i = 1,2...2000000000. Para nuestro problema solo 
		guardamos b, es decir el maximo indice para todos los f(n) igual a un valor.
		ejemplo: 
			a[1] = 1; a[2]=3; a[3]=5 ...
			si queremos saber la sucesión del valor cuatro (x=4) debemos buscar 
			un a[i]/ a[i-1] <x && x<=a[i] entonces, en nuestro ejemplo
			i==3, es decir, nuestro resultado es 3.
**/

#include <iostream>
using namespace std;

#define MAX_DATA 673367

unsigned int a[MAX_DATA];

void init();
unsigned int getIndex(unsigned int );
unsigned int find(unsigned int max, unsigned int value);

int main(){
	unsigned int n;
	init();
	cin >> n;

	while (n != 0){
		cout << getIndex(n) << endl;
		cin >> n;
	}
	return 0;
}

void init(){
	a[1] = 1;
	a[2] = 3;
	
	for(unsigned int i = 3; i < MAX_DATA; i++){
		a[i] = a[i-1] +find(i-1, i);
	}
}

unsigned int find(unsigned int max, unsigned int value){
	unsigned int min = 1, temp;
	while(min != max ){
		temp = min + (max-min)/2;
		if(a[temp] > value)
			max = temp;
		else 
			min = temp;
			
		if(max-min == 1)
			if(a[min] >= value)
				max = min;
			else min = max;
	}
	return min;
}

unsigned int getIndex(unsigned int n){
	for(unsigned int i =1; i <= n && i < MAX_DATA; i++)
		if(a[i-1] < n  && a[i] >= n)
			return i;
	
	return 0;
}
