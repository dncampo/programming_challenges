/**
 * Title: Simple Arithmetics II
 * URL: https://www.spoj.pl/problems/ARITH2/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se va operando sobre la entrada, hasta que el operador sea '='.

**/


#include <iostream>

using namespace std;

int main (){
	unsigned cases;
	char op;
	
	unsigned long long tmp_num, result;
	
	cin >> cases;
	
	for (unsigned i = 0; i < cases; i++){
		cin >> result;
		cin >> op;
		
		while('=' != op){
			cin >> tmp_num;
			
			if('+' == op)
				result += tmp_num;
				
			else if ('-' == op)			
				result -= tmp_num;
				
			else if ('*' == op)			
				result *= tmp_num;
				
			else
				result /= tmp_num;
			
			cin >> op;
		}
		cout << result << endl;		
	}
	return 0;
}
