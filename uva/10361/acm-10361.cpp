/**
 * Title: Automatic Poetry 
 * URL: http://online-judge.uva.es/p/v103/10361.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se 'tokeniza' la primer línea de cada caso de prueba y se guarda cada parte en un vector.
	+ Luego se siguen las especificaciones del enunciado para armar la salida.

**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve (string &l1, string& l2) {
	unsigned p1, p2;
	string c1, c2;
	vector <string> tokenized;

	p1 = l1.find_first_of ('<', 0);
	p2 = l1.find_first_of ('>', p1);

	tokenized.push_back ( l1.substr (0, p1++) ); //pushing s1
	tokenized.push_back ( l1.substr (p1, p2 - p1) ); //pushing s2

	p1 = l1.find_first_of ('<', p2++);
	tokenized.push_back ( l1.substr (p2, p1 - p2) ); //pushing s3
	p2 = l1.find_first_of ('>', p1++);

	tokenized.push_back ( l1.substr (p1, p2 - p1) ); //pushing s4
	tokenized.push_back ( l1.substr (p2 + 1) ); //pushing s5

	for (unsigned i = 0; i < tokenized.size (); i++)
		cout << tokenized[i];
	cout << endl << l2.substr (0, l2.size () - 3);
	cout << tokenized[3] << tokenized[2] << tokenized[1] << tokenized[4] << endl;
}

int main () {
	unsigned pairs; cin >> pairs; cin.ignore ();

	string line1, line2;
	for (unsigned i = 0; i < pairs; i++) {
		getline (cin, line1);
		getline (cin, line2);
		
		solve (line1, line2);
	}
	return 0;
}
