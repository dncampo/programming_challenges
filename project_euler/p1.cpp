#include <iostream>

using namespace std;

unsigned const MAX_F = 32;

unsigned fib[MAX_F];

int main(){

   fib[1] = 1;
   fib[2] = 2;
      
   unsigned sum = 3;   
   
   for(int i = 3; i <= MAX_F; i++){
      fib[i] = fib[i - 1] + fib[i - 2];   
      
      sum += fib[i];
      
//      cout << i << ": " << fib[i] << endl;
//      if (fib[i] > 4000000) break;
   }
   cout << sum << endl;

}
