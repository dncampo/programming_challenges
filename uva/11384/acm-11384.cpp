/**
 * Title: Help is needed for Dexter
 * URL: http://uva.onlinejudge.org/external/113/11384.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    + Las distintas salidas siguen un patron determinado que se inicializa en un arreglo, para luego accesarlo.
**/
#include<iostream>

using namespace std;

int num[31];

int main(){
   int p = 2;
   for(int i=1; i<31; i++){
      num[i] = p - 1;
      p *= 2;
   }
   
   int n;
   while(cin >> n){
      int i=1;
      for(; n > num[i]; i++);
      
      cout << i << '\n';
   }
   
   return 0;
}
