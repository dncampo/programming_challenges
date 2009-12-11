/** 
 * Title: Above Average
 * URL: http://online-judge.uva.es/p/v103/10370.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calcula la media de la clase, se cuentan los alumnos que la sobrepasan y se
   calcula el porcentaje. Tener en cuenta el redondeo...
	
**/


#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main(){
	unsigned n_cases;
	cin >> n_cases;
	
	for (unsigned i = 0; i < n_cases; i++){
		unsigned n;
		cin >> n;
		
		vector <unsigned> grades(n);
		
		for (unsigned j = 0; j < n; j++) cin >> grades[j];
		
		unsigned avg = accumulate(grades.begin(), grades.end(), 0) / n; 
		
		unsigned above = 0;
		
		for(unsigned k = 0; k < n; k++) if (grades[k] > avg) above++;
		
		float percentage = (above * 100 / (float)n);
		
		cout << fixed << showpoint << setprecision(3);	
 
		cout << percentage << "%" << endl;
	}

	return 0;
}

