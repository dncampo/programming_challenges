/**
 * Title: Parentheses Balance
 * URL: http://online-judge.uva.es/p/v6/673.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza una pila para ver si se pueden balancear los paréntesis.

**/

#include <iostream>
#include <stack>

using namespace std;

int main () {
	unsigned n_cases;
	cin >> n_cases;
	cin.ignore(); // el endl

	for (unsigned i = 0; i < n_cases; i++) {
		string line;
		getline (cin, line);
		
		stack<char> s;
		for (unsigned j = 0; j < line.size (); j++) {
			char c = line [j];
			
			if ('(' == c || '[' == c) {
				s.push (c);
			}
			else { // =>  ')' or ']'
				if (s.empty ()) {
					s.push ('a'); //evidentemente esta mal, estonces agrego algo para que la pila no esté vacía
					break; //y al cortar, imprime "No".
				}
				else { //not empty
					if ( (')' == c && '(' == s.top ()) || (']' == c && '[' == s.top ()) ) {
						s.pop ();
					}
					else {
						break;
					}
				}
			}
		}
		if (s.empty ())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
