#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	unsigned n_cases;

	cin >> n_cases;
	for (unsigned i = 0; i < n_cases; i++) {
		string a, b;
		multiset<char> sa, sb;
	
		cin >> a >> b;

		if (a.size() != b.size()) 
			cout << "NO" << endl;

		else {
			for (unsigned j = 0; j < a.size(); j++) {
				sa.insert(a[j]);
				sb.insert(b[j]);
			}
			if (sa == sb)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
