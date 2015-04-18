#include <iostream>
#include <vector>

using namespace std;

int main () {
	unsigned ncases, N;
	int temp;
	cin >> ncases;
	
	for (unsigned i=0; i<ncases; i++) {
		cin >> N;
		
		vector<unsigned> ms (N);
		for (unsigned j=0; j<N; j++) {
			cin >> ms[j];
		}
		
		int max_first = ms[1]-ms[0], max_second = 0;
		
		for (unsigned j=1; j<N; j++) {
			temp = ms[j-1] - ms[j];
			if (temp > 0) {
				max_second = max(max_second, temp);				
			}
		}		
		
		unsigned tot_first=0, tot_second=0;
		
		int diff;
		tot_second = ms[0] > max_second ? max_second : ms[0];
		for (unsigned j=1; j<N; j++) {
			//second method
			diff = ms[j-1] - ms[j];
			if (diff > 0) {//had eaten
				tot_first += diff;
			}
			
			if (j < N-1)
				tot_second += ms[j] > max_second ? max_second : ms[j];

		}
		
		cout << "Case #" << i+1 << ": " << tot_first << " " << tot_second << endl;
		
	}
	
	return 0;
}
