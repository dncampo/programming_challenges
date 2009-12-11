/** 
 * Title: Train Swapping
 * URL: http://online-judge.uva.es/p/v2/299.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + La clave es darse cuenta que hay que contar la cantidad de intercambios que se realizan 
   en una ordenación con el método burbuja (bubble sort)
	
**/


#include <iostream>

using namespace std;


unsigned bubble_sort(unsigned a[], unsigned size){
	unsigned count = 0;
	
	for (unsigned j = 1; j <= size; j++) {          
	   for (unsigned i = 0; i < size-1; i++)
                       { 
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
	unsigned n_cases;
	
	cin >> n_cases;
	
	for(unsigned i = 0; i < n_cases; i++){
		unsigned size;
		cin >> size;
		
		unsigned carriages[size];
		
		for(unsigned j = 0; j < size; j++)
			cin >> carriages[j];

		cout << "Optimal train swapping takes " << bubble_sort(carriages, size) << " swaps." << endl;	
	}

	return 0;
}

