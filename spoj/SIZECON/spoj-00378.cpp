/**
 * Title: Size Contest
 * URL: http://www.spoj.pl/problems/SIZECON/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se debe ir sumando todos los números no negativos de la entrada estándar, usando la mínima cantidad
	de carácteres en el código fuente. (Hay lenguajes que son más adecuados que C++ para este problema)
**/

#include <iostream>

using namespace std;
int t,n,r,a;
int main(){
	cin >> t;
	while(a++<t) cin>>n, r += (n > 0) ? n : 0;
	cout << r << endl;
}

//EOF
