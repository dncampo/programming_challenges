#include <cstdio>
#include <cstring>
#include <cmath>

#define SIZE 100001


using namespace std;

char list[SIZE];

void criba(int L,int U){
   int d = U-L+1;
   int d_limit = (int) (sqrt(U));
	
   memset(list, 1, sizeof (char [d]));

   for(int i = (L % 2 == 1); i < d; i += 2){
      list[i] = 0;
   }

   for(int i = 3; i <= d_limit; i += 2){
      if (i > L && !list[i-L]) continue;

      int j = L/i*i;
    
      if (j < L) j += i;
      if (j == i) j += i;
      j-=L; 
      for (; j < d; j += i) 
         list[j]=0;
   }
  
   if (L <= 1) list[1-L] = 0;
   if (L <= 2) list[2-L] = 1;
  
  for (int i = 0; i < d;i++) 
	  if (list[i]) printf("%d\n", L+i);
	  //cout << (L+i) << "\n";
	
  printf("\n")	;
  //cout << endl;
}


int main () {
	unsigned n_cases, a, b;
	
	scanf("%u", &n_cases);
	
	for (unsigned i=0; i<n_cases; i++) {
		scanf("%u %u", &a, &b);
		criba(a, b);
	}
	

}
