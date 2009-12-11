/** 
 * Title: Power Crisis
 * URL: http://online-judge.uva.es/p/v1/151.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se trata de un algoritmo ad-hoc. Lo más importante es tratar de hacer la
   simulación de la solución como si lo resolviéramos con lapiz y papel. Es un 
   poco engorroso pero con paciencia y órden no es complicado.
	
**/



#include <iostream>

using namespace std;

bool test (bool cities[], unsigned size, unsigned m){
	unsigned	count = size - 1;
	
	unsigned index = 1, m_count = 0;
	cities[0] = true;
	
	while (count > 0){
		m_count = 0;
	
		while (m_count < m){
		
			if(index == size) index = 0;
			
			if(true == cities[index]) {
				index++;
				continue;
			}
			else{
				index++;
				m_count++;
			}
		}
		
		if(index == 13) {
			if (1 == count) return true; //13 es la ultima
			else return false; //caimos en donde no debíamos..
		}			

		else {
			cities[index - 1] = true;
			count--;
		}

	}
	cout << endl;
	return true;
}


int main(){
	unsigned n;

	while (cin >> n){
		if (0 == n) return 0;
	
		bool cities[n];
		
		for (unsigned i = 0; i < n; i++) cities[i] = false;
	
		unsigned m = 1;
		

		while (false == test (cities, n, m)) {
			m++;	
			for (unsigned i = 0; i < n; i++) cities[i] = false; //seteamos a false debido a que intentamos con otro m
		}

		cout << m << endl;
	}
	return 0;
}

