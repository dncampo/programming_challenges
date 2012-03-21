/**
 * Title: The Triangle Game
 * URL: http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=2061
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Primero se pone el primer triángulo en la solución, y por cada una de sus 3 rotaciones se hace
	un backtracking con los restantes triangulos.
	+ Para agregar un triángulo como candidato a la última posición de la solución parcial se verifica
	que su lado izquierdo (L) sea igual al lado derecho (R) del último triángulo colocado.
	+ Todo triángulo, o cualquiera de sus rotaciones, que cumpla con la restricción anterior es un
	candidato para ocupar el último lugar disponible de la solución parcial.
	+ Antes de agregar un triángulo candidato a la solución parcial se verifica que no esté agregado
	(en ninguna de sus rotaciones)
	+ Por cada triángulo que se agregue, se llama a backtracking.

**/



#include <iostream>
#include <vector>

using namespace std;

struct Triangle {
	unsigned L; //L stands for left (so obvious, don't?)
	unsigned C;
	unsigned R;
	unsigned id; //identify each triangle
	
	void rotate() { //like clockwise rotation
		unsigned temp = R;
		R = L;
		L = C;
		C = temp;
	}
};

vector<Triangle> hexagon;
unsigned solution_score = 0;

void backtracking(vector<Triangle>);
bool is_solution();
void process_solution();
void get_candidates(vector<Triangle> &candidates, vector<Triangle>);

int main(){
	char c;
	
	do {
		solution_score = 0;
		hexagon.clear();
		
		//read the data
		vector<Triangle> availables (6);
		for (unsigned i = 0; i < 6; i++) {
			Triangle T;
			cin >> T.L >> T.C >> T.R;
			T.id = i;
			availables[i] = T;
		}
		cin >> c; //the most useless line

		//first triangle *must* be in the solution
		hexagon.push_back(availables[0]); //so put it
		availables.erase(availables.begin()); //and remove it from the availability vector

		unsigned max = 0; //max score so far
		for (unsigned i = 0; i < 3; i++){
			backtracking(availables);
			if (solution_score > max) max = solution_score;
			Triangle temp = hexagon[0];
			hexagon.clear();
			hexagon.push_back(temp);
			hexagon[0].rotate(); //other two position of the first triangle
		}
		
		if (0 == solution_score) cout << "none" << endl;
		else cout << solution_score << endl;

	} while ('*' == c);
	
	return 0;
}

void backtracking(vector<Triangle> availables){
	if(is_solution()){
		process_solution();
	}else{

		vector<Triangle> candidates;

		get_candidates(candidates, availables);
		
		for(unsigned i = 0; i < candidates.size(); i++){
			hexagon.push_back(candidates[i]);
			backtracking(availables); //do the magic!
			hexagon.pop_back();
		}
	}
}

bool is_solution(){
	if (6 == hexagon.size())
		return true;
	return false;
}

void process_solution(){
	unsigned sum = 0;
	for (unsigned i = 0; i < hexagon.size(); i++) {
		sum += hexagon[i].C;
	}
	if (sum > solution_score)
		solution_score = sum;
}

// is this triangle already in the solution vector?
bool in_sol (Triangle a_t){
	for (unsigned i = 0; i < hexagon.size(); i++) {
		if (hexagon[i].id == a_t.id) return true;
	}
	return false;
}

//fits this triangle in the last available position at the solution vector?
bool fits_in_sol (Triangle a_t) {
	unsigned index = hexagon.size() - 1;
	
	if (5 == hexagon.size()) { //we almost have a solution!
		if ( (hexagon[index].R == a_t.L) && ( hexagon[0].L == a_t.R) ) return true;
	}
	else {
		if (hexagon[index].R == a_t.L) return true;
	}
	return false; //:(
}


//give me a vector of candidates that I can put in the last position of the solution vector
void get_candidates(vector <Triangle> &candidates, vector<Triangle> availables){
	for (unsigned i = 0; i < availables.size(); i++){
		if (! in_sol(availables[i])){
		
			for (unsigned j = 0; j < 3; j++){ //for each possible rotation...
				bool fits = fits_in_sol(availables[i]);
				if (fits) {
					candidates.push_back(availables[i]);
				}
				availables[i].rotate(); //...make your grace
			}
		}
	}
}

