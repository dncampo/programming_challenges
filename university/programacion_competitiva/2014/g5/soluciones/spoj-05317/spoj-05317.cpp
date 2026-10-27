/**
 * Title: Tetravex Puzzle
 * URL: http://www.spoj.pl/problems/TETRAVEX/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la técnica de backtracking para resolver el problema.
	+ Se utiliza una estructura Tile para representar cada "ficha".
	+ Se llenan secuencialmente las posiciones (mientras se pueda) y se llega a una solución cuando 
	se colocan las 9 fichas.
	+ En get_candidates se chequea que ficha se puede colocar en la posición actual.

**/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_ROW 3
#define MAX_COL 3

struct Tile {
	int up, down, left, right;
	unsigned id;
};

vector< vector<Tile> > data;
vector<Tile> tiles;
unsigned filled;
bool first_solution;


bool is_solution(){
	if (9 == filled) {
		first_solution = true;
		return true;
	}
	return false;
}

void get_candidates(unsigned i, unsigned j, vector<Tile> &candidates){
	for (unsigned k = 0; k < tiles.size (); k++) {

		if (i > 0 && j > 0) {
			if ( (data[i - 1][j].right == tiles[k].left) && (data[i][j - 1].down == tiles[k].up) ) {
				candidates.push_back (tiles[k]);
			}
			continue;
		}

		if (i > 0) {
			if ( data[i - 1][j].right == tiles[k].left) {
				candidates.push_back (tiles[k]);
			}
			continue;
		}

		if (j > 0) {
			if (data[i][j - 1].down == tiles[k].up){
				candidates.push_back (tiles[k]);
			}
			continue;
		}

		//en 0,0
		candidates = tiles;
		return;
	}
}

void remove_tile (vector <Tile>& tiles, unsigned id) {
	for (vector<Tile>::iterator it = tiles.begin (); it != tiles.end (); it++) {
		if (it->id == id) {
			tiles.erase (it);
			return;
		}
	}
}

void backtracking(unsigned i, unsigned j){
	if(is_solution()){
		return;
	}
	else{
		vector<Tile> candidates;

		unsigned x, y = j;
		x = (i + 1) % 3;
		if (0 == x) y++;

		get_candidates(i, j, candidates);

		for(unsigned index = 0; index < candidates.size(); index++){
			data[i][j] = candidates[index];
			remove_tile (tiles, candidates[index].id);
			filled++;
			backtracking(x, y);
			filled--;
			tiles.push_back ( data[i][j] );
		}
	}
}


int main(){

	unsigned n_cases; cin >> n_cases;
	unsigned n_c = 1;

	for (unsigned k = 0; k < n_cases; k++) {
		filled = 0;
		first_solution = false;

		data.reserve(MAX_ROW);
		for(int i = 0; i < MAX_ROW; i++) {
			data[i].reserve(MAX_COL);
		}
		tiles.clear ();
	
		for (unsigned j = 0; j < 9; j++) {
			Tile t;
			cin >> t.up >> t.right >> t.down >> t.left;
			t.id = j;
			tiles.push_back (t);
		}

		backtracking (0,0);
		cout << "Case " << n_c << ": ";
		if (first_solution) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		if (k < n_cases - 1) cout << endl;
		n_c++;
	}
	return 0;
}

