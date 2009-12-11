/**
 * Title: Humble Numbers
 * URL: http://uva.onlinejudge.org/external/4/443.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Se utiliza una un vector en donde se va calcuando los humble numbers.
   luego se imprime la solucion como indica el enunciado.
   Para mayor detalle de la estrategia de implementacion ver el problema Hugly Numbers.
**/

#include <iostream>
#include <string>
using namespace std;
#define MAX 5843

int min(int a, int b, int c, int d){
   return min(min(a, b), min(c, d));
}

string get_nth(int n){
   if((n%100) > 3 && (n%100) < 21)
      return "th";
      
   int res = n- 10*(n/10);
   if(res == 1)
      return "st";
   else if(res == 2)
      return "nd";
   else if(res == 3)
      return "rd";

   return "th";
}

int main(){
   int humble[MAX], dos = 1, tres = 1, cinco = 1, siete = 1;
   humble[1] = 1;
   
   for(int i = 2; i < MAX; i++){
      humble[i] = min(humble[dos]*2, humble[tres]*3, humble[cinco]*5, humble[siete]*7);
      
      if(humble[i] == humble[dos]*2){
         dos++;
      }
      if(humble[i] == humble[tres]*3){
         tres++;
      }
      if(humble[i] == humble[cinco]*5){
         cinco++;
      }            
      if(humble[i] == humble[siete]*7){
         siete++;
      }
   }
   
   int n;
   cin >> n;   
   
   while (n != 0){
      cout << "The "<< n<< get_nth(n)<< " humble number is " << humble[n]<< "." << endl;
      cin >> n;   
   }
   return 0;
}
