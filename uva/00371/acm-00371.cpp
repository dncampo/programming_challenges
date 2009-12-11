/**
 * Title: Ackermann Functions
 * URL: http://online-judge.uva.es/p/v3/371.html
 * Resources of interest:
 * Solver group: Yeyo-David
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada intervalo de entrada vamos calculando la funcion X(n)
   y almacenando en un arreglo los valores que se van generando
   para evitar calcularlos en otro ciclo q coincida con esos valores.
   luego se busca el maximo y se imprime el resultado.
**/

#include <iostream>
#include <cstring>
using namespace std;

void solve(unsigned long long a, unsigned long long b, unsigned long long &index, unsigned &result){
   unsigned data [b - a + 1];
   memset(data, 0, sizeof (data));
   unsigned long long i = a;
   
   if(a == 1){
      i++;
      data[0] = 0;
   }
   
   for(; i <= b; i++) {
      unsigned cycle = 0;
      unsigned long long val = i;
      
      while((val > 1 && val < a) || val >= i ) {
         if(val & 1){
            val = 3 * val + 1;
         }
         else {
            val >>= 1;
         }
         cycle++;
      }

      if(val >= a) {
         data[i - a] = data[val - a] + cycle;
      }else {      
         data[i - a] = cycle;
      }      
   }   

   if(a == 1){
      data[0] = 3;
   }
   
   index = 0;
   result = 0;

   for(unsigned i = 0; i <= b - a; i++) {
      if(result < data[i]){
         index = i + a;
         result = data[i];
      }
         
   }
}

int main() {
   unsigned long long a, b, index;
   
   while(cin >> a >> b){
      unsigned result = 0;
      index = 0;
      if(0 == a + b) return 0; 
    
      if(a > b) {
         a ^= b;
         b ^= a;
         a ^= b;
      }
      
      solve(a, b, index, result);
      
      cout << "Between " << a << " and " << b << ", "     
           << index << " generates the longest sequence of " 
           << result << " values." << endl;
   }

   return 0;
}


