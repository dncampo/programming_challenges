/**
 * Title: Longest Palindrome
 * URL: http://online-judge.uva.es/p/v111/11151.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza programacion dinamica para resolver el problema.
   la funcion que se utiliza es la seiguiente:
   longest(i, j) :
      1 si i = j
      longest(i+1, j-1)+2 si i != j y list[i] == list[j]
      max (longest(i, j-1), longest(i+1, j)) en otro caso
**/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1001
 
int solve(char list[]){
   int size = strlen(list);
   int m[size][size];

   memset(m, 0, sizeof(m));

   for(int i = 0; i < size; i++){
      for(int j = i, k = 0; j < size; j++, k++){
         if(k == j){
            m[k][j] = 1;
         } else if(list[k] == list[j]){
            m[k][j] = 2 + m[k+1][j-1];
         } else {
            m[k][j] = (m[k+1][j] > m[k][j-1]) ? m[k+1][j] : m[k][j-1];
         }
      }
   }
   return m[0][size-1];
}

int main(){
   int cases;
   char list[MAX];

   cin >> cases;
   cin.ignore();
   
   for(int i = 0; i < cases; i++){
      cin.getline(list, MAX);
      cout << solve(list) << endl;   
   }
   
   return 0;
}
