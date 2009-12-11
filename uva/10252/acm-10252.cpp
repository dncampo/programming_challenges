/**
 * Title:Common Permutation 
 * URL: http://online-judge.uva.es/p/v102/10252.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para cada par de string de entrada se realiza el siguiente algoritmo:
   -Se los ordena ascendentemente.
   -Se recorre linealmente los string y si tienen un caracter en comun se lo imprime.

   
**/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   string a, b;
   
   while(getline(cin, a) && getline(cin, b)){
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      
      for(int i = 0, j =0; i < a.size() && j < b.size(); i++){
         while(j < b.size() && b[j] < a[i])
            j++;

         if(j < b.size() && a[i] == b[j]){
            cout << a[i];
            j++;
         }
      }
      cout << endl;
   }
   
   return 0;

}

