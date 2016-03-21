#include <iostream>

using namespace std;

long long f(int n) {
	if (n < 2) return 1;
	return n*f(--n);
}


int main() {
	int m, n;
	while(cin >> m >> n) {
		long long mf = f(m), nf = f(n);
		cout << mf + nf << endl;
	}
	
	return 0;
}
