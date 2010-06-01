/**
 * Title: Cyclic Numbers
 * URL: http://online-judge.uva.es/p/v9/942.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   + Para cada par de valores (a, b) de la entrada se realiza el siguiente algoritmo:
   - se imprime el valor "a/b" como división entera.
   - luego se imprime el caracter "."
   - luego se realiza una división de (a%b dividido b) mientras el resto no sea cero o no se encuentre que es periodico.
     Para generar un ciclo (o periodo) debe haberse repetido el cociente y resto en la división.
   - luego se imprime la parte que no es cíclica.
   - entre parentesis te imprime si hay una parte cíclica.
   
   formato de salida: (a/b).x[(y)]
   x: digitos no cíclicos
   y: digitos que forman un ciclo.
   Los [] significa que puede estar o nó.
**/

#include <iostream>
#include <vector>
using namespace std;


/*buscar si hay periodo.*/
bool find_cycle(vector<long long>& r, vector<long long>& d){
   if(r.size() == 0) return false;
   
   int lastr = r[r.size()-1], lastd = d[d.size()-1],  i;

   for(i = r.size()-2; i >= 0; i--){
      if(r[i]  == lastr && d[i] == lastd){
         break;
      }
   }
     
   if(i >= 0){
      for(int it = 0; it < i; it++){
         cout << d[0];
         r.erase(r.begin());
         d.erase(d.begin());         
      }
      return true;
   }
   
   return false;    
}
/*resolver hasta que se encuentra un periodo o hasta que se encuentra el resto  = 0*/
void solve_cyclic(long long div, long long divisor){
   vector<long long> digits;
   vector<long long> remainder;
   long long quotient;
   
   while(div > 0 && !find_cycle(remainder, digits)){
      div *= 10;
      quotient = div / divisor;
      div = div - quotient * divisor;
      
      digits.push_back(quotient);
      remainder.push_back(div);
   }
   
   if(digits.size() == 0){
      cout << "0\n";
   } else{
      if(div == 0){
         for(int i = 0; i < digits.size(); i++){
            cout << digits[i];
         }
         cout << "\n";
      } else {
         cout << "(";      
         
         for(int i = 0; i < digits.size()-1; i++){
            cout << digits[i];
         }
         cout << ")\n";
      }
   }
}


void solve(long long a, long long b){
   int div = a/b;
   
   cout << div << ".";
   solve_cyclic(a - div * b, b);
}

int main(){
   int cases, a, b;
   
   cin >> cases;
   
   for(int i = 0; i < cases; i++){
      cin >> a >> b;
      solve(a, b);
   }
   
   return 0;
}
