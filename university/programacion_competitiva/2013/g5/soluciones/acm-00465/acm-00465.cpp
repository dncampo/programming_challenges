/**
 * Title: Overflow
 * URL: http://online-judge.uva.es/p/v4/465.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se lee la entrada.
   + Se almacenan los operandos en un 'unsigned long long' para que no se desborden y luego se verifica
   si cualquiera de los operandos o el resultado producen overflow. Recordar que en una arquitectura
   de 32 bit, un unsigned long long posee 8 bytes para almacenar el tipo de dato.

**/


#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int main (){
  string aa, bb;
  char op;
  unsigned long long op1, op2, max_int = numeric_limits<int>::max();

  while (cin >> aa >> op >> bb){
	 cout << aa  << " " << op << " " << bb << endl;

	 op1 = atol(aa.c_str());
	 op2 = atol(bb.c_str());

	 if (op1 > max_int)
		cout << "first number too big" << endl;

	 if (op2 > max_int)
		cout << "second number too big" << endl;

	 switch (op) {
		case '+':
		  if (op1 + op2 > max_int) cout << "result too big" << endl;
		  break;

		case '*':
		  if(op1 * op2 > max_int) cout << "result too big" << endl;
		  break;
	 }
  }
  return 0;
}
