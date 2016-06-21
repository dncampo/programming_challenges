#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> data;


bool is_solution(unsigned l){
	return data.size() == l;
}

void process_solution(unsigned l){
	for (unsigned i=0; i<l; i++){
		cout << data[i] << " ";
	}
	cout << "\n";
}

bool is_prime (unsigned i) {
	return (3==i || 5==i || 7==i || 11==i || 13==i || 17==i || 19==i || \
			23==i || 29==i || 31==i);
}

void get_candidates(vector<unsigned> &candidates, unsigned l){
	vector<bool> cand(l+1, true);
	unsigned last = data.back();
	
	bool first = (data.size() + 1 == l)? true: false;
	
	cand[0] = false;
	for (unsigned i=0; i<data.size(); i++) {
		cand[data[i]] = false;
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
	}
	
	for (unsigned i=2; i<cand.size(); i++) {
		if (cand[i]) {
			candidates.push_back(i); 
		}
	}

}


void backtracking(unsigned l){
	if(is_solution(l)){
		process_solution(l);
	}else{
		vector<unsigned> candidates;

		get_candidates(candidates, l);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking(l);
			data.pop_back();
		}
	}
}


int main () {
	unsigned l;

	while (cin >> l) {
		data.clear();
		data.push_back(1);
		backtracking(l);
	}
}


