/**
 * Title: Free Binary Strings
 * URL: http://uva.onlinejudge.org/external/111/11127.html
 * Resources of interest:
 * Solver group: David-Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	+ La solucion se basa en la tecnica de backtracking.
	+ Para que el algoritmo termine antes del tiempo limite es necesario
	+ realizar una poda en el arbol de expansion que genera el backtracking.
	+ Las optimizaciones que se realizan son las siguientes:
	   1) Se expande solamente si la cadena resultante no es triple free.
		2) Si en la entrada se ingresan 0s y 1s, se expande con 0 y 1
		   respectivamente si corresponde.	
**/


#include <iostream>
#include <vector>
using namespace std;

vector<int> data;
vector<int> in;
unsigned int cont;

bool is_triple_free(int);
bool compare(int, int, int);
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

	int size, cases=0;
	while (cin >> size){
		if(0 == size) return 0;

		cases++;
		cont = 0;	
		data.reserve(size);
		in.reserve(size);
		
		for(int i = 0; i < size; i++){
			char c;
			cin >> c;
			if (c == '0') in.push_back(0);
			else if (c == '1') in.push_back(1);
			else in.push_back(-1);
		}
		
		backtracking();
	
		cout << "Case " << cases << ": " << cont << endl;

		in.clear();
		data.clear();	
	}
	
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
	return in.size() == data.size();
}

void process_solution(){
	for (unsigned i = 0; i < in.size(); i++){
		if(in[i] > -1)
			if(data[i] != in[i])
				return;		
	}
	cont++;
	
}

void get_candidates(vector<int> &candidates){
	
	if(data.size() < 2) {
		if(in[data.size()] > -1){
			candidates.push_back(in[data.size()]);
		}else {
			candidates.push_back(0);
			candidates.push_back(1);
		}
	}
	else{
		if(in[data.size()] > -1){
			if(!is_triple_free(in[data.size()]))
				candidates.push_back(in[data.size()]);
		} else {
			if(!is_triple_free(0)) candidates.push_back(0);
			if(!is_triple_free(1)) candidates.push_back(1);
		}
	}	
}

bool is_triple_free(int op){
	data.push_back(op);

	int n = data.size() / 3;
		
	for (int i = 1; i <= n; i++){
		if(compare(data.size() - i*3, data.size() - i*2, i) &&
			compare(data.size() - i*2, data.size() - i, i) ) {
			data.pop_back();
			return true;
		}
	}
	data.pop_back();
	return false;
}

bool compare(int a, int b, int size){
	for ( int i = 0; i < size; i++) {
		if(data[a+i] !=  data[b+i]) return false;
	}
	return true;
}
