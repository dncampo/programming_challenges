/** 
 * Title: Problem E: Problem C: Longest Common Subsequence
 * URL: http://uva.onlinejudge.org/external/104/10405.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se usa programación dinámica (DP) con el algoritmo de la mayor subsecuencia común (LCS)
**/

#include <iostream>
#include <vector>

using namespace std;


int lcs(string first_word, string second_word, vector<vector<int> >& pm) {
	//build the increasing subsequences table (DP)
	for (int i = first_word.size(); i >= 0; i--)
		for (int j = second_word.size(); j >= 0; j--) {
		
			// formula that decides the LCS
			if (i == (int)first_word.size() || j == (int)second_word.size()) pm[i][j] = 0;
			else if (first_word[i] == second_word[j]) pm[i][j] = 1 + pm[i+1][j+1];
			else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);		
		}
	return pm[0][0];
}

int main() {
	string w1,w2;
	char c;

	while(true){
		while(1){
			if(c == 0) return 0;
			scanf("%c",&c);
			cout << c << endl;
			if ('\n' == c) break;
			else w1.push_back(c);
		}
		while(1){
			scanf("%c",&c);
			if ('\n' == c) break;
			else w2.push_back(c);
		}
		
		if((w1 == w2) && w1 == "") continue;
		
		// build the array that stores the computed values, avoiding recalculate (DP)
		vector<vector<int> > prefix_matrix(w1.size() + 1);
		for(unsigned i = 0; i < w1.size() + 1; i++){
			vector<int> tmp(w2.size() + 1, 0);
			prefix_matrix[i] = tmp;
		}
		cout << lcs(w1, w2, prefix_matrix) << endl;
	}
	return 0;
}


