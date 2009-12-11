/**
 * Title: Word Scramble
 * URL: http://online-judge.uva.es/p/v4/483.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para cada caracter que pertenezca a una palabra se lo inserta en una pila para luego extraerlo
	e imprimirlo en orden inverso.

**/


#include <iostream>
#include <stack>

using namespace std;

void print_reverse (string& line){
	stack<char> s;

	for (unsigned i = 0; i < line.size(); i++) {
		
		char c = line[i];
		if (c != ' ') {
			s.push(c);
		}
		else {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
	}
	
	//last word
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main () {
	string line;
	while (getline (cin, line))
		print_reverse (line);

	return 0;
}
