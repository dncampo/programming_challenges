/**
 * Title: Recognizing Good ISBNs
 * URL: http://uva.onlinejudge.org/external/3/333.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Problema tipo 'Ad-Hoc' en el que hay que tratar de seguir de forma ordenada los posibles casos
	que se presenten: delimitar cuales son los caracteres permitidos en un ISBN, si hay una X que aparezca
	en la décima posición, que el ISBN tengo sólo 10 dígitos (X = "dígito" 10), que el la segunda suma del
	ISBN se múltiplo de 11.

**/


#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool divisible_by_11(vector<unsigned>& ISBN) {
	vector <unsigned> s1 (10), s2(10);
	s1[0] = ISBN[0];

	for (unsigned i = 1; i < 10; i++)
		s1[i] = s1[i-1] + ISBN[i];

	s2[0] = s1[0];
	for (unsigned i = 1; i < 10; i++)
		s2[i] = s2[i-1] + s1[i];

	return 0 == (s2[9] % 11);
}

void process_line (string & line) {
	string fixed_line;
	
	for (unsigned i = 0; i < line.size(); i++) { //saco los espacios
		char c = line[i];

		//if (isspace(c)) continue;
		if (' ' == c) continue;

		fixed_line.push_back(c);
	}
	
/*	string valid_chars = "0123456789X-"; //si aparece un char distinto a uno de estos es inválido
	bool may_valid = fixed_line.find_first_not_of (valid_chars) == string::npos;

	if (!may_valid) {
		cout << fixed_line << " is incorrect." << endl;
		return;
	}
*/
	
	vector <unsigned> ISBN;
	unsigned Xs = 0;
	for (unsigned i = 0; i < fixed_line.size(); i++) {
		char ch = fixed_line[i];
		if (isdigit (ch) ) {
			ISBN.push_back(ch - '0'); //voy guardando el dígito en un vector de dígitos
			continue;
		}
		
		if ('X' == ch) { //cuento las Xs, debe haber a lo sumo 1.
			Xs++;
			ISBN.push_back(10); //X == 10
			continue;
		}
		else continue;
	}
	
	if (10 != ISBN.size() || (Xs > 1) || (Xs > 0 && 10 != ISBN[ISBN.size() - 1]) || \
		!divisible_by_11(ISBN)) { //posible casos inválidos
		cout << fixed_line << " is incorrect." << endl;
		}
	
	else { //al fin!!
		cout << fixed_line << " is correct." << endl;
	}
	return;
}

int main () {
	string line;
	while (getline (cin, line) ) {
		process_line (line);
	}

	return 0;
}
