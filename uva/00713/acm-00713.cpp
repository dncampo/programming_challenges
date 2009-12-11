/**
 * Title: Adding Reversed Numbers
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/7/713.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se leen los números a sumar en dos strings. Al número que tenga menos cifras se le agregan ceros
	por derecha para hacer más sencilla la suma. Luego se suman ambos números (strings) cifra por cifra 
	empezando por la izquierda (reverse sum) y acarreando hacia la derecha. A medida que se van sumando 
	las cifras se van acumulando en un string para su posterior impresión.
**/


#include <iostream>
#include <string>

using namespace std;

void sum(void);
void padding(void);

string num1,num2;	

int main (){	
	unsigned cases;
	cin >> cases;
	for (unsigned c = 0; c < cases; c++) {
		cin >> num1 >> num2;	 
		padding();
		sum();
	}
}

void padding(){
	if(num1.size() > num2.size())
		while(num1.size() > num2.size())	num2 = num2 + "0";	
	else
		while(num2.size() > num1.size())	num1 = num1 + "0";
}

void sum (){
	size_t size = num1.size();
	string print ="";
	unsigned carry = 0;
	
	for(size_t a = 0; a < size; a++){
		short val = num1[a] - '0' + num2[a] - '0';
		short sum = (val + carry) % 10;
			print += '0' + sum;
		carry = (carry + val) / 10;		
	}
	if(carry) print += '0' + carry;
	
	while('0' == print.at(0) && print.size() > 1) print = print.substr(1); //without leading zeros
	for(size_t a = 0; a < print.size(); a++)
		cout << print.at(a);
	cout << endl;
}

//EOF
