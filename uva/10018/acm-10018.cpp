/**
 * Title: Reverse and Add
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/100/10018.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Por facilidad en el acceso de los dígitos se almacena el número en un string. Se suma el número
	con su reverso y a continuación se llama a una función que determina si el resultado es palíndromo.
**/

#include <iostream>

using namespace std;

string sum(string);
bool is_pal(string);
void solve(string);

string num1;

int main () {
	unsigned cases;
	string num;
	cin >> cases;
	for (unsigned c = 0; c < cases; c++) {
		cin >> num;
		solve(num);
	}
	return 0;
}

void solve(string num) {
	unsigned short iterations=0;
	string rev_num;
	do{
		iterations++;
		num = sum(num);
	} while(!is_pal(num));
	cout << iterations << " " << num << endl;
}

string sum(string num){
	short carry = 0;
	string total = "";
	
	int c = num.size() - 1, d=0;
	for(; c >= 0; c--,d++){
		string tmp;
		short sum = carry + (num.at(c) - '0') + (num.at(d) - '0');
		tmp.push_back('0' + (sum % 10));
		total = tmp + total;
		carry = sum / 10;
	}
	if(carry) {
		string tmp;
		tmp.push_back('0' + carry);
		total = tmp + total;
	}
	return total;
}

bool is_pal(string num){
	size_t size_num = num.size();
	size_t corte;

	if(0 == (size_num % 2))  //par
		corte = size_num / 2;
	else
		corte = (size_num - 1) / 2;

   for(size_t b=0, c=size_num; b < corte; b++,c--)
		if (num.at(b) != num.at(c-1)) return false;
   
	return true;
}

//EOF

