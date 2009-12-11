/**
 * Title: Perfect Cubes 
 * URL: http://uva.onlinejudge.org/external/3/386.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Simplemente se calcula la ecuacion:
      a^3 = b^3+c^3+d^3 
   y para optimizar un poco se utiliza un vector de los cubos precalculados  
**/
#include<iostream>
#include<vector>
using namespace std;

vector<int> cubes(201);

int main(){
   for(int i = 0; i <= 200; i++){
      cubes[i] = i*i*i;
   }
   
   for(int a = 1; a <= 200; a++){
      for(int b = 2; b < 200; b++){
         for(int c = b+1; c < 200; c++){
            for(int d = c+1; d < 200; d++){
               if(cubes[a] == (cubes[b]+cubes[c]+cubes[d])){
                  cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d <<")" << endl;
                  if(a < d) a = d+1;
               }
            }
         }
      }
   }
   return 0;
}
