/**
 * Title: Zeros and Ones  
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/103/10324.html/external/1/100.html
 * Solver group: Yeyo-Leo-Po-Seba
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Implementamos el algoritmo trivial para resolver el problema:
      Recorremos el arreglo (cadena) linealmente comparando cada elemento
      y observando que se cumpla que sean o todos 0s o todos 1s en el intervalo dado.
**/


#include <iostream>
using namespace std;
#define MAX 1000000

/* cadena de ceros y unos*/
char cadena [MAX];

int main(){
	unsigned cont = 0; // contador de casos , para imprimir case i:
	 
	while(scanf("%s", cadena) != EOF){
		unsigned cases; // cantidad de pruebas.
		scanf("%d", &cases);
		unsigned aa[cases], bb[cases];
		
		for(unsigned i = 0; i < cases; i++)
			scanf("%d%d", &aa[i], &bb[i]);

		printf("Case %d:\n", ++cont);

		unsigned a, b;
		char c;
		// resolver ...
		for(unsigned i = 0; i< cases; i++){
			if(aa[i] > bb[i]) 
				a = bb[i], b = aa[i];
			else
				b = bb[i], a = aa[i];			

			c = cadena[a];
			bool fin = false;
			for(unsigned it = a+1; it <= b && !fin; it++){
				if(cadena[it] != c)
					fin = true;
			}
			// imprimir solucion...
			puts(fin ? "No" : "Yes");
		}

	}

	return 0;
}
