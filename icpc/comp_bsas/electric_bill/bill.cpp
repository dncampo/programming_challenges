#include <iostream>

using namespace std;

unsigned get_accum(int A){
   unsigned ret = 0;
   if (A - 200 >= 0) {
      ret += 100;
      A -= 200;

      if (A - 30000 >= 0) {
         ret += 10000;
         A -= 30000;

         if (A - 5000000 >= 0) {
            ret += 1000000;
            A -= 5000000;

            ret += A / 7;
         }
         else {
            ret += A / 5;
         }
      }
      else {
         ret += A / 3;
      }
   }
   else {
      ret += A >> 1;
   }
   return ret;
}

unsigned get_exp (int A){
   unsigned ret = 0;
   if (A - 100 >= 0) {
      ret += 200;
      A -= 100;

      if (A - 10000 >= 0) {
         ret += 30000;
         A -= 10000;

         if (A - 1000000 >= 0) {
            ret += 5000000;
            A -= 1000000;

            ret += A * 7;
         }
         else {
            ret += A * 5;
         }
      }
      else {
         ret += A * 3;
      }
   }
   else {
      ret += A << 1;
   }
   return ret;


}

unsigned get_my_expenses (unsigned accum, unsigned B) {
   for (unsigned i = 0; i <= (accum >> 1) ; i++) {
      unsigned my_ex = get_exp(i);
      unsigned nei_ex = get_exp(accum - i);
      if (B == nei_ex - my_ex) {
         return i;
      }

   }
   return 0;
}


int main() {
   unsigned A, B;
   while (cin >> A >> B) {
      if (0 == A && 0 == B) return 0;

      unsigned accum = get_accum(A);
      unsigned my_ex = get_my_expenses(accum, B);
      cout << get_exp(my_ex) << endl;
   }
   return 0;
}
