#include <iostream>
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
 */ bool is_solution();

/*
 * procesar una solucion
 */ void process_solution();

/*
 * expandir alternativas a un estado que no es solucion.
 */ void get_candidates(vector<int> &candidates);

int main(){
	
	// USAR: data.push_back()
	// para cada caso de prueba usar data.clear() y first_solution = false
	return 0;
}

void backtracking(){
	if(is_solution()){
		process_solution();
	}else{
		if(first_solution) return;
			
		vector<int> candidates;

		get_candidates(candidates);
		
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

