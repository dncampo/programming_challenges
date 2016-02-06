/**
 * Title: Anti-Blot System
 * URL: https://www.spoj.pl/problems/ABSYS/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se busca en cada uno de los operandos y en el resultado hasta encontrar la letra 'm' en alguno
	de estos números. Luego se resuelve la ecuación conforme este dato para revelar al numero perdido.

**/


#include <iostream>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	
	for (int i = 0; i < cases; i++){
		int val_a, val_b, val_r;
		string a,b,op1,op2, res;
		cin >> a >> op1 >> b >> op2 >> res;
		
		if( a.find("m") != string::npos) {
			val_b = atoi(b.c_str());
			val_r   = atoi(res.c_str());
			val_a = val_r - val_b; 
		}
		else if( b.find("m") != string::npos) {
			val_a = atoi(a.c_str());
			val_r   = atoi(res.c_str());
			val_b = val_r - val_a; 
		}
		else {
			val_b = atoi(b.c_str());
			val_a = atoi(a.c_str());
			val_r   = val_a + val_b;
		}
		
		cout << val_a << " + " << val_b << " = " << val_r << endl;
	}
	return 0;
}
