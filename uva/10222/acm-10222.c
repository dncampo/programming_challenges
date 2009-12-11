/**
 * Title: Decode the Mad man
 * URL: http://online-judge.uva.es/p/v102/10222.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacena en un arreglo el desplazamiento correspondiente a cada posible caracter de entrada
	y se lo accesa a traves su valor ASCII.

**/

#include <stdio.h>

char decode[] =
		{ 0,
			 1,  2,  3,  4,  5,   6,  7,  8,  9, 10,    11,12, 13, 14, 15,  16, 17, 18, 19, 20,
			21, 22, 23, 24, 25,  26, 27, 28, 29, 30,   ' ',32, 33, 34, 35,  36, 37, 38, 'l',40,
			41, 42, 43, 'n','9', 'm',',','8',49,'`',   '1','2','3','4','5', '6','7',58, 'k',60,
			'0',62, 63, 64, 65,  'c','z','a','q','s',  'd','f','y','g','h', 'j','b','v','u','i',
			81, 'w',83, 'e','t', 'x', 87, 88, 'R',90,  'o','[','p',94, 95,  96, 97, 'c','z','a',
			'q','s','d','f','y', 'g','h','j','b','v',  'u','i',113,'w',115, 'e','t','x',119,120,
			'r', 122
		};

int main () {
	int c;
	while (EOF != (c = getchar()))
		printf ("%c", decode[c]);
	return 0;
}
