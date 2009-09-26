/** 
 * Title: History Grading
 * URL: http://uva.onlinejudge.org/external/1/111.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se usa programación dinámica (DP) con el algoritmos de la mayor subsecuencia común (LCS)
**/

#include <iostream>
#include <vector>

using namespace std;


int lcs(const vector<int> first_word, vector<int> second_word, vector<vector<int> >& pm) {
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
	int events, tmp;
	cin >> events;
//cout << "events: " << events << endl;
	vector<int> correct(events);
	for(int i = 0; i < events; i++){
		cin >> tmp;
		correct[i] = tmp;
//cout << tmp << " ";
	}
//cout << endl;
	
	while(cin >> tmp){
		vector<int> student(events);
		student[0] = tmp;

		for(int j = 1; j < events; j++){
			cin >> tmp;
			student[j] = tmp;
//cout << tmp << " ";
		}
//cout << endl;		
		// build the array that stores the computed values, avoiding recalculate (DP)
		vector<vector<int> > prefix_matrix(correct.size() + 1);
		for(unsigned k = 0; k < correct.size() + 1; k++){
			vector<int> tmp(student.size() + 1, 0);
			prefix_matrix[k] = tmp;
		}

		unsigned res = lcs(correct, student, prefix_matrix);
		cout << res << endl;
	}
	return 0;
}


