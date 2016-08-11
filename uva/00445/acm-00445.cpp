/*
* Title: Marvelous Mazes
* Tags: ad-hoc, simulation, parsing, strings
* URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=386
* Resources of interest:
* Solver group: David
* Contact e-mail: dncampo at gmail dot com
* Notes: 
    + Ad-Hoc problem. Simulate the labyrinth creation process.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

	string line;
	while (getline (cin, line)) {
		if (1 == line.size ()) //new maze
			line = "";

		unsigned rep = 0;
		for (unsigned i = 0; i < line.size (); i++) {
			if (isdigit (line[i])) {
				char c[2];
				c[0] = line[i];
				c[1] = '\0';
				rep += atoi (c);
			}
			else if ('!' == line[i]) cout << endl; 
			else {
				if ('b' == line[i])	cout << string(rep, ' ');
				else cout << string(rep, line[i]);
				rep = 0;
			}
		}
		cout << endl;
	}

	return 0;
}
