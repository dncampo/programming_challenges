/** 
 * Title: Problem E: Vacation
 * URL: http://uva.onlinejudge.org/external/101/10192.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se usa programación dinámica (DP) con el algoritmos de la mayor subsecuencia común (LCS)
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
	unsigned cnt = 1;
	
	while(1){
		getline(cin, w1); //use getline instead of raw cin, for the ' ' (space) character
		if('#' == w1[0]) return 0;

		getline(cin, w2);
		
		// build the array that stores the computed values, avoiding recalculate (DP)
		vector<vector<int> > prefix_matrix(w1.size() + 1);
		for(unsigned i = 0; i < w1.size() + 1; i++){
			vector<int> tmp(w2.size() + 1, 0);
			prefix_matrix[i] = tmp;
		}

		unsigned res = lcs(w1, w2, prefix_matrix);
		cout << "Case #"<< cnt++ << ": you can visit at most "<< res << " cities." << endl; 
		
	}
	return 0;
}


