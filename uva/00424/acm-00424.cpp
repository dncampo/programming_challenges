/**
 * Title: Integer Inquiry
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/4/424.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution: 
	+ Se almacena la suma de los números en un arreglo de hasta 102 posiciones 
	(lo máximo que se puede usar en la suma de 100 números de hasta 100 dígitos cada uno) y se los van 
	sumando.
**/

#include <iostream>
#include <string>

#define DIGS 102

using namespace std;

string num;
short sum[DIGS];

int main(){
	memset(sum, 0, DIGS);
	
	unsigned a;
	while (1){
		cin >> num;
		if("0" == num){ //print output
			bool flag = false;
			for (int b = DIGS-1; b >= 0; b--)
				if((0 != sum[b]) || flag) {
				flag = true;
				cout << sum[b];
				}
				cout << endl;
				return 0;
			}

		int carry = 0;
		a=0;		
		
		for(; a < num.size(); a++){ //let's sum
			sum[a] = sum[a] + carry + (num.at(num.size() - a - 1) - '0');
			carry = sum[a] / 10;
			sum[a] = sum[a] % 10;			
		}
		if(carry){
			while(carry){
				sum[a] = sum[a] + carry;
				carry = sum[a] / 10;
				sum[a] = sum[a] % 10;
				a++;
			}
		}
	}
	return 0;
}

//EOF
