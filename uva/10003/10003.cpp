#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int size, const vector<int>& cuts, int i, int j){
	if ( i == j ){
      return size; // caso base
	}

	
	const int mid = size / 2;
	int diff = 1000, pos, tmp;
	for(unsigned a = 0; a < cuts.size(); a++){
	cout << a << endl;
		tmp = abs(mid - cuts[a]);
		if (tmp < diff) {
			diff = tmp;
			pos = a;
		}
	}
	return size + solve(cuts[pos], cuts, i, pos-1) + solve(size - cuts[pos], cuts, pos + 1, j);
	
}


int main(int argc, char *argv[]){
	while(1){
		int size, n_cuts;
		cin >> size;
		if (0 == size) {
			return 0;    
		}
		cin >> n_cuts;
		vector<int> cuts(n_cuts);
		for(int i = 0; i < n_cuts; i++){
			int tmp;
			cin >> tmp;
			cuts[i] = tmp;
		}
		sort(cuts.begin(), cuts.end());
		cout << "The minimum cutting is " << solve(size, cuts, 0, cuts.size() - 1) << "." << endl ;
	}
  	getchar();
	return 0;
}
