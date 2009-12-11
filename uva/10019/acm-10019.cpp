/**
 * Title: Funny Encryption Method
 * URL: http://online-judge.uva.es/p/v100/10019.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza el "& 1" para ir chequeando si el bit menos significativo está o no activo a la vez
	que se van realizando corrimientos de bits (>> 1) hacia la derecha (16 en total (unsigned short) es 
	suficiente para la entrada máxima posible, que sería 0x9999 = 39321).
	También es necesario convertir el número de entrada a hexadecimal.

**/


#include <iostream>

using namespace std;

unsigned short pow16[] = {1, 16, 256, 4096};

//count the ones
unsigned short count_bits (unsigned short num) {
	unsigned short ret = 0;
	for (unsigned short j = 0; j < 16; j++) {
		ret += num & 1;
		num >>= 1;
	}
	return ret;
}

int main () {
	unsigned short n_cases, num;
	
	cin >> n_cases;
	
	for (unsigned short i = 0; i < n_cases; i++) {
		cin >> num;
		unsigned short b1 = count_bits(num);
		
		unsigned short hex = 0, pow = 0;
		while (num > 0) { //dec to hex
			hex += (num % 10) * pow16[pow++];
			num /= 10;
		}

		cout << b1 << " " << count_bits(hex) << endl;
	}

	return 0;
}