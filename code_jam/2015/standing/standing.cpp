#include <iostream>
#include <vector>

using namespace std;

int main() {
   unsigned cases, smax, sum, needed;
   string actual;

   cin >> cases;

   for (unsigned i = 0; i<cases; i++) {
      cin >> smax >> actual;

      sum = 0;
      needed = 0;

      for (unsigned j=0; j<=smax; j++) {
         unsigned aa = actual[j] - '0';
         if (sum < j) {
            needed += (j-sum);
            sum += (j-sum) + aa;
         }
         else {
            sum += aa;
         }
      }
      cout << "Case #" << i+1 << ": " << needed << endl;
   }
   

   return 0;
}
