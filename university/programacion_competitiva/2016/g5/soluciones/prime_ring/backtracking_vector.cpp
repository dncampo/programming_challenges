#include <iostream>
#include <vector>
using namespace std;

#define MAX 10

vector<unsigned> data;


bool is_solution(unsigned n){
	//si corresponde hacer: first_solution = true;
	return data.size() == n;
}

void process_solution(){
	for (unsigned i=0; i<data.size(); i++){
		cout << data[i] << " ";
	}
	cout << "\n";
	
}

bool is_prime (unsigned i) {
	return (3==i || 5==i || 7==i || 11==i || 13==i || 17==i || 19==i || \
			23==i || 29==i || 31==i);
}

void get_candidates(vector<int> &candidates, unsigned n){
	vector<bool> cands (n+1, true);
	cands[0] = false;
	unsigned last = data.back();
	
	bool first = (data.size() + 1 == l)? true: false;
	
	for (unsigned i=0; i<data.size(); i++){
		cands[data[i]] = false;
	}
	
	for (unsigned i=2; i<cand.size(); i++) {
		if (!is_prime(last + i)) { //check sum w/last
			cand[i] = false;
		}
		
		if (first) { //check w/first too
			if (!is_prime(1 + i)) {
				cand[i] = false;
			}
	}
	
	for (unsigned i=2; i<cand.size(); i++) {
		if (cand[i]) {
			candidates.push_back(i); 
		}
	}
	
}

void backtracking(unsigned n){
	if(is_solution(n)){
		process_solution(n);
	}else{
			
		vector<int> candidates;

		get_candidates(candidates);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking();
			data.pop_back();
		}
	}
}

int main(){
	unsigned n;

	while (cin >> n){
		backtracking(n);
	} 
	

	
	// USAR: data.push_back()
	// para cada caso de prueba usar data.clear() y first_solution = false
	return 0;
}
