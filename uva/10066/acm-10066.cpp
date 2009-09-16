/** 
 * Title: The Twin Towers
 * URL: http://uva.onlinejudge.org/external/100/10066.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Al igual que en el problema acm-00531 "Compromise" se usa la mayor subsecuencia común (LCS)
**/

#include <iostream>
#include <vector>

using namespace std;


int lcs(vector<int> first_tower, vector<int> second_tower, vector<vector<int> >& pm) {
	//build the increasing subsequences table (DP)
	for (int i = first_tower.size(); i >= 0; i--)
		for (int j = second_tower.size(); j >= 0; j--) {
		
			// formula that decides the LCS
			if (i == (int)first_tower.size() || j == (int)second_tower.size()) pm[i][j] = 0;
			else if (first_tower[i] == second_tower[j]) pm[i][j] = 1 + pm[i+1][j+1];
			else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);		
		}
	return pm[0][0];
}

int main() {
	int t1, t2, tmp, cnt = 1;
	
	while(cin >> t1 >> t2){
		if(0 == t1 && 0 == t2 ) return 0;
		
		vector<int> first_tower(t1);
		for(int a = 0; a < t1; a++){
			cin >> tmp;
			first_tower[a] = tmp;
		}

		vector<int> second_tower(t2);
		for(int b = 0; b < t2; b++){
			cin >> tmp;
			second_tower[b] = tmp;
		}
	
		// build the array that stores the computed values, avoiding recalculate (DP)
		vector<vector<int> > prefix_matrix(first_tower.size() + 1);
		for(unsigned i = 0; i < first_tower.size() + 1; i++){
			vector<int> tmp(second_tower.size() + 1, 0);
			prefix_matrix[i] = tmp;
		}	
		cout << "Twin Towers #" << cnt++ << endl;
		cout << "Number of Tiles : " << lcs(first_tower, second_tower, prefix_matrix) << endl; 
		cout << endl;
	}
	return 0;
}


