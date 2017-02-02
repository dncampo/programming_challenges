/**
 * Title: Traveling Salesman
 * URL: https://www.spoj.pl/problems/FAKETSP/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se van obteniendo los strings que representan las coordenadas actuales del viajante y luego se
   convierten a double utilizando flujos de C++.
   + Para el recorrido total viajado se utiliza la fórmula de la distancia euclídea entre 2 puntos.

**/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

void get_val(string& line, double &x, double &y) {
   stringstream ss1, ss2;
   unsigned pos_a = line.find_first_of('(');
   unsigned pos_b = line.find_first_of(',');
   string a = line.substr(pos_a + 1, pos_b - pos_a);

   pos_a = pos_b + 1;
   pos_b = line.find_first_of(')');
   string b = line.substr(pos_a, pos_b - pos_a);

   ss1 << a;
   ss1 >> x;
   ss2 << b;
   ss2 >> y;
}


int main() {
   double sx, sy, x, y, dist = 0.0;
   string line;

   getline(cin, line);
   get_val(line, sx, sy);

   while (getline(cin,line)) {
      get_val(line, x, y);
      dist += sqrt( pow(sx - x, 2.0) + pow(sy - y, 2.0) );
      printf("The salesman has traveled a total of %.3f kilometers.\n", dist);
      sx = x, sy = y;
   }

   return 0;
}
