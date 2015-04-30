#include <iostream>
#include <map>

using namespace std;

int main() {
	unsigned n_cases, m, a, b;

	
	cin >> n_cases;
	
	for (unsigned i=0; i<n_cases; i++) {
		if (i>0) cout << endl;
		
		multimap<float, unsigned> sorted;
		
		cin >> m;
		for (unsigned j=1; j<=m; j++) {
			cin >> a >> b;
			float temp = b/(float)a;
			sorted.insert(make_pair<float, unsigned>(-temp, j));
		}
		
		multimap<float, unsigned>::iterator it = sorted.begin();
		for (; it != sorted.end(); it++) {
			cout << it->second << " ";
		}
		cout << endl;
	}
}
