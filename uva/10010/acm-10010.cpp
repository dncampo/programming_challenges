#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool to_right(string& line, unsigned row, unsigned col, string& q){
	
	for(unsigned i = col, j = 1; j < q.size(); i++, j++ )
		if(q[j] != line[i]) return false;
		
	cout << row + 1 << " " << col << endl;
	return true;
}

bool to_left(string& line, unsigned row, unsigned col, string& q){
	for(unsigned i = col, j = 1; j < q.size(); i--, j++ )
		if(q[j] != line[i]) return false;

	cout << row + 1 << " " << col+2 << endl;		
	return true;
}

bool to_down(vector<string> &mat, unsigned row, unsigned col, string& q){
	for(unsigned i = row, j = 1; j < q.size(); i++, j++)
		if(q[j] != mat[i][col]) return false;

	cout << row << " " << col + 1 << endl;		
	return true;
}

bool to_up(vector<string>& mat, unsigned row, unsigned col, string& q){
	for(unsigned i = row, j = 1; j < q.size(); i--, j++)
		if(q[j] != mat[i][col]) return false;

	cout << row+2 << " " << col + 1 << endl;
	return true;	
}

bool to_down_right (vector<string>& mat, unsigned row, unsigned col, string& q){
	for(unsigned i = row, m = col, j = 1; j < q.size(); i++, m++, j++)
		if(q[j] != mat[i][m]) return false;

	cout << row << " " << col << endl;		
	return true;
}

bool to_down_left (vector<string> &mat, unsigned row, unsigned col, string& q){
	for(unsigned i = row, m = col, j = 1; j < q.size(); i++, m--, j++)
		if(q[j] != mat[i][m]) return false;

	cout << row << " " << col+2 << endl;		
	return true;
}

bool to_up_right (vector<string> &mat, unsigned row, unsigned col, string &q){
	for(unsigned i = row, m = col, j = 1; j < q.size(); i--, m++, j++)
		if(q[j] != mat[i][m]) return false;

	cout << row+2 << " " << col << endl;		
	return true;
}

bool to_up_left (vector<string>& mat, unsigned row, unsigned col, string &q){
	for(unsigned i = row, m = col, j = 1; j < q.size(); i--, m--, j++)
		if(q[j] != mat[i][m]) return false;

	cout << row+2 << " " << col+2 << endl;		
	return true;
}




void solve(vector <string>& mat, string &q){
	int m = mat.size();
	int n = mat[0].size();
	int q_size = q.size();
	char c = q[0];

	for(int i = 0; i < (int)m; i++){
		for(int j = 0; j < (int)n; j++){
			if(mat[i][j] == c){
		
				if(q_size == 1){ //el pattern es de 1 char :)
					cout << i+1 << " " << j+1 << endl;
					return;
				}
				bool ret;
					
				if(j + q_size <= n){ //hacia la derecha
					ret = to_right(mat[i], i, j + 1 ,q);				
					if(ret) return;
				}
				
				if(j - (q_size - 1) >= 0){ //hacia la izquierda
					ret = to_left(mat[i], i, j - 1,q);
					if(ret) return;
				}
				
				
				if(i + q_size <= m){ //hacia abajo
					ret = to_down(mat, i + 1, j ,q);
					if (ret) return;				
				}

				if(i - (q_size - 1) >= 0){ //hacia arriba
					ret = to_up(mat, i - 1, j, q);
					if (ret) return;
				}
				
				if( (i + q_size <= m) &&  (j + q_size <= n) ) { //hacia abajo + derecha
					ret = to_down_right(mat, i + 1, j + 1, q);
					if (ret) return;
				}
				
				if( (i + q_size <= m) && (j - (q_size- 1) >= 0) ){ //hacia abajo + izquierda
					ret = to_down_left(mat, i + 1, j - 1, q);
					if (ret) return;
				}
				
				if( (i - (q_size - 1) >= 0) &&  (j + q_size <= n) ){ //hacia arriba + derecha
					ret = to_up_right(mat, i - 1, j + 1, q);
					if (ret) return;
				}
				
				if( (i - (q_size - 1) >= 0) && (j - (q_size- 1) >= 0) ) { //hacia arriba + izquierda
					ret = to_up_left(mat, i - 1, j - 1, q);
					if(ret) return;
				}
			}
		}
	}
}

int main(){
	unsigned n_cases;
	cin >> n_cases;
	
	for(unsigned i = 0; i < n_cases; i++){
		unsigned m, n;
		cin >> m >> n;

		vector<string> matrix(m);
		for (unsigned j = 0; j < m; j++){
			for (unsigned k = 0; k < n; k++){
				char c;
				cin >> c;
				matrix[j].push_back(tolower(c));
			}
		}
		
		
/*		for(unsigned i = 0; i < matrix.size(); i++){
			for(unsigned j = 0; j < matrix[i].size(); j++){
				cout << matrix[i][j];
			}
			cout << endl;
		}
*/

		unsigned queries;
		cin >> queries;

		string q;
		for(unsigned a = 0; a < queries; a++){
			cin >> q;
			
			for(unsigned b = 0; b < q.size(); b++){
				q[b] = tolower(q[b]);
			}
			solve(matrix, q);
		}
		cout << endl;
	}
	
	return 0;	
}

