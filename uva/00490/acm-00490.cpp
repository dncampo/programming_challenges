/**
 * Title: Rotating Sentences
 * URL: http://online-judge.uva.es/p/v4/490.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se almacenan las líneas de texto en un vector<string> y se lo recorre por columnas en primer lugar
  y por filas (empezando por la última) en segundo lugar.

**/

#include <iostream>
#include <vector>

using namespace std;

int main () {
	string line;
	vector <string> data;

	while (getline (cin, line))
		data.push_back(line);

  unsigned max = 0;
  for (unsigned i = 0; i < data.size(); i++) // max sentence size
	 if (data[i].size() > max)
		max = data[i].size();

  for (unsigned col = 0; col < max; col++) { // by col
	 for (int i = data.size() - 1; i >= 0; i--) { // by row, last first

		  if (col < data[i].size())
			 cout << data[i][col];
		  else
			 cout << " ";
	 }
		cout << endl;
  }
  return 0;
}
