#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 10

vector<int> data;

/*
 * Bandera de parada del backtracking.
 * Inicialmente en false.
 */ bool first_solution;

/* se le pueden agregar parametros que ayuden
 * a la resolucion de un problema determinado.
 */ void backtracking();

/*
 * Se avalúa si data es una solución.
 */ bool is_solution(unsigned n) {
	return data.size() == n;
}

/*
 * procesar una solucion
 */ void process_solution() {
	cout << data << "\n";
}

/*
 * expandir alternativas a un estado que no es solucion.
 */ void get_candidates(vector<int> &candidates);



void backtracking(string s){
	if(is_solution(s.size())){
		process_solution();
	}else{
//		if(first_solution) return;
			
		vector<int> candidates;

		get_candidates(candidates, s);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking();
			data.pop_back();
		}
	}
}

bool is_solution(){
	//si corresponde hacer: first_solution = true;
	return false;
}

void process_solution(){
	cout << "solucion..." << endl;
}

void get_candidates(vector<int> &candidates){
	
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

	while (cin >> l) {
		sort(l.begin(), l.end(), compare);
		cout << l;

	}
}


