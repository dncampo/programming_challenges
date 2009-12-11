/** 
 * Title: Count on Cantor
 * URL: http://online-judge.uva.es/p/v2/264.html
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

rational rat[10001629];

int main(){
	rational r1, r2;
	r1.num = 1;
	r1.den = 1;
	
	r2.num = 1;
	r2.den = 2;
	
	rat[1] = r1;
	rat[2] = r2;
	
	bool desciende = true;
	unsigned limit = 1, index = 2;
	for(unsigned i = 0; i < 4471; i++){
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
	

	unsigned term;
	while(cin >> term) cout << "TERM " << term << " IS " << rat[term].num << "/" << rat[term].den << endl;
	
	return 0;
}







