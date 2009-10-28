#include <iostream>

#define NUM 13195
#define ROOT 115

using namespace std;

unsigned const MAX_F = 32;

unsigned fib[MAX_F];

int main(){

   fib[1] = 1;
   fib[2] = 2;
      
   unsigned sum = 2;   
   
   for(int i = 3; i <= MAX_F; i++){
      fib[i] = fib[i - 1] + fib[i - 2];   
      
      if(!(fib[i] & 1))
	      sum += fib[i];
      

//      cout << i << ": " << fib[i] << endl;
//      if (fib[i] > 4000000) break;
   }
   cout << sum << endl;

}
