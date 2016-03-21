#include <cstdio>

using namespace std;

#define N 10001
int ps[N]={0};

double r;



int main() {
	for (int i=0, ii; ii=i*i, ii < N; i++) 
		ps[ii] = 1;
	
	int n;	
	while (scanf("%d", &n)!=EOF) {
		bool flag = true;
		for (int i=0; flag && i<=n>>1; i++) {
			if(ps[i] && ps[n-i]) {			
				printf("YES\n"); 
				flag=false;
				break;
			}
		}
		if (flag)
			printf("NO\n"); 	
		
	}
	return 0;
}
