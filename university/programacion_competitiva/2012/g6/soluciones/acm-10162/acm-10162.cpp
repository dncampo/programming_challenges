/**
 * Title: Last Digit
 * URL: http://online-judge.uva.es/p/v101/10162.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Para implementar la solución se utiliza la propiedad de que 
   la solución de cualquier n es igual a la solucion de n % 100.
**/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int m[100];

void init(){
   m[0] = 0;
   
   for(int n = 1; n < 100; n++){
   	int res = n;
	   for(int i = 1; i < n; i++){
	   	res = (res*n) % 10 ;
	   }
	   m[n] = (m[n-1] + res) % 10;
	}
}

int main(){
   init();
   string in;
   
   cin >> in;
   
   while(in != "0"){
      if(in.size() > 2){
         in = in.substr(in.size()-2, in.size());
      }
      int value = atoi(in.c_str());
      
      cout << m[value] << endl;
      
      cin >> in;
   }
}

