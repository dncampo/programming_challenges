/** 
 * Title: Compromise
 * URL: http://uva.onlinejudge.org/external/5/531.html
 * Resources of interest:
 * Solver group: David - Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se cargan las palabras de cada texto (strings) en un par de vector<string>.
   + Luego se aplica el algoritmo de LCS (Longest Common Subsequence), tomando cada palabra
   de cada vector como si fueran cada una de las letras pertenecientes a una cadena de caracteres.	
**/

#include <iostream>
#include <vector>

using namespace std;


void lcs(vector<string> first_text, vector<string> second_text, vector<vector<int> >& pm) {
	//build the increasing subsequences table (DP)
	for (int i = first_text.size(); i >= 0; i--)
		for (int j = second_text.size(); j >= 0; j--) {
		
			// formula that decides the LCS
			if (i == (int)first_text.size() || j == (int)second_text.size()) pm[i][j] = 0;
			else if (first_text[i] == second_text[j]) pm[i][j] = 1 + pm[i+1][j+1];
			else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);		
		}
}


void print_lcs(vector<string> first_text, vector<string> second_text, vector<vector<int> >& pm){
	int i = 0, j = 0, m = first_text.size(), n = second_text.size();

	// no blank space after the result, if not PE
	bool first_print = true;

	while (i < m && j < n){
		if (first_text[i] == second_text[j]){

			if(first_print)
				cout << first_text[i], first_print = false;
			else
				cout << " " << first_text[i];
				
			i++; j++;
		}
		
		else if (pm[i+1][j] >= pm[i][j+1]) i++;
		else j++;
	}
	cout << endl;
}


int main() {
	string word;
	
	while(cin >> word){ //there are another case?
		vector<string> first_text(0);
		while(1){
			if ("#" == word) break; // 1st text loaded...
			first_text.push_back(word);
			cin >> word;
		}

		vector<string> second_text(0);
		while(1){
			cin >> word;
			if ("#" == word) break; //2nd txt loaded...
			second_text.push_back(word);
		}
	
		// build the array that stores the computed values, avoiding recalculate (DP)
		vector<vector<int> > prefix_matrix(first_text.size() + 1);
		for(unsigned i = 0; i < first_text.size() + 1; i++){
			vector<int> tmp(second_text.size() + 1, 0);
			prefix_matrix[i] = tmp;
		}	
	
		lcs(first_text, second_text, prefix_matrix); 
		print_lcs(first_text, second_text, prefix_matrix);
	}
	return 0;
}


