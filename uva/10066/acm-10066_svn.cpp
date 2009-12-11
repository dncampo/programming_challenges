	/**
 * Title: The Twin Towers
 * URL:http://online-judge.uva.es/problemset/v100/10066.html 
 * Resources of interest:
 * Solver group: Yeyo-Po
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Se utiliza programación dinamica para resolver el problema.
    Se crea una matriz de N1xN2 elementos donde se va calculando la solución.   
**/
#include <iostream>
#include <vector>
using namespace std;

#define max(a, b) a > b? a : b

int solve(vector<int> &a, vector<int> &b){
	vector<vector<int> > m(b.size());
	
	for(int i = 0; i < m.size(); i++){
		m[i].assign(a.size(), 0);
	}

	// construir la solucion
	m[0][0] = (a[0] == b[0])? 1 : 0;
	
	for(int j = 1; j < m[0].size(); j++){
		m[0][j] = (a[j] == b[0]) ? 1 : m[0][j-1];
	}
	
	for(int i = 1; i < m.size(); i++) {
		m[i][0] = (b[i] == a[0]) ? 1 : m[i-1][0];
	}
	
	for(int i = 1; i < m.size(); i++){
		for(int j = 1; j < m[i].size(); j++){
			if(a[j] == b[i]&& m[i][j-1] >= m[i-1][j]){					
				m[i][j] = 1 + m[i-1][j];
			}else {
				m[i][j] = max( m[i-1][j], m[i][j-1]);
			}
		}
	}	

	return m[b.size()-1][a.size()-1];
}

int main(){
	int N1, N2;
	int count = 0, tmp;
	vector<int> T1, T2;
		
	cin >> N1 >> N2;
	
	while(N1 != 0 && N2 != 0){
		T1.clear();
		T2.clear();
		++count;
		
		for(int i = 0; i< N1; i++){
			cin >> tmp;
			T1.push_back(tmp);
		}
		
		for(int i = 0; i< N2; i++){
			cin >> tmp;
			T2.push_back(tmp);
		}
	
		cout << "Twin Towers #" << count << endl;
		cout << "Number of Tiles : " << solve(T1, T2) << endl;
		cout << endl;
		cin >> N1 >> N2;
	}

	return 0;
}
