#include <iostream>
using namespace std;

int solve(int b, int p, int mod){
   int R =  b;

   if(p > 1){
      int x = solve(b, p/2, mod);
      int y = solve(b, p/2, mod);
      if(p & 1){
         return (((x * y) % mod ) * b) % mod;
      } else{
         return (x * y) % mod;
      } 
   }
   
   return p == 0? 1 :  b; 
}

int main(){
   int B, P, M;   
   
   while(cin >> B >> P >> M){
      cout << solve(B % M, P, M) << endl;
   }
   return 0;
}
