#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>



using namespace std;

int main () {
	int T, N, B, sum, res, temp;
	
	cin >> T;
	
	for (unsigned i=0; i<T; i++){
		cin >> B >> N;
		sum = 0;
				
		multimap<unsigned, unsigned> barbers;
		for (unsigned j=0; j<B; j++){
			cin >> temp;
			barbers.insert(pair<unsigned, unsigned>(temp, j+1));
			//sum += barbers[j];
		}
		
		if (N <= B) {
			cout << "Case #" << i+1 << ": " << N << endl;
			continue;
		}		
		
		vector<float> table(B);
		
		unsigned maxe = (max_element(barbers.begin(), barbers.end()))->second;
		int h=0;
		for (multimap<unsigned, unsigned>::iterator it = barbers.begin(); it != barbers.end(); it++, h++) {
		//unsigned h=0; h<B; h++){
			table[h] = ((float)maxe / it->second);
		}
		unsigned summ = accumulate(table.begin(), table.end(), 0);
		res = N % summ;
		
		//sort(barbers.begin(), barbers.end());
			
		multimap<unsigned, unsigned>::iterator it = barbers.begin();	
		while (res > 0) {
			res -= it->first;
		}
		
		//if (res == 0) res = B;
		
		cout << "Case #" << i+1 << ": " << it->second << endl;
	}
	return 0;
}

