/**
 * Title: Factorial! You Must be Kidding!!! 
 * URL: http://uva.onlinejudge.org/external/103/10323.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Simplemente se imprime la solucion de los casos válidos. 
   El unico detalle importante en este problema es que el in puede ser negativo y hay que definir el factorial para el caso negativo:
   n! =n*(n-1)! -> (n-1)! = n!/n ->  n! = (n+1)! / (n+1)
   entonces 
   si in=-1 --> 1! = fact(0)/0 (overflow)
   si in=-2 --> 2! = fact(-1)/(-1)=-infinity so underflow 
   ....
**/

#include <iostream>
using namespace std;

int main(){
   int in;

   while(cin >> in){
      if(in < 0){
         in = -in;
   
         if(in & 1)
            cout << "Overflow!" << endl;                  
         else 
            cout << "Underflow!" << endl;
      }else  if(in < 8) {
         cout << "Underflow!" << endl;
      } else if(in > 13){
         cout << "Overflow!" << endl;         
      } else{
         switch(in){
            case 8:  cout << 40320 << endl; break;
            case 9:  cout << 362880 << endl; break;
            case 10: cout << 3628800 << endl; break;
            case 11: cout << 39916800 << endl; break;
            case 12: cout << 479001600 << endl; break;
            case 13: cout << 6227020800 << endl; break;
         }
      }
   }
   return 0;
}

