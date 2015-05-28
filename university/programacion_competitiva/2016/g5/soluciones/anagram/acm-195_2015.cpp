#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 10

vector<char> data;

bool my_comp(char a, char b){
  char A=tolower(a);
  char B=tolower(b);
  return (A==B ? a<b: A<B);
}

void process_solution() {
	for(unsigned i=0; i<data.size(); i++) {
		cout << data[i];
	}
	cout << '\n';
}

bool is_solution(int s){
	return data.size() == s;
}

void get_candidates(vector<char> &candidates, const string& in){
	map<char, unsigned, bool(*)(char, char)> cnt(my_comp);
	for (unsigned i=0; i<in.size(); i++) {
		cnt[in[i]]++;
	}
	for (unsigned i=0; i<data.size(); i++) {
		cnt[data[i]]--;
	}
	for (map<char, unsigned>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
		if (it->second > 0) {
			//cout <<"T";
			candidates.push_back(it->first);
		}
	}/*
	cout << "cand: ";
	for (int i=0; i<candidates.size(); i++) {
		cout << candidates[i];
	}
	cout << endl;*/
}


void backtracking(const string& in){
	if(is_solution(in.size())){
		process_solution();
	}else{
		//if(first_solution) return;
			
		vector<char> candidates;

		get_candidates(candidates, in);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking(in);
			data.pop_back();
		}
	}
}
// c < d ?
// A a true
// A b true
// A A false
// a A false
// b A false
bool compare (char c, char d) {
	if (c == d) return false;
	if (toupper(c) == toupper(d)) return c < d;

	return toupper(c) < toupper(d);
}



int main () {
	unsigned n_cases;
	string l;
	cin >> n_cases;

	for (unsigned i=0; i<n_cases; i++) {
		data.clear();
		cin >> l;
		sort(l.begin(), l.end(), my_comp);
		backtracking(l);
		
	}
}


