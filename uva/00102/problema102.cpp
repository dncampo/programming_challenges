/**
 * Title: Ecological Bin Packing
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/1/102.html
 * Resources of interest:
 * Solver group: David-Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se utiliza un arreglo de BINS*COLORS donde se almacena la cantidad de botellas de un color determinado en un bin dado.
	 Por ejemplo in[x][y] = c cuenta la cantidad *c* de botellas de color *y* que hay en el bin *x*.
	 *x* puede ser 0,1 ó 2, que se corresponde con el primero, segundo y tercer bin.
	 Luego *y* también puede ser 0, 1 ó 2; que se coresponde con *Brown*, *Green* y *Clear* respectivamente.
	 Entonces, por ejemplo in[2][0] = 8, significa que tenemos en el bin *2* 8 botellas color *Brown*.
	 + Luego se calculan las sumas de movimientos para todas las permutaciones de posibles soluciones (BGC es una posible solución, por ejemplo) y esa cantidad se almacena en un vector de movimientos *ordenado* alfabéticamente (BCG,BGC,CBG, etc.) para luego consultar la configuración con menos movimientos.
	 + Como punto a favor tenemos que esta implementación es muy rápida y fácil de codificar.
	 + Como punto en contra se tiene que esta forma de resolver sólo funciona para este problema en particular y es muy difícil de generalizar a distinto número de BIN o COLORS.
**/


#include <iostream>

#define COLORS 3
#define BINS COLORS
#define POSIB 6 //factorial de COLORS (permutaciones)

using namespace std;

unsigned in[BINS][COLORS]; //cantidad de botellas COLOR en bin BIN.
unsigned posib[POSIB]; //posib[0] -> BCG, posib[1]-> BGC, etc (orden alfab)...

int main (int argc, char **argv){

  while(cin >> in[0][0] >> in[0][1] >> in[0][2] \
				>> in[1][0] >> in[1][1] >> in[1][2] \
				>> in[2][0] >> in[2][1] >> in[2][2]) {

	 posib[0] = in[1][0] + in[2][0] + in[0][2] + in[2][2] + in[0][1] + in[1][1]; //BCG
	 posib[1] = in[1][0] + in[2][0] + in[0][1] + in[2][1] + in[0][2] + in[1][2]; //BGC
	 posib[2] = in[1][2] + in[2][2] + in[0][0] + in[2][0] + in[0][1] + in[1][1]; //CBG
	 posib[3] = in[1][2] + in[2][2] + in[0][1] + in[2][1] + in[0][0] + in[1][0]; //CGB
	 posib[4] = in[1][1] + in[2][1] + in[0][0] + in[2][0] + in[0][2] + in[1][2]; //GBC
	 posib[5] = in[1][1] + in[2][1] + in[0][2] + in[2][2] + in[0][0] + in[1][0]; //GCB

	 unsigned min = 0; //supongo que el min es BCG, para empezar a recorrer
	 for(short a=1; a < POSIB; a++) //empiezo de 1 ya que 0 es el min, por ahora
		if(posib[a] < posib[min])
		  min = a;

	 switch(min) {//la solución es....
		case 0: cout << "BCG " << posib[min]<< endl; break;
		case 1: cout << "BGC " << posib[min]<< endl; break;
		case 2: cout << "CBG " << posib[min]<< endl; break;
		case 3: cout << "CGB " << posib[min]<< endl; break;
		case 4: cout << "GBC " << posib[min]<< endl; break;
		case 5: cout << "GCB " << posib[min]<< endl; break;
	 };
  }
  return 0;
}

//EOF
