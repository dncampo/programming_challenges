#include <iostream>
#include <vector>

using namespace std;

#define N 4

vector<bool> valid (N, true);

bool is_binary(vector<vector<bool> >& a_tree, unsigned root) {
	unsigned count=0;
	vector<unsigned> leafs;
	for (unsigned i=0; i<a_tree.size(); i++){
		if (!valid[i] || i==root) continue;
		
		if (a_tree[root][i] != 0){
			count++;
			if (count>2) return false;
			leafs.push_back(i);
		}
	}
	if (count == 0) {
		return true;
	}
	
	if (count == 2) {
		valid[root]=false;
		bool ret= is_binary(a_tree, leafs[0]) && is_binary(a_tree, leafs[1]);
		valid[root]=true;
		return ret;
	}
	else {
		return false;
	}
}

int main(){
	
	vector<bool> tmp(N,false);
	vector<vector<bool> > tree(N, tmp);
	
	tree[0][1] = true;
	tree[1][0] = true;
	tree[1][2] = true;
	tree[2][1] = true;
	tree[2][3] = true;	
	tree[3][2] = true;
	
	for (unsigned i=0; i<N; i++){
		for (unsigned j=0; j<N; j++){
			cout << tree[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	valid[3] = false;
	cout << (bool)is_binary(tree,2) << endl;
}