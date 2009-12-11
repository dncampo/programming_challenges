/**
 * Title: Fibonaccimal Base
 * URL: http://uva.onlinejudge.org/external/9/948.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
 * 	Se inicializa un array con la sucesion de Fibonacci (en orden invertido) para tener
 * 	los valores a usar para representar la base "fibonaccimal". Luego se recorre el array formando
 * 	la nueva representacion del numero, colocando '1' y '0' segun corresponda.
 */

#include<iostream>
#include<string>

#define SIZE 40

using namespace std;

unsigned fib[SIZE];

int main(){

	unsigned ant1 = 1;
	unsigned ant2 = 0;
	
	// Inicializar array fib
	for(int i=SIZE-1; i>=0; i--){
		fib[i] = ant1 + ant2;
		ant2 = ant1;
		ant1 = fib[i];
	}

	int n;
	cin >> n;
	unsigned num;
	int j;
	
	for(int i=0; i<n; i++){
		cin >> num;
		string res = "";

		// Pasar a base fibonaccimal:
		
		// Posicionar el indice en el numero de Fibonacci mas grande
		// que sea menor o igual a num
		j = SIZE-1;
		while(num > fib[j]) j--;
		
		if(fib[j] > num) j++;
		
		// Formar la nueva representacion del numero
		unsigned temp = num;
		while(j < SIZE){
			if(temp >= fib[j]){
				temp -= fib[j];
				res += "1";
			}
			else
				res += "0";
			j++;
		}
		
		cout << num << " = " << res << " (fib)" << endl;
	}

	return 0;
}
