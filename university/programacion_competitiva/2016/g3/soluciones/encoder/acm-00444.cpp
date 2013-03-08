/**
 * Title: Encoder and Decoder
 * URL: http://online-judge.uva.es/p/v4/444.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utilizan varias funciones auxiliares para codificar o decodificar un mensaje.
	+ Se debe tener espcial cuidado cuando se decodifica un mensaje dado que hay casos en los que se
	deben tomar de a dos letras y hay casos en los que se deben tomar de a tres letras. Por ejemplo:
	suponer un mensaje codificado como sigue: 811234..... (continúa). Si se tomasen los 2 primeros 
	números, se los invierte y se obtiene 18, que no pertenece a un carácter válido. Por lo tanto deberían 
	tomarse los 3 primeros que se convierten en 118 (letra v).
	Por otro lado sea el mensaje codificado como: 98732..... Si se tomasen los 3 primeros números daría
	789, que no pertenece al rango válido (el máximo valor ASCII del problema es 122). Por ello deben
	tomarse los 2 primeros números que se convierten en 89 (letra Y).

**/


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const unsigned MAX = 122; //max ASCII value used
bool valid [MAX + 1] = { false }; //valid ASCII values

// unsigned to string
string reverse (unsigned rev) {
	stringstream res;

	while (rev > 0) {
		res << (rev % 10);
		rev /= 10;
	}
	return res.str ();
}

//string to unsigned
unsigned reverse (string& rev) {
	string tmp;
	unsigned res;
	stringstream ver;

	for (string::const_reverse_iterator it = rev.rbegin (); it != rev.rend (); it++){
		tmp = tmp + *it;
	}

	ver << tmp;
	ver >> res;
	return res;
}

// initialize valid characters
void init () {
	valid [32] = true; valid [33] = true; valid [44] = true;
	valid [46] = true; valid [58] = true; valid [59] = true;
	valid [63] = true;
	
	for (unsigned i = 65; i <= 90; i++)
		valid [i] = true;

	for (unsigned i = 97; i <= MAX; i++)
		valid [i] = true;
}


string encode (string &line) {
	string res = "";
	for (string::const_reverse_iterator it = line.rbegin (); it != line.rend (); it++) {
		res = res + reverse (*it);
	}

	return res;
}

string decode (string &line) {
	unsigned i = 0;
	string res = "";

	while (i < line.size () - 1) {
		string tmp = line.substr (i, 2);
		unsigned rev = reverse (tmp);

		//see if two numbers belongs to a valid letter
		// e.g.: 81... -> it's 18 and does not belong to a valid char
		if ( rev < MAX && valid[rev]) {
			i += 2;
		}
		// e.g.: 811... -> it's 118 and belong to a valid char (see that 18 cannot be converted)
		else {
			tmp = line.substr (i, 3);
			rev = reverse (tmp);
			i += 3;
		}

		res = (char)rev + res;
	}
	return res;
}


int main () {
	string line;
	init ();

	while (getline (cin, line)) {
		if (isdigit (line[0]))
			cout << decode (line) << endl;
		else
			cout << encode (line) << endl;
	}
	return 0;
}
