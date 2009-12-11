/** 
 * Title: Largest Submatrix
 * URL: http://uva.onlinejudge.org/external/8/836.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: bortoli.leonardo at gmail dot com
 * Description of solution:
    Ver la solucion del problema acm-00108.
    Es un caso particular de dicho problema. Ademas de sumar los 'unos' de la submatriz,
    se verifica si esa cantidad es igual al area de la submatriz correspondiente.
**/

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<vector<int> > m;
vector<vector<int> > t;
int max_area;

int initial_max(){
	for(unsigned i=0; i<m.size(); i++){
		for(unsigned j=0; j<m.size(); j++){
			if(m[i][j] == 1)
				return 1;
		}
	}
	
	return 0;
}

void get_max(int i, int j){
	int s = m.size();
	
	// horizontal
	for(int f=i; f<s; f++){
		t[f][j] = m[f][j];
	}
	for(int df=0; i+df<s; df++){
		for(int dc=1; j+dc<s; dc++){
			t[i+df][j+dc] = t[i+df][j+dc-1] + m[i+df][j+dc];
			
			if(t[i+df][j+dc] == (dc + 1) * (df + 1) && t[i+df][j+dc] > max_area){
				max_area = t[i+df][j+dc];
			}
		}
	}
	for(int df=1; i+df<s; df++){
		for(int dc=df; j+dc<s; dc++){
			t[i+df][j+dc] += t[i+df-1][j+dc];
			
			if(t[i+df][j+dc] == (dc + 1) * (df + 1) && t[i+df][j+dc] > max_area){
				max_area = t[i+df][j+dc];
			}
		}
	}
	
	// vertical
	for(int c=j; c<s; c++){
		t[i][c] = m[i][c];
	}
	for(int df=1; i+df<s; df++){
		for(int dc=0; j+dc<s; dc++){
			t[i+df][j+dc] = t[i+df-1][j+dc] + m[i+df][j+dc];
			
			if(t[i+df][j+dc] == (dc + 1) * (df + 1) && t[i+df][j+dc] > max_area){
				max_area = t[i+df][j+dc];
			}
		}
	}
	for(int dc=1; j+dc<s; dc++){
		for(int df=dc+1; i+df<s; df++){
			t[i+df][j+dc] += t[i+df][j+dc-1];
			
			if(t[i+df][j+dc] == (dc + 1) * (df + 1) && t[i+df][j+dc] > max_area){
				max_area = t[i+df][j+dc];
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	char row[26];
	
	for(int i=0; i<n; i++){
		cin.ignore();
		
		cin >> row;
		int m_size = strlen(row);
		
		m.resize(m_size);
		t.resize(m_size);
		for(int j=0; j<m_size; j++){
			m[j].resize(m_size);
			t[j].resize(m_size);
		}
		
		for(int j=0; j<m_size; j++)
			m[0][j] = row[j]-'0';
			
		char c;
		for(int j=1; j<m_size; j++){
			for(int k=0; k<m_size; k++){
				cin >> c;
				m[j][k] = c-'0';
			}
		}
		
		max_area = initial_max();
		
		if(max_area){ // si initial_max() devuelve 0, no debe buscar las submatrices
			for(int j=0; j<m_size; j++){
				for(int k=0; k<m_size; k++){
					get_max(j, k);
				}
			}
		}
		
		cout << max_area << endl;
		
		// para que no imprima una nueva linea al final de todas las salidas
		if(i+1 < n)
			cout << endl;
	}
	
	return 0;
}
