#include <iostream>

using namespace std;

int main(){
   unsigned ncases;
   const string G = "GABRIEL";
   const string R = "RICHARD";

   cin >> ncases;

   for (unsigned i=0; i<ncases; i++) {
      unsigned x, r, c;
      string win;

      cin >> x >> r >> c;

      if (1 == x) {
         win = G;
      }
      else if (7 <= x) {
         win = R;
      }
      else {
         if (((r >= x && c >= (x-1)) || (r >= (x-1) && c >= x)) \
               && (0 == (r*c)%x)) {
            win = G;
         }
         else {
            win = R;
         }
      }
      cout << "Case #" << i+1 << ": " << win << endl;
   }
   return 0;
}

