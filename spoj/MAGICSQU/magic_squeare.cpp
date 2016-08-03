/*
Title: Magic Square!
Tags: Magic square, game, matrix, backtracking, brute force, pruning
URL: http://www.spoj.com/problems/MAGICSQU/
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + Given the partially filled matrix, it is populating accordingly using backtracking and pruning whenever is possible.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;



vector< vector<int> > data; //partial solution
vector<int> accum; //row accum
vector<int> used; //used nums

int magic_constant;
int n_case;
bool first_solution;


/*
 * Column verification.
 * Rows are always filled correctly with BT candidates.
 */
bool check_col (int size) {
	int sum = magic_constant;
	int i = 0;
	for (; sum == magic_constant && i < size; i++) {
		sum = 0;
		for (int j = 0; j < size; j++) {
			sum += data[j][i];
		}
	}
	return (i >= size);
}

/*
 * Check both diagonals
 */
bool check_diag (int size) {
	int t = 0;
	int tt = 0;
	for (int i = 0; i < size; i++) {
		t += data[i][i];
	}
	for (int i = 0, j = data.size() - 1; t==magic_constant && i < size; i++, j--) {
		tt += data[i][j];
	}

	return tt==magic_constant;
}

void process_solution(int size){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << data[i][j] << " ";
		}
		cout << "\n";
	}
		cout << "\n";
}

bool is_solution(int i, int j, int size){

	if (i>=size) {
		bool tt = check_col(size);
		bool ttt = check_diag (size);
		return ttt && tt;
	}
	return false;
}

void get_candidates(int i, int j, vector<int> &candidates, int size){

	/*
	 * If it is the last column, let's add the needed number to achieve the magical constant
	 */
	if (j == (int)data.size() - 1) {
		int diff = magic_constant - accum[i];
		if(0 < (diff) && !used[diff]) {
			candidates.push_back(diff);
			return;
		}
		else return;
	}

	/*
	* If it is not the las column, let's add all the unused values
	*/
	for (int k = 1; k <= size*size; k++) {
		if (!used[k]) {
			candidates.push_back(k);
		}
	}
}

void backtracking(int i, int j, int size){
	if(is_solution(i, j, size)) {
		first_solution=true;
		process_solution(size);
	}
	else{
		if (i >= size) return;

		int r = i, c;

		c = (j+1) % size;
		r = c ? r : ++r;

		vector<int> candidates;

		if (data[i][j] == 0) {

			get_candidates(i, j, candidates, size);

			for(unsigned index = 0; index < candidates.size() && !first_solution; index++){
				data[i][j] = candidates[index];
				++used[candidates[index]];
				accum[i] += candidates[index];

				backtracking(r, c, size);

				accum[i] -= candidates[index];
				--used[candidates[index]];
				data[i][j] = 0;
			}
		}
		else {
			backtracking(r, c, size);
		}
	}
}

/*
 * If the input has repeated numbers => it can't be solution
 */
bool check_used () {
	for (unsigned i = 1; i < used.size(); i++) {
		if (used[i] > 1) return true;
	}
	return false;
}


int main(){

	int size;

	while (cin >> size) {
		first_solution = false;
		int ssize = size*size;
		magic_constant = ((ssize * (ssize+1))>>1)/size; // [(n**2) * (1 + n**2)]/n

		accum.assign (size, 0);

		used.assign(size*size + 1,0);


		data.resize(size);
		for (int i = 0; i < size; i++){
			data[i].assign (size, 0);
		}

		int tmp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> tmp;
				data[i][j] = tmp;
				used[tmp]++;
				if (tmp) {
					accum[i] += tmp;
				}
			}
		}

		cout << "Case #" << ++n_case << "\n";

		if (check_used()) {
			cout << "No Solution\n\n";
			continue;
		}

		backtracking (0, 0, size);

		if (false == first_solution) {
			cout << "No Solution\n\n";
		}

	}
	return 0;
}
