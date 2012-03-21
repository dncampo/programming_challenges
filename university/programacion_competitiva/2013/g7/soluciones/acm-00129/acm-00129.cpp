/**
 * Title:  Krypton Factor
 * URL: http://uva.onlinejudge.org/external/1/129.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
	+ La solucion se basa en la tecnica de backtracking.
	+ Para que el algoritmo termine antes del tiempo limite es necesario
	+ realizar una poda en el arbol de expansion que genera el backtracking.
	+ La optimizacion que se realiza es la siguiente:
	   1) Se expande solamente si la cadena resultante no es hard sequence.

**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define TOTAL 27

string data;
unsigned n, L, counter;

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
 */ void get_candidates(vector<char> &candidates);
 
char letters[TOTAL];

bool is_hard_sequence(char );
bool compare(int, int, unsigned );

int main(){
	// inicializar letters
	char c = 65;
	for(int i=1; i<TOTAL; i++, c++)
		letters[i] = c;

	cin >> n >> L;
	while(n != 0 && L != 0){
		backtracking();
		
		data.clear();
		counter = 0;
		first_solution = false; // ACORDARSE DE HACER ESTO
		cin >> n >> L;
	}
	// USAR: data.push_back()
	// para cada caso de prueba usar data.clear()
	// actualizar first_solution
	return 0;
}

void backtracking(){
	if(is_solution()){
		process_solution();
	}else{                               
		if(first_solution) return;
			
		vector<char> candidates;

		get_candidates(candidates);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			data.push_back(candidates[i]);
			counter++;
			backtracking();
			data.erase(data.size() - 1);
		}
	}
}

bool is_solution(){
	return counter == n;
}

void process_solution(){
	first_solution = true; // SE NECESITA SOLO LA PRIMER SOLUCION
	unsigned i=0, j=0;
	
	for(; i+4 < data.size(); i+=4){
		printf("%c%c%c%c", data[i], data[i+1], data[i+2], data[i+3]);
		j++;
		if(j == 16)
			putchar('\n');
		else
			putchar(' ');
	}
	for(; i < data.size(); i++)
		printf("%c", data[i]);
		
	cout << endl << data.size() << endl;
}

void get_candidates(vector<char> &candidates){
	if(data.empty())
		for(unsigned i=1; i<=L; i++)
			candidates.push_back(letters[i]);
	else{
		for(unsigned i=1; i<=L; i++)
			if(data[data.size()-1] != letters[i] && is_hard_sequence(letters[i]))
				candidates.push_back(letters[i]);
	}
}

bool is_hard_sequence(char c){
	data.push_back(c);
	
	unsigned s = data.size();
	unsigned size = s / 2;
	
	for(unsigned i=1; i<=size; i++)
		if(compare(s-i*2, s-i, i)){
			data.erase(s-1);
			return false;
		}

	data.erase(s-1);
	return true;
}

bool compare(int a, int b, unsigned size){
	for(unsigned i = 0; i < size; i++)
		if(data[a+i] != data[b+i])
			return false;
	return true;
}

