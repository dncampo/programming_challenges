/**
 * Title: Last Digit
 * URL: http://online-judge.uva.es/p/v101/10162.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se va calculando el último dígito para las primeras 100 posiciones y luego se utiliza
	dicha información.
**/


#include <iostream>
#include <cstdlib>

using namespace std;

unsigned last_digit[101];

void precalc () {
	last_digit[1] = 1, last_digit[2] = 5, last_digit[3] = 2;
	last_digit[4] = 8, last_digit[5] = 3, last_digit[6] = 9;
	last_digit[7] = 2, last_digit[8] = 8, last_digit[9] = 7;
	for (unsigned i = 10; i < 100; i++) {
		unsigned last_dig = i % 10;
		if (0 == last_dig || 1 == last_dig || 5 == last_dig) {
			last_digit[i] = (last_dig + last_digit[i-1]) % 10;
			continue;
		}
		
		// Esto se podría hacer más eficiente, pero de esta forma alcanza.
		unsigned tmp = last_dig;
		for (unsigned j = 1; j < i; j++) {
			tmp *= last_dig;
			tmp %= 10;
		}
		last_digit[i] = (tmp + last_digit[i - 1]) % 10;
	}
	last_digit[100] = last_digit[99];
}

int main (){
	precalc();

   string num;
   cin >> num;
   while(num != "0"){
      if(2 < num.size())
         num = num.substr(num.size()-2);

      unsigned val = atoi(num.c_str());
      cout << last_digit[val] << endl;
      cin >> num;
   }
}
