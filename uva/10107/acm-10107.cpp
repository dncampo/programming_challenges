/** 
 * Title: What is the Median?
 * URL: http://online-judge.uva.es/p/v101/10107.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se mantiene un conjunto ordenedo de los números de entrada (multiset) y se mantiene una 
	posición que corresponde o al centro del conjunto (si es impar) o al primero de los dos
	números para obtener el promedio (si es par)
	
**/

#include <iostream>
#include <set>

using namespace std;

int main() {
  unsigned num, pos = 0;
  multiset<unsigned> data;
  
  while (cin >> num){
	 data.insert(num);

	 multiset<unsigned>::iterator it = data.begin();
	 for (unsigned j = 0; j < pos; j++) it++;

	 //odd size
	 if (data.size() & 1) {
		cout << *it << endl;
	 }
	 else {
		unsigned sum = (*it + *++it) / 2;
		cout << sum << endl;
		pos++; 
	 }
	 
  }

  return 0;
}
