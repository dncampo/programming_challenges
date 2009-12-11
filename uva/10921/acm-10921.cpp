/** 
 * Title: Find the Telephone
 * URL: http://online-judge.uva.es/p/v109/10921.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para facilitar y reducir el código se almacena en un map los valores correspondientes a cada
   uno de los posibles caracteres de entrada.   

**/

#include <iostream>
#include <map>

using namespace std;

map<char, unsigned> decoder;

int main() {
  decoder['0'] = 0;
  decoder['1'] = 1;
  decoder['A'] = decoder['B'] = decoder['C'] = 2;
  decoder['D'] = decoder['E'] = decoder['F'] = 3;
  decoder['G'] = decoder['H'] = decoder['I'] = 4;
  decoder['J'] = decoder['K'] = decoder['L'] = 5;
  decoder['M'] = decoder['N'] = decoder['O'] = 6;  
  decoder['P'] = decoder['Q'] = decoder['R'] = decoder['S'] = 7;  
  decoder['T'] = decoder['U'] = decoder['V'] = 8;
  decoder['W'] = decoder['X'] = decoder['Y'] = decoder['Z'] = 9;  

  string line;
  while (cin >> line) {
    for (unsigned i = 0; i < line.size(); i++){
      if ('-' != line[i]) cout << decoder[line[i]];
      else cout << '-';
    }
    cout << endl;
  }
  
  return 0;
}
