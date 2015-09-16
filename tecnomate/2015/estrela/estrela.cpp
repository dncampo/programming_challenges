#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <cstring>

#define SIZE 2147483646
             
using namespace std;


//char list[SIZE/2+1];

void criba(int limit, const set<int>& fac){
   
   char list[limit];	
   memset(list, 1, sizeof(list));

   int d_limit = (int) (sqrt(limit));

   for(int i=2; i<=d_limit; i++){
      if(list[i]){
		 set<int>::iterator it=fac.begin(); 
		 for (; (*it)*i <= limit; it++){
         //for(int j=2; j*i<=limit; j++){
            list[(*it)*i] = 0;
         }
      }
   }
   for (int k=1; k<limit; k++){
	   if(list){
		   cout << list[k];
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


vector<int> factors(int n) {
	vector<int> pf;
	//vector <int> pf;
    // Print the number of 2s that divide n
    while (n%2 == 0){
		pf.push_back(2);
        //printf("%d ", 2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2){
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
			pf.push_back(i);
            //printf("%d ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {
		pf.push_back(n);
        //printf ("%d ", n);
	}
	
	return pf;
}

int estrelas_prime(int n) {
	if (2==n) return 1;
	return (n-1)/2;
}


int main() {
	int N; 
	
	while(cin >> N) {
		unsigned ss = 1;
		if (is_prime(N)) {//prime
			ss = estrelas_prime(N);
		}
		else {
			vector<int> facs = factors(N);
			map<int, int> facs2;
			for (unsigned i=0; i<facs.size(); i++) {				
				facs2[facs[i]]++;
			}
			map<int,int>::iterator it=facs2.begin();
			map<int,int>::iterator itend=facs2.end();
			for (; it!=itend; it++) {
//cout << "facs2: " << it->first << " - " << it->second << endl;				
//cout << estrelas_prime(it->first) * pow(it->first, it->second - 1) << endl;					
				if (2 != it->first) {
					ss *= estrelas_prime(it->first) * pow(it->first, it->second - 1);
					
				}
			}
			int mapsize = facs2.size();
			if (facs2[2] != 0) {
				if (1==mapsize) {//power of 2 only
					ss = pow(2,facs2[2] - 2);
				}
				else {
					ss *= pow(2,facs2[2]);
				}
			}
			else {
//cout << "ss *= pow(2,facs2.size() - 1): " << mapsize << endl;								
//cout << "ss: " << ss << " * " << pow(2,mapsize - 1) << endl;
				ss *= pow(2,mapsize - 1);				
			}
		}
		cout << ss << endl;	
	}
    return 0;
}

