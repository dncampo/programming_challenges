/** 
 * Title: Prince and Princess
 * URL: http://uva.onlinejudge.org/external/106/10635.html
 * Resources of interest:
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Primero se tranforma los saltos de la segunda secuencia (princesa) en indices de la primera 
   secuencia  y se lo almacena como tal en un vector. Para realizar esta tarea en forma logaritmica
   se almacena en un mapa la primer secuencia de la siguiente forma : 
   valor = numero, 
   clave: posicion en la secuencia
   Luego se utiliza un LIS sobre el vector de indices generado para resolver le problema
**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

int LIS(const vector<int>& input){
    set<int> s;
    set<int>::iterator k;

    for(unsigned i = 0; i < input.size(); i++){
        if(s.insert(input[i]).second){
           k = s.find(input[i]);
          
           if(++k != s.end()){
              s.erase(k);
           }
        }
    }
    return s.size();
}

int main() {
	int cnt = 1;

	unsigned n_cases;
	scanf("%d", &n_cases);
	
	for(unsigned i = 0; i < n_cases; i++) {
	   unsigned n, p, q;
	   
   	scanf("%d%d%d", &n, &p,&q);

      vector<int> prince(p+1);
      map<unsigned, unsigned> m;
	   for (unsigned j = 0; j<=p; j++){
      	scanf("%d", &prince[j]);
	      m[prince[j]] = j;
	   }

      vector<int> princess(q+1);
	   for (unsigned j = 0; j<=q; j++){
	      unsigned tmp;
      	scanf("%d", &tmp);
	      princess[j] = m[tmp];
	   }

      printf("Case %d: %d\n", cnt++, LIS(princess));
	}	
	return 0;
}

