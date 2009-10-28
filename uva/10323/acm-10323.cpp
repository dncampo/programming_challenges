#include <iostream>

#define MIN_FAC 8
#define MAX_FAC 13

using namespace std;

unsigned long long facts[MAX_FAC];


int main(){
   
   facts[0] = 1;
   for(unsigned a = 1; a <= MAX_FAC; a++)
      facts[a] = facts[a - 1] * a;

   unsigned n;
   while (cin >> n){
      if (n < MIN_FAC) cout << "Underflow!" << endl;
      else if (n > MAX_FAC) cout << "Overflow!" << endl;
      else cout << facts[n] << endl;   
   }

   return 0;	
}
