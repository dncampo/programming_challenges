#include <iostream>

using namespace std;

int main () {
	unsigned ncases, N;
	int temp;
	cin >> ncases;
	
	for (unsigned i=0; i<ncases; i++) {
		cin >> N;
		
		for (unsigned j=0; j<N; j++) {
			cin >> ms[j];
		}
		
		

		cout << "Case #" << i+1 << ": " << tot_first << " " << tot_second << endl;
		
	}
	
	return 0;
}
