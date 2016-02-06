http://www.spoj.com/problems/FASTPOW/

#include <iostream>

using namespace std;

int main(){
   unsigned A, B, C;
   cin >> A >> B >> C;
   
   unsigned long long b=1,c=A,k=B;
   unsigned long long MOD = 294967295ULL;
   
   while (k>0) {
      
      if (k%2) {
         k--;
         b = b * c;      
     
      } 
      else {
         k = k >> 1;
         c = c*c;          
      }
cout << b << endl;      
      b = b % MOD;      
      c = c % MOD;
   }
   
   cout << b%C << endl;
   return 0;   
}
