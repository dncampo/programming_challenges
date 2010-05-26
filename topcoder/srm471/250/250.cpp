#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

#define SIZE 1000002
             
using namespace std;

char list[SIZE];

void criba(int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   list[1] = list[0] = 0;
   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
}


class PrimeContainers {
public:
   
   int containerSize(int N) {
      criba(1000000);
      

      int res = list[N];
      int pow = 1;
      while (pow <= (N >> 1) + 1) {
         pow <<= 1;
         if (list[N / pow]) res++;   
      }
      return res;
   }
};





int main () {

   PrimeContainers tmp;

   cout << tmp.containerSize(959) << endl;

   return 0;
}

