/**
 * Title: Transform the Expression
 * URL: https://www.spoj.pl/problems/ONP/
 * Resources of interest: http://en.wikipedia.org/wiki/Reverse_Polish_notation
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se recorre carácter por carácter el string que representa a la expresión. Si lo que se obtiene es
	un operando se lo va imprimiendo. Si es un operador se lo almacena en una pila, y si es una paréntesis
	de cierre se saca el último operador apilado y se lo imprime.
	+ Se adjunta la URL de una descripción de la Reverse Polish Notation.
**/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void RPN(string);

int main (){
	unsigned cases;
	string algebraic;
	
	cin >> cases;	
	for (unsigned c = 0; c < cases; c++) {
		cin >> algebraic;
		RPN(algebraic);
	}	
	return 0;
}

void RPN(string alg){
	stack<char> opers;
	char tmp;	
	
	unsigned cont = 0;
	while (cont < alg.size()) {
		tmp = alg.at(cont++);
		
		if(')' == tmp) {
			cout << opers.top();
			opers.pop();
		}		
		else if( ('+' == tmp) || ('-' == tmp) || ('*' == tmp) || ('/' == tmp) || ('^' == tmp) )
			opers.push(tmp);		
		else if ('(' != tmp) cout << tmp;		
	}
	cout << endl;
}

//EOF
