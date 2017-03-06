#include <cstdio>
#include <cmath>
#include <cstring>

#define SIZE 3200000
             
using namespace std;

char list[SIZE];

void criba(int limit){
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
         for(int j=2; j*i<=limit; j++){
            list[j*i] = 0;
         }
      }
   }
}


bool is_prime(int n){
   if(n < 2 ) return false;
   
   for (int i = 2; i < (int)sqrt(n) + 1; i++){
      if (n % i == 0) 
         return false;
   }
   return true;
}

int main() {
	long long input;
	  
	criba(SIZE-1);
	 
	//cin >> input;	
	scanf("%lld", &input);
	for (long long i=2; i*i <= input; i++) {
		if(list[i]) { //isprime
			if (0==(input % i)) {				
				//cout << i << endl;
				printf("%lld\n", i);
			}
		}
	}
	if (list[(unsigned)input] && input != 1) {
		printf("%lld\n", input);
	}
	
    return 0;
}
