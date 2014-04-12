#include <iostream>
#include <vector>

using namespace std;

int main () {
	unsigned n_cases, row, tmp1, tmp2, tmp3, tmp4;
	
	cin >> n_cases;	
	
	for (unsigned t=0; t<n_cases; t++) {		
		cin >> row;
		
		vector<bool> cards(16, false);
		vector<unsigned> candidates;
		for (unsigned i=1; i<5; i++) {	
			if (i==row) {
				cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
				cards[tmp1] = true;
				cards[tmp2] = true;
				cards[tmp3] = true;
				cards[tmp4] = true;
			}
			else {
				cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
			}
		}
		cin >> row;
		for (unsigned i=1; i<5; i++) {	
			if (i==row) {
				cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
				if (cards[tmp1]){
					candidates.push_back(tmp1);
				}
				if (cards[tmp2]){
					candidates.push_back(tmp2);
				}
				if (cards[tmp3]){
					candidates.push_back(tmp3);
				}
				if (cards[tmp4]){
					candidates.push_back(tmp4);
				}				
			}
			else {
				cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
			}
		}
		cout << "Case #" << t+1 << ": ";
		
		if (candidates.size() > 1) {
			cout << "Bad magician!" << endl;
		}
		else if (candidates.empty()) {
 			cout << "Volunteer cheated!" << endl;
		}
		else {
			cout << candidates[0] << endl;
		}
	}
	return 0;
}
