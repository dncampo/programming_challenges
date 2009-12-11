/**
 * Title: Palindromes
 * URL: http://online-judge.uva.es/p/v4/401.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se tienen dos funciones para comprobar si una palabra es palindrome o espejada.
   + Para la función espejada se crea un arreglo que contiene la letra espejada para cada
	posición (los lugares con ' ' significa que la letra que corresponde a dicha posición no
	tiene espejado).

**/


#include <iostream>

using namespace std;

char rev[] = {
		'1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', 'A', ' ', ' ', ' ', '3', ' ', ' ', 'H','I', 'L', ' ', 'J', 'M',
		' ', 'O', ' ', ' ', ' ', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'
	};

bool is_palindrome (string& s) {
	for (int i = 0, j = (int)s.size() - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

bool is_mirrored (string& s) {
	for (int i = 0, j = (int)s.size() - 1; i <= j; i++, j--) {
		if (s[i] != rev[ s[j] - '1']) return false;
	}
	return true;
}


int main () {
	string s;
	bool is_pal, is_mirr;
	while (cin >> s) {
		is_pal = is_palindrome (s);
		is_mirr = is_mirrored (s);

		cout << s << " -- is ";
		if (is_pal && is_mirr) cout << "a mirrored palindrome.";
		else if (is_pal && !is_mirr) cout << "a regular palindrome.";
		else if (!is_pal && is_mirr) cout << "a mirrored string.";
		else cout << "not a palindrome.";
		cout << endl << endl;
	}
	return 0;
}
