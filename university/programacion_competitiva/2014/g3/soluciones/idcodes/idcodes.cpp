#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long a = 0ULL;

int main () {
   string line;
   while (cin >> line) {
      if ("#" == line) return 0;
      
      if (next_permutation(line.begin(), line.end())) {
         cout << line << '\n';
      }
      else {
         cout << "No Successor\n";
      }
   
   }
   return 0;
}
