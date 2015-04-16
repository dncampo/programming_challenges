#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool mycomp (char a, char b){
	char A = toupper(a);
	char B = toupper(b);
	return (A==B ? a < b: A<B);
}

int main() {
   unsigned ncases;
   string str;

   cin >> ncases;
   for (unsigned i=0; i<ncases; i++) {
      cin >> str;

      sort(str.begin(), str.end(), mycomp);
      do {
         cout << str << endl;
      } while (next_permutation(str.begin(), str.end(), mycomp));
   }
   return 0;
}
