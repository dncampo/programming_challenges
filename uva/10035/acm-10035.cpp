/**
 * Title: Primary Arithmetic
 * URL: http://acm.uva.es/problemset/v100/10035.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se simula una suma para acumular los acarreos y despues se imprime la solucion.
**/
#include <iostream>
using namespace std;

int main(){
   long long a, b, carry;
   
   cin >> a >> b;
   
   while(a != 0 || b != 0){
      carry = 0;
      //solve;
      if(a < b){
         int tmp = a;
         a  = b;
         b = tmp;
      }
      int tmp = 0;
      while(a > 0){
         tmp = (a % 10 + b % 10 + tmp) / 10;
         carry += tmp;
         a /= 10; 
         b /= 10; 
      }
      
      if(carry == 0){
        cout << "No carry operation." << endl;
      } else {
        cout << carry << " carry operation";
        if(carry > 1) cout << "s";
        cout << "." << endl;
      }
      
      cin >> a >> b;
   }
   return 0;
}
