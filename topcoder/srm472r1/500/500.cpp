#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <sstream>


using namespace std;

int pow4[16];

class PotatoGame {
public:
   string theWinner(int n) {
      pow4[0] = 1;
      for (int i = 1; i < 16; i++) {
         pow4[i] = pow4[i-1] << 2;
      }
      
      bool r = false;
      
      while (1) {
         unsigned i = 0;
         for (; i < 16; i++) {
            if (n < pow4[i]) break;
         }
         n -= pow4[i - 1];
         if (n == 0) {
            if (r) return "Hanako";
            return "Taro";
         }
         else r = !r;
      }
   }
};

int main () {

   PotatoGame tmp;


   return 0;
}

