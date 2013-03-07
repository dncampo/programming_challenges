#include <iostream>
#include <vector>

using namespace std;

int main () {
	unsigned n, m, c, seq, actual;
	
	while (cin >> n >> m >> c) {
		if (n+m+c == 0) return 0;
		
		vector <int> capacity(n+1);
		//vector <int> turned(n+1,0);
		
		int maxim = 0, consumed=0;
				
		for (unsigned i=1; i <= n; i++) cin >> capacity[i];
		for (unsigned i=1; i <= m; i++) {
			cin >> actual;
			consumed += capacity[actual];
			capacity[actual] *= -1;
			if (consumed > maxim) maxim = consumed;
		}

		cout << "Sequence " << ++seq << "\n";		
		
		if (maxim>c) {

			cout << "Fuse was blown.\n";
		}
		else {
			cout << "Fuse was not blown.\n" << "Maximal power consumption was " << maxim << " amperes.\n";
		}
		
		cout << "\n";
	}	
	return 0;
}
