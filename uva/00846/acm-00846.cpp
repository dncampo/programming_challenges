/**
 * Title: Steps
 * URL: http://uva.onlinejudge.org/external/8/846.html
 * Resources of interest:
 * Solver group: Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Para cada entrada x,y se define diff = y-x
    + para cada valor de diff se define lo siguiente:
    diff,steps
    0,0
    1,1
    2,2
    3,3
    4,3
    5,4
    6,4
    7,5
    8,5
    9,5
    10,6
    11,6
    12,6
    13,7
    14,7
    15,7
    16,7
    ...
    etc
    +Ahora agrupando por el valor steps tenemos:
    steps, valur mayot de diff
    0,0
    1,1
    2,2
    3,4
    4,6
    5,9
    6,12
    +Cada par de valores del inciso anterior se calcula en un arreglo (list)
    +Finalmente para cada entrada se busca el mayor indice i(staps) que sea menor que diff en el arreglo y se lo imprime
**/

#include <iostream>
using namespace std;
#define MAX 93000

unsigned list[MAX];

int solve(int x, int y){
   int diff = y-x;
   int index = -1;

   while(list[++index] < diff);
   
   return index;
}

void init(){
   bool temp = true;
   
   for(int i = 0, counter = 0, ds = 0; i < MAX; i++){
      counter += ds;       

      list[i] = counter;

      if(temp){
         temp = false;
         ++ds;
      } else {
         temp = true;
      }
   }
}

int main(){
   init();
   int cases, x, y;
   
   cin >> cases;
   
   for(int i = 0; i < cases; i++){
      cin >> x >> y;
      
      cout << solve(x, y) << endl;
   }

   return 0;
}
