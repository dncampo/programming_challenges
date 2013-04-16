/**
 * Title: TeX Quotes
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/2/272.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Hay que reemplazar las comillas dobles (") iniciales por dos tildes ` (``) y las finales (") por dos ' ('')
	Para esto se usa una variable booleana para ir marcando si las próximas comillas dobles que aparezcan en el
	texto son de apertura o cierre.
**/


#include <iostream>

using namespace std;

int main (void){
	char c;
	bool open = true;
	while(cin.get(c)){
		if( ('"' == c) && (open)){
			cout << "``";
			open = !open;
		}
		else if(('"' == c) && (!open)){
			cout << "''";
			open = !open;
		}		
		else
			cout << c;		
	}
	return 0;
}
