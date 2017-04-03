#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a, aa, b;
	
	scanf("%d", &a);
	
	for (int i=0; i<a; i++) {
		scanf("%d", &aa);
		vector<int> v(aa);
		for (int j=0; j<aa; j++) {
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end());
		
		int j=0;
		for (; j<aa-1; j++) {
			printf("%d ", v[j]);
		}
		printf("%d\n",v[j]);
	}

	return 0;
}
