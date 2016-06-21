#include <iostream>
#include <vector>
using namespace std;

#define MAX 10

vector<int> data;

/*
 * Bandera de parada del backtracking.
 * Inicialmente en false.
 */ bool first_solution;
 
 
void process_solution(){
    for (int i=0; i<data.size();i++)
        cout << data[i] << " ";  
    cout << endl;
}

bool is_solution(int n){
	//si corresponde hacer: first_solution = true;
	return n==data.size();
}



bool is_prime(int n){
    for (int i=2; i*i<=n; i++){
        if (n%i==0) return false;
    }
    return true;
}

void get_candidates(vector<int> &candidates, int n){
	vector<bool> used(n+1, false);
    int actual = data.back();
    bool last = data.size()== n-1;
    
    for (int i=0; i<data.size();i++) used[data[i]]=true;
    
    for(int i=2; i<=n; i++){
        if(!used[i] && is_prime(actual+i) && (!last || is_prime(i+1))){
            candidates.push_back(i);
        }
    }    
}


void backtracking(int n){
	if(is_solution(n)){
		process_solution();
	}else{
		if(first_solution) return;
			
		vector<int> candidates;

		get_candidates(candidates, n);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking(n);
			data.pop_back();
		}
	}
}




int main () {
	unsigned n, ncase=1;

	while(cin >> n) {
        data.clear();
        data.push_back(1);
        cout << "Case: " << ncase++ << endl;        
        backtracking(n);
        cout << endl;       
        
    }
}


