/**
 * Title: Bee
 * URL: http://uva.onlinejudge.org/external/110/11000.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    + Inicializo un array con todos los valores posibles para cada 'n', siguiendo un patron
    + que cumple esta secuencia: a[n] = a[n-1] + fibonacci[n]
**/
#include<iostream>
#define MAX 500001

using namespace std;

unsigned long long total[MAX];
unsigned fib[MAX];

void init(){
   fib[1] = 1;
   fib[2] = 2;
   for(int i=3; i<MAX; i++){
      fib[i] = fib[i-1] + fib[i-2];
   }
   
   total[0] = 1;
   for(int i=1; i<MAX; i++){
      total[i] = total[i-1] + fib[i];
   }   
}

int main(){
   init();
   
   int n;
   
   cin >> n;
   while(n >= 0){
      if(n == 0)
         cout << "0 1" << endl;
      else
         cout << total[n-1] << " " << total[n] << endl;
      cin >> n;
   }
   
   return 0;
}
