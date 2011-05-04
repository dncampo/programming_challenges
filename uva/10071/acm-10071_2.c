/**
 * Title: Back to High School Physics
 * URL: http://online-judge.uva.es/p/v100/10071.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Dado un tiempo t y una velocidad constante v, se calcula la distancia recorrida por una 
	partícula en el tiempo 2*t.

**/

#include <stdio.h>


int main(){
	short t,v;
	
	while(~scanf("%hd", &v)){
		scanf ("%hd", &t);
		printf ("%d\n", (t*v) << 1);
	}	
	return 0;
}
