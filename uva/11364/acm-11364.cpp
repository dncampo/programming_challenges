/*
Title: Optimal Parking
Tags: adhoc, sorting
URL: https://uva.onlinejudge.org/external/113/p11364.pdf
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Notes:
    + The input is sorted and the succesive differences of each one are performed
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n_cases;
	cin >> n_cases;

	for (unsigned i = 0; i < n_cases; i++){
		unsigned n;
		cin >> n;
		vector<unsigned> data(n);

		for (unsigned j = 0; j < n; j++) cin >> data[j];

		sort (data.begin(), data.end());
		unsigned sum = 0;
		for (unsigned k = 1; k < n; k++) sum += data[k] - data[k - 1];
		sum += data[n - 1] - data[0];
		cout << sum << endl;

	}
	return 0;
}

