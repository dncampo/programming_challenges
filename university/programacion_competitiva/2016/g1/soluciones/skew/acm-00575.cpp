/**
 * Title: Skew Binary
 * URL: http://online-judge.uva.es/p/v5/575.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se calculan todas las potencias de 2 posiblemente necesarias y se almacenan en un arreglo
	+ se van leyendo las entradas y se almacenan en un string para procesarlas.
	+ cada entrada se recorre caracter por caracter y se van realizando las operaciones correspondientes.
**/

#include <iostream>

#define PSIZE 32

using namespace std;

unsigned powers[PSIZE];

void init_powers () {
   
   unsigned pow = 0;
   powers[0] = pow;
   for (unsigned i = 1; i < PSIZE; i++) {
      powers[i] = ((powers[i-1] + 1) << 1) - 1;
   }

}

int main () {
   
   init_powers ();
   
   string input;
   
   while (cin >> input) {
      if ("0" == input) {
         break;
      }
      
      unsigned sum = 0;
      string::reverse_iterator rit = input.rbegin();
      for (unsigned c = 1; rit != input.rend(); c++, rit++) {
         sum += powers[c] * (*rit - '0');
      }
      
      cout << sum << endl;
   }
   
   return 0;
}


