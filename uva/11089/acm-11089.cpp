/**
 * Title: Fi-binary Number
 * URL: http://online-judge.uva.es/p/v110/11089.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    + Las distintas salidas siguen un patron determinado mediante una funcion recursiva.
**/
#include<iostream>
#define MAX 45

using namespace std;

int fib[MAX];

int prev_fib(int n){
   int i = 1;
   for(; n >= fib[i]; i++);
   
   return --i;
}

void solve(string& str, int n){
   if(n == 1){
      str = "1";
   } else if(n == 2){
      str = "10";
   } else{
      int i_prev = prev_fib(n);
      int delta = n - fib[i_prev];
      
      if(delta < fib[i_prev - 2]){
         solve(str, fib[i_prev - 1] + delta);
         str.erase(0, 1);
      } else{
         delta = n - fib[i_prev] - fib[i_prev - 2] + 1;
         solve(str, fib[i_prev - 2] + delta - 1);
      }
      
      str.insert(0, "10");
   }
}

int main(){
   fib[1] = 1;
   fib[2] = 2;
   for(int i=3; i<MAX; i++){
      fib[i] = fib[i-1] + fib[i-2];
   }

   int t, n;
   cin >> t;
   
   for(int i=0; i<t; i++){
      cin >> n;
      
      string output;
      solve(output, n);
      
      cout << output << '\n';
   }

   return 0;
}
