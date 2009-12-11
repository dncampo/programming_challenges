/**
 * Title: Funny Encryption Method
 * URL: http://online-judge.uva.es/p/v100/10019.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se toma el número y se lo convierte a hexadecimal.
	Luego se usa un conjunto de bits (bitset) para contabilizar los 1's.

**/


#include <bitset>

unsigned short pow16[] = {1, 16, 256, 4096};

int main () {
	unsigned short n_cases, num;
	
	scanf("%hu",&n_cases);
	
	for (unsigned short i = 0; i < n_cases; i++) {
		scanf ("%hu", &num);
		
		std::bitset<16> b1_bs(num);
		
		unsigned short hex = 0, pow = 0;
		while (num > 0) { //dec to hex
			hex += (num % 10) * pow16[pow++];
			num /= 10;
		}
		std::bitset<16> b2_bs (hex);

		printf("%u %u\n",(unsigned)b1_bs.count(), (unsigned)b2_bs.count());
	}

	return 0;
}