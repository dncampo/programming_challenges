#include <iostream>

using namespace std;


int main() {
	int m, n;
	while(cin >> m >> n) {
		if (0==m && 0==n) return 0;
		int op=0 , c=0;
		while (n || m) {
			c = (c + (n%10) + (m%10)) / 10;
			op += c;
			n /= 10, m /= 10;
		}
		if (!op) cout << "No carry operation.\n";
		else if (op >1) cout << op << " carry operations.\n";
		else cout << op << " carry operation.\n";
	}
	
	return 0;
}
