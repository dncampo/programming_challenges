/** 
 * Title: Error Correction
 * URL: http://online-judge.uva.es/p/v5/541.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Si hay más de una fila o columna con errores de paridad la matriz completa 
   es corrupta. Si sólo hay una fila con error de paridad, también existirá una 
   columna con error.
   + Guardar la fila-columna a corregir.
	
**/

#include <iostream>

using namespace std;

int main(){
	unsigned size;
	
	while (cin >> size) {
		if (0 == size) return 0;
		
		bool mat[size][size], mat_corrupt = false;

		// cargar la matriz		
		for (unsigned i = 0; i < size; i++)
			for (unsigned j = 0; j < size; j++)	cin >> mat[i][j];

		// chequear paridad por filas
		unsigned corrupt_rows = 0, row_to_fix;
		for (unsigned i = 0; i < size; i++){
			unsigned sum = 0;
			
			for (unsigned j = 0; j < size; j++)	{
				if (true == mat[i][j]) sum++;
			}
			if (sum & 1) {
				corrupt_rows++;
				row_to_fix = i + 1;
			}
			if (corrupt_rows > 1) {
				mat_corrupt = true;
				break;
			}
		}

		// chequear paridad por columnas
		unsigned corrupt_cols = 0, col_to_fix;
		for (unsigned j = 0; j < size && !mat_corrupt; j++) {			
			unsigned sum = 0;
			
			for (unsigned i = 0; i < size; i++)	{
				if (true == mat[i][j]) sum++;
			}
			if (sum & 1) {
				corrupt_cols++;
				col_to_fix = j + 1;
			}
			if (corrupt_cols > 1) {
				mat_corrupt = true;
				break;
			}			
		}
		
		if (0 == corrupt_rows && 0 == corrupt_cols) cout << "OK" << endl;
		else if (1 == corrupt_rows && 1 == corrupt_cols) cout << "Change bit (" \
			<< row_to_fix << "," << col_to_fix << ")" << endl;
		else cout << "Corrupt" << endl;
	
	}

	return 0;
}

