http://www.spoj.com/problems/FACTCG2/

#include <cstdio>
#include <vector>


using namespace std;

void computeSieve(vector<int> &sieveTable){
	int sz = sieveTable.size();
	for(int i = 2; i*i < sz; i++){
		if(sieveTable[i] == 0){
			for(int j = i*i; j < sz; j += i){
				if(sieveTable[j] == 0) sieveTable[j] = i;
			}
		}
	}
}



int main(){
	int n;
	vector<int> sieveTable(10000007, 0);
	computeSieve(sieveTable);

	while (scanf("%u", &n) > 0) {
		if(n == 1){
			printf("1\n");
			break;
		}
		else{
			printf("1");
			while(sieveTable[n] != 0 && n % sieveTable[n] == 0){
				printf(" x %d", sieveTable[n]);
				if(sieveTable[n]==0)	break;
				n /= sieveTable[n];
			}   
			printf(" x %d\n", n);      
		}
	}
	return 0;
}
