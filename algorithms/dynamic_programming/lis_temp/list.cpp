#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant {
	unsigned w, iq, id;
};

bool cmp (Elephant a, Elephant b) { 
	return a.iq > b.iq;
}

/*
vector<unsigned> lis (vector<Elephant> &a) {
	vector<unsigned> b, p(a.size());
	int u, v;

	//if (a.size() < 1) return b;

	//Elephant e = {0 , 0, 0};
	//b.push_back(0);
	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++) {
		if (a[ b.back() ].w < a[i].w) {
			p[i] = b.back();
			b.push_back(a[i].id);
			continue;
		}

		for (u = 0, v = b.size()-1; u < v;) {
			unsigned c = (u + v) / 2;
			if (a[b[c]].w < a[i].w ) u=c+1; else v=c;
		}

		if (a[i].w < a[b[u]].w) {
			if (u > 0) p[i] = b[u-1];
			b[u] = a[i].id;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}

*/

int lis(vector<Elephant> A, vector<Elephant> B, vector<vector<int> >& pm) {
	for (int i = A.size(); i > 0; i--)
		for (int j = B.size(); j > 0; j--) {

			if (i == (int)A.size() || j == (int)B.size()) pm[i][j] = 0;
			else if (A[i].w < B[j].w) pm[i][j] = 1 + pm[i+1][j+1];
			else pm[i][j] = max(pm[i][j+1], pm[i+1][j]);
		
		}
	return pm[0][0];
}

void print_lcs(vector<string> A, vector<string> B, vector<vector<int> >& pm){
	int i = 0, j = 0, m = A.size(), n = B.size();
	bool first = true;
	while (i < m && j < n){
		if (A[i] == B[j]){
			if(first){
				cout << A[i];
				first = false;
			}
			else
				cout << " " << A[i];
			i++; j++;
		}
	else if (pm[i+1][j] >= pm[i][j+1]) i++;
	else j++;
	}
	cout << endl;
}

int main() {

	unsigned w, iq, id = 1;

	vector <Elephant> elephants;
	while (cin >> w >> iq) {
		Elephant e = {w, iq, id++};
		elephants.push_back (e);
	}
	
	sort (elephants.begin (), elephants.end (), cmp);
	

	vector<vector<int> > prefix_matrix(elephants.size() + 1);
	for(unsigned i = 0; i < elephants.size() + 1; i++){
		vector<int> vy(elephants.size() + 1,0);
		prefix_matrix[i] = vy;
	}

	int sol = lis ( elephants, elephants, prefix_matrix );
	cout << sol << endl;
	
/*
	cout << sol.size () << endl;
	for (vector<Elephant>::const_reverse_iterator it = sol.rbegin (); it != sol.rend (); it++) {
		cout << it->id << endl;
	}*/
/*
	int a[] = { 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> lis = lis(seq);
 
	for (size_t i = 0; i < lis.size(); i++)
		printf("%d ", seq[lis[i]]);
        printf("\n"); */
 
	return 0;
}