/**
 * Title: Hashmat the brave warrior
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/100/10055.html
 * Resources of interest:
 * Solver group: Yeyo-David
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Se resta el número más grande menos el más chico.
	+ Es muy importante tener en cuenta que un unsigned int o unsigned long no son suficientes dado que
	estos tipos de datos van de 0 a 2^32 - 1, y el enunciado dice que puede llegar a tomar hasta 2^32.
**/

#include <iostream>
using namespace std;


int main(){
   unsigned long long a, b;
   while(cin >> a >> b) cout << (a>b ? (a-b): (b-a)) << endl;
   return 0;
}

//EOF