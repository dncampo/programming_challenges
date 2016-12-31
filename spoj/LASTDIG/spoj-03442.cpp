/**
 * Title: The last digit
 * URL: https://www.spoj.pl/problems/LASTDIG/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para resolver este problema se ha tomado en cuenta que el último dígito de la operación de multiplicar
	un número n por sí mismo m veces tiene un "ciclo" que depende de n y m. Por ejemplo el resultado de hacer
	5 elevado a la m siempre termina con el número 5. En cambio un número terminado en 7 tiene un ciclo que va
	rotando entre 7, 9, 3, 1. Por ejemplo 7^5 finaliza en 7, 7^6 en 9, 7^7 en 3, 7^8 en 1, y 7^9 en 7 volviendo
	a comenzar el ciclo. Tomando esto en cuenta (los ciclos de algunos números son de 4 "vueltas" y de otros 1)
	se almacenaron los ciclos de todos los números (que terminan en 0-9).
	+ Como complejidad adicional, el código fuente de este problema no debe superar los 700 bytes
	(por ello para enviar este código sólo copie lo necesario y elimine cualquier comentario o línea en
	blanco de más).
**/


#include <iostream>

typedef unsigned ui;

ui c2[] = {2,4,8,6}, c3[] = {3,9,7,1}, c7[] = {7,9,3,1}, c8[] = {8,4,2,6};

void p(ui);
ui r(ui);

ui a,b,t,j;

int main (){	
	std::cin >> t;
	for(; j < t; j++){
		std::cin >> a >> b;
		a %= 10;
		if(0==b) p(1);	
		else if(1==a)p(1);
		else if(0==a) p(0);
		else if(6==a) p(6);
		else if(4==a) (0==(b%2)) ? p(6) : p(4);
		else if(9==a) (0==(b%2)) ? p(1) : p(9);
		else if(2==a) p(c2[r(b)-1]);
		else if(3==a) p(c3[r(b)-1]);
		else if(7==a) p(c7[r(b)-1]);
		else if(8==a) p(c8[r(b)-1]);
		else p(5);
	}
	return 0;
}
void p(ui n){
	std::cout << n << std::endl;
}
ui r(ui n){
	while( n > 4) n -= 4;
	return n;
}
