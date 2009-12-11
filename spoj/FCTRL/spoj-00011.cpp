/**
 * Title: Factorial
 * URL: https://www.spoj.pl/problems/FCTRL/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza una fórmula para calcula el valor de Z(N)
**/

#include <cstdio>

unsigned multiples[14] =
	{ 1, 5, 25, 125, 625, 3125, 15625,
		78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125 };

int main(){
	unsigned cases;
	unsigned sum, div, i, in;

	scanf("%u",&cases);
	for(unsigned j = 0; j < cases; j++) {
		i = 1, sum = 0;

		scanf("%u" ,&in);
		do{
			div = in / multiples[i];
			sum += div;
			i++;
		}while (div > 0);

		if(j == cases -1)
			printf("%u",sum);
		else
			printf("%u\n",sum);
	}
	return 0;
}
