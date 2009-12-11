/**
 * Title: The Decoder
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/4/458.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se le resta 7 a cada uno de los carácteres ASCII leídos y se imprime en la salida estándar.
**/

#include <cstdio>

using namespace std;

int main (){		
   char c;		
   while((c = getchar()) != EOF){		
		if ('\n' != c)
			c -= 7;			
		printf("%c", c);
	}
   return 0;
}

//EOF
