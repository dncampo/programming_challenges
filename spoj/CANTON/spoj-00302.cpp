/** 
 * Title: Count on Cantor
 * URL: http://www.spoj.pl/problems/CANTON/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Lo importante es darse cuenta de cómo la sucesión tiene forma de zig-zag creciente.
	
**/


#include <iostream>

using namespace std;

struct rational {
	unsigned num;
	unsigned den;
};

//espacio para ir almacenando el máximo caso posible: 10000000 
//le almacena un poco más debido a que por como se armo el bucle for se calcula un 
//poco más de lo necesario, que es preferible a poner un if que corte cuando
//llegue al máximo.
rational rat[10001629]; 
//rational rat[1999001];


int main(){
	rational r1, r2;

	//los primeros dos términos...
	r1.num = 1;
	r1.den = 1;
	
	r2.num = 1;
	r2.den = 2;
	
	rat[1] = r1;
	rat[2] = r2;
	
	bool desciende = true;
	unsigned limit = 1, index = 2;
	for(unsigned i = 0; i < 4471; i++){
//	for(unsigned i = 0; i < 1997; i++){
		for(unsigned k= 0; k < limit; k++){
			index++;
			rational r = rat[index - 1];
			if(desciende){
				r.num++;
				r.den--;			
			}
			else{
				r.num--;
				r.den++;
			}
			rat[index] = r;			
		}
		index++;
		limit++;
		rational r = rat[index-1];
		if(desciende) r.num++;
		else r.den++;
		
		rat[index] = r;		
		desciende = !desciende;
	}

	unsigned ncases;
	scanf("%u",&ncases);
	for(unsigned i = 0; i < ncases; i++){
		unsigned term;
		
		scanf("%u",&term);		
		printf("TERM %u IS %u/%u\n", term, rat[term].num, rat[term].den);
	}
	
	return 0;
}






