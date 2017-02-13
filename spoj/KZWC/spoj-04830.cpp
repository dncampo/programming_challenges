/** 
 * Title: Z meet
 * URL: http://www.spoj.pl/problems/KZWC/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacena en un vector bidimensional las fechas necesarias, ordenadas por letra (a partir
   de la A)
	
**/

#include <iostream>
#include <cmath>

using namespace std;

unsigned values[][2] = { {2001, 2005}, {2002, 2006}, {2003, 2007}, {2004, 2008},
								{2005, 2009}, {2006, 2010}, {2007, 2011} };


int main(){
	unsigned n_cases;
	
	cin >> n_cases;
	

	for(unsigned a = 0; a < n_cases; a++){
		unsigned year, strength = 0;
		string arrangement;		
		cin >> year >> arrangement;
	
		for(unsigned i = 0; i < arrangement.size(); i++){
			unsigned c = arrangement[i] - 'A';
			unsigned val = values[c][1];
			strength += (year > val ? (pow(double(year - val), 2.0)): pow(double(year - values[c][0]), 2.0) );		
		}
		cout << strength << endl;
	}

	return 0;
}

