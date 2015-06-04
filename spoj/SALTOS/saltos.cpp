#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 10

vector<int> data;
int solutions;

/*
 * Bandera de parada del backtracking.
 * Inicialmente en false.
 */ bool first_solution;

/* se le pueden agregar parametros que ayuden
 * a la resolucion de un problema determinado.
 */ void backtracking(int);

/*
 * Se avalúa si data es una solución.
 */ bool is_solution(int);

/*
 * procesar una solucion
 */ void process_solution();

/*
 * expandir alternativas a un estado que no es solucion.
 */ void get_candidates(vector<int> &candidates, int n);

int main(){
	int n;
	
	while (cin >> n) {
		if (0==n) return 0;
		
		solutions = 0;
		data.clear();
		backtracking(n);
		cout << solutions << endl;
	}
	
	// USAR: data.push_back()
	// para cada caso de prueba usar data.clear() y first_solution = false
	
	return 0;
}

void backtracking(int n){
	if(is_solution(n)){
		process_solution();
	}else{
		if(first_solution) return;
			
		vector<int> candidates;

		get_candidates(candidates, n);
		
		for(int i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			backtracking(n);
			data.pop_back();
		}
	}
}

bool is_solution(int n){
	if (data.size() == n) {
		
		vector<bool> generated (n, false);
		for (int i=0; i<data.size()-1; i++) {		
			generated[abs(data[i]-data[i+1])] = true;
		}
	
	/*for (int i=1; i<generated.size(); i++) {		
			if (generated[i] == false) return false;
		}*/
	return true;
	}
	return false;
}

void process_solution(){
	solutions++;
}

void get_candidates(vector<int> &candidates, int n){
	vector<bool> used (n+1, false);
	vector<bool> generated (n, false);
	used[0] = true;
	generated[0] = true;

	
	if (data.size() > 0) {
		for (int i=0; i<data.size(); i++) {
			used[data[i]] = true;
		}

		for (int i=0; i<data.size()-1; i++) {		
			generated[abs(data[i]-data[i+1])] = true;
		}

	
		int last=data[data.size()-1];
		for (int i=1; i<= n; i++) {

			if (!used[i] && !generated[abs(last-i)]) {
				candidates.push_back(i);
			}		
		}
	
	}
	else {
		for(int i=1; i<=n; i++){
			candidates.push_back(i);
		}
	}	
}

