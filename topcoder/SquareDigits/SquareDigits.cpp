#include <iostream>
#include <set>

using namespace std;

class SquareDigits {

	public:
	   unsigned sq (unsigned n) {
	      unsigned sum = 0;
	      while (n > 9) {
            unsigned m = n % 10;
            n /= 10;
            sum += m * m;
         }
         sum += n * n;
         return sum;
	   }
	
		int smallestResult (const int d) {

         for (unsigned i = 0 ;; i++) {

   			set<unsigned> conj;
            unsigned sq_n = i;
			   while (1) {
               sq_n = sq (sq_n);
				   if (sq_n == (unsigned)d) return i;
				   				   
				   if (conj.end() != conj.find (sq_n))  break;  //begin a cycle

				   conj.insert (sq_n);

			   }

		   }
			
			return 0;
		}
};

int main () {
   SquareDigits s;
   for (unsigned i = 1; i < 177; i++)
      cout << i << ": " << s.smallestResult (i) << endl;
   return 0;
}

