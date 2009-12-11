/** 
 * Title: Flip Sort
 * URL: http://online-judge.uva.es/p/v103/10327.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + La clave es darse cuenta que hay que contar la cantidad de intercambios que se realizan 
   en una ordenación con el método burbuja (bubble sort)
	+ Para el peor caso, es decir con 1000 números ordenados de forma descendente: 1000 999 998...3 2 1,
	tomará; (1000 * 999) / 2 = 499500 operaciones
**/


#include <iostream>

using namespace std;


unsigned bubble_sort(unsigned a[], unsigned size){
	unsigned count = 0;
	
	for (unsigned j = 1; j <= size; j++) {
	   for (unsigned i = 0; i < size-1; i++) {
 			if (a[i] > a[i+1]){
 				count ++;
 				unsigned temp = a[i];
 				a[i] = a[i+1];
 				a[i+1] = temp;
			}
		}
	}
	return count;
}

int main(){
	unsigned size;

	while (cin >> size) {
		unsigned nums[size];

		for(unsigned j = 0; j < size; j++)
			cin >> nums[j];

		cout << "Minimum exchange operations : " << bubble_sort(nums, size) << endl;
	}

	return 0;
}

