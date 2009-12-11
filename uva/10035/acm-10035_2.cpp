/** 
 * Title: Problem B: Primary Arithmetic
 * URL: 10035
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se van ``cortando'' los números a y b desde la cifra menos significativa y se va sumando
   este valor, verificando si hay o no acarreo, mientras haya cifras para sumar.
	
**/


#include <iostream>

using namespace std;

int main(){
	unsigned a, b;
	
	while (true) {
		cin >> a >> b;
		
		if(0 == a && 0 == b) return 0;
		
		if(a < b) { //swap :)
			a ^= b;
			b ^= a;
			a = b ^ a;
		}
		
		unsigned last_carry = 0, carries = 0;
		while (a > 0){
			last_carry = (a % 10) + (b % 10) + last_carry;
			a /= 10;
			b /= 10;
			
			if (last_carry > 9) {
				carries ++;
				last_carry /= 10;
			}
			else last_carry = 0;
		}
		
		if (1 == carries) cout << carries << " carry operation." << endl;
		else if (1 < carries) cout << carries << " carry operations." << endl;
		else cout << "No carry operation." << endl;
	}
	return 0;
}

