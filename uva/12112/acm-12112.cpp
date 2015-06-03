// NOT ACCEPTED SOT FAR
//$ g++ -std=c++11 acm-12112.cpp


#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX_ROW 12
#define MAX_COL 12

unsigned best_solution; //size of best solution so far

vector<string> data;

/*
 * Bandera de parada del backtracking.
 * Inicialmente en false.
 */ bool first_solution;

/* se le pueden agregar parametros que ayuden
 * a la resolucion de un problema determinado.
 */ void backtracking(int i , int j);

/*
 * Se avalúa si data es una solución.
 */ bool is_solution(int, int );

/*
 * procesar una solucion
 */ void process_solution();

/*
 * expandir alternativas a un estado que no es solucion.
 */ void get_candidates(int i, int j, vector<int> &candidates);

void add_candidate(int &i, int &j, int data);
void del_candidate(int &i, int &j, int data);

int main(){
	string line;
	unsigned n_case = 1, r, c;
	unsigned long long pos;
		
		
	while (1) {
		getline (cin, line);
		//cin.ignore();
		if (line.size() == 1 && line[0] == '0') {
			return 0;
		}

		best_solution = 15;
		data.clear();
		
		if ((pos = line.find_first_not_of("0123456789")) != string::npos) { // well differenciated nums
			r = stoi(line.substr(0, pos));			
			pos = line.find_first_of("0123456789", pos);
			c = stoi(line.substr(pos, string::npos));
		}
		else { //just one string of nums...
			if (line[1] == '0') { //first one is 10
				r = stoi(line.substr(0,2));
				c = stoi(line.substr(2, string::npos));
			}
			else { //first one is < 10, second one could be 10
				r = stoi(line.substr(0,1));
				c = stoi(line.substr(1, string::npos));
			}
		}		
//cout << "1º: " << r << endl;
//cout << "2º: " << c << endl;

		data = vector<string> (r);
		for (unsigned i=0; i < r; i++) {			
			getline(cin, data[i]);
			for (unsigned )
		}
		
		cout << endl;
		for(int i = 0; i < r; i++) {
			//for(int i = 0; i < r; i++) {
				cout << data[i] << endl;
			//}			
		}
		
		cout << "Case " << n_case++ << ": ";
		
		// USAR: data.push_back()
		// para cada caso de prueba usar data.clear()	
		
	}
	return 0;
}

void backtracking(int i, int j){
	if(is_solution(i, j)){
		process_solution();
	}else{
		if(first_solution) return;
			
		vector<int> candidates;

		get_candidates(i, j, candidates);
		
		for(unsigned index = 0; index < candidates.size(); index++){
			add_candidate(i, j, candidates[index]);
			backtracking(i, j);
			del_candidate(i, j, candidates[index]); 
		}
	}
}

bool is_solution(int i, int j){
	//si corresponde hacer: first_solution = true;
	

	
	
	return false;
}

void process_solution(){
	cout << "solucion..." << endl;
	if (1) {
		//best_solution
	}
}

void get_candidates(int i, int j, vector<int> &candidates){
}

void add_candidate(int &i, int &j, int n){
		// USAR: data.push_back()

}

void del_candidate(int &i, int &j, int n){
		// USAR: data.pop_back()

}
