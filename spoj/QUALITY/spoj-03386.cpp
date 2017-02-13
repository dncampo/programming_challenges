/** 
 * Title: Contest System Quality Assurance Tester
 * URL: http://www.spoj.pl/problems/QUALITY/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Tener en cuenta que si un ejercicio se alcanzo a resolver y se ha enviado N veces entonces
	debemos sumar al tiempo que demoro resolverlo (N-1)*20 minutos = (N-1)*PENALTY
	
**/


#include <iostream>
#define PENALTY 1200

using namespace std;

int main(){
	unsigned p1,p2,p3, sec1, sec2, sec3;

	unsigned i = 0;
	while(cin >> sec1 >> sec2 >> sec3 >> p1 >> p2 >> p3){
		i++;
		unsigned count = (0 != sec1)? 1: 0;
		count += (0 != sec2)? 1: 0;
		count += (0 != sec3)? 1: 0;
		
		unsigned sum = 0;
		
		sum += (0 == sec1)? 0: sec1 + (PENALTY * ((0 != sec1)? (p1 - 1): 0));
		sum += (0 == sec2)? 0: sec2 + (PENALTY * ((0 != sec2)? (p2 - 1): 0));
		sum += (0 == sec3)? 0: sec3 + (PENALTY * ((0 != sec3)? (p3 - 1): 0));
				
		cout << "team " << i << ": " << count << ", " << sum << endl;
	}
	return 0;
}

