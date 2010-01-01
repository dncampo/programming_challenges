//#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

int main() {
   unsigned N, D, W;

   while (~scanf("%u %u", &N, &D)) {
      if (0 == N && 0 == D) return 0;

      list<unsigned> l;
      unsigned l_size = 0; //tam de la lista, dado que el método size PUEDE llegar a ser O(N)
      for (unsigned i = 1; i <= N; i++) {
         l.push_back(i);
         l_size++;
      }

      list<unsigned>::iterator it = l.begin();
      list<unsigned>::iterator er;

      unsigned i = 1;
      while (l_size > 1) {
         i %= l_size;
         for (; i < D; i++) {
            if (it == l.end()) {
               it = l.begin();
            }
            else {
               it++;
            }
         }
         if (it == l.end()) it = l.begin();
         er = it++;
         i++;
//cout << "eliminating: " << *er << endl;
         l.erase(er);
         l_size--;
      }
      if (it == l.end()) it = l.begin();
      printf("%u %u %u\n", N, D, *it);
   }

   return 0;
}
