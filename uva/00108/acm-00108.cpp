/** 
 * Title: Maximum Sum 
 * URL: http://uva.onlinejudge.org/external/1/108.html
 * Resources of interest:
 * Solver group: Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Primero se lee e inicializa una matriz(m) de N x N elementos, 
    luego utilizando la matriz temporal (t) de N x N se calcula 
    la suma maxima con un algoritmo de O(n^4), es decir, se va probando
    con todas las posibilidades.
    + 
**/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int> > m;
vector<vector<int> > t; 
int max_count;

int max_pos(int N){
	int max = m[0][0];
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(max < m[i][j])
				max = m[i][j];
		}
	}
	return max;
}

void get_max(int i, int j, int N){ 
	// horizontal
	for(int x = 0; x < N; x++){
		t[x][j] = m[x][j];
	}
	
	for(int dx = 0; i+dx < N; dx++){
		for(int dy = 1; j+dy < N; dy++){	
			t[i+dx][j+dy] = t[i+dx][j+dy-1] + m[i+dx][j+dy];

			if(max_count < t[i+dx][j+dy]){
				max_count = t[i+dx][j+dy];
			}
		}
	}
	
	for(int dx = 1; i+dx < N; dx++){
		for(int dy = dx; j+dy < N ; dy++){	
			t[i+dx][j+dy] += t[i+dx-1][j+dy];

			if(max_count < t[i+dx][j+dy]) {
				max_count = t[i+dx][j+dy];
			}
		}
	}
	
	// vertical
	for(int y = 0; y < N; y++){
		t[i][y] = m[i][y];		
	}
		
	for(int dx = 1; i+dx < N; dx++){
		for(int dy = 0; j+dy < N; dy++){	
			t[i+dx][j+dy] = t[i+dx-1][j+dy] + m[i+dx][j+dy];

			if(max_count < t[i+dx][j+dy]) { 
				max_count = t[i+dx][j+dy];	
			}
		}
	}

	for(int dx = 1; i+dx < N; dx++){
		for(int dy = 1; j+dy < N ; dy++){	
			t[i+dx][j+dy] += t[i+dx][j+dy-1];

			if(max_count < t[i+dx][j+dy]) {
				max_count = t[i+dx][j+dy];
			}
		}
	}
}

int main(){
	int N;
	
	cin >> N;

	m.resize(N);
	t.resize(N);

	for(int index = 0; index < N; index++){
		m[index].resize(N);
		t[index].resize(N);		
	}

	int i=0, j=0, c;
	int NN = N*N; 

	for(int index = 0; index < NN; index++){
		cin >> c;

		m[i][j++] = c;

		if(j % N == 0){
		 	j = 0;
		 	++i;
		}
	}	
	//solve !!
	max_count = max_pos(N);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			get_max(i, j, N);
		}
	}

	cout << max_count << endl;

	return 0;
}

