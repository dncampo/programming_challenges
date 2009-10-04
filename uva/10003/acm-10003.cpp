#include<iostream>
#include<vector>
#include<limits>

using namespace std;

vector<vector<unsigned> > m, s;

unsigned solve(vector<unsigned>& p){
	m.resize(p.size());
	s.resize(p.size());
	
	for(unsigned i = 0; i < p.size(); i++){
		m[i].assign(p.size(), 0);
		s[i].assign(p.size(), 0);
	}
	

	for(unsigned l = 2; l < p.size(); l++) {
		for(unsigned i = 0; i < p.size()-l;i++){
			unsigned j = i+l;

			m[i][j] = numeric_limits<unsigned>::max();

			for(unsigned k = i+1; k <= j - 1; k++){
				unsigned q = m[i][k] + m[k][j] + p[j] - p[i];
				
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		} 
	}

	return m[0][p.size()-1];
}

int main(){
	unsigned n, size;
	vector<unsigned> p;	
	
	cin >> n;
	
	while(n > 0){
		cin >> size;
	

		p.push_back(0);
		
		for(unsigned i = 0; i < size; i++){
			unsigned tmp;
			cin >> tmp;
			p.push_back(tmp);
		}
		
		p.push_back(n);
		
		cout << "The minimum cutting is " << solve(p) << "." << endl;

		cin >> n;
		p.clear();
	}

	return 0;
}

