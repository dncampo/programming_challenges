/**
 * Title: Mice and Maze
 * URL: https://www.spoj.pl/problems/MICEMAZE/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se utiliza la herramienta de grafos, y se aplica la búsqueda Dijkstra con cada una de las celdas
	(nodes). Si el peso acumulado de cada celda a la celda destino es <= al tiempo dado, se incrementa
	un contador.
	
**/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <cstring>

using namespace std;

struct Edge{
	int v;   		// nodo vecino
	int weight; 	// peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo
		int time;
		int exit;

	private:		
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 


	public:
		Graph_w():nedges(0){}

		bool read(bool directed);

		int dijkstra();
		void print();

};

int main(){
	
	int n_cases;
	cin >> n_cases;
	for(int i = 0; i < n_cases; i++){
		Graph_w g;
		if(!g.read(true)){
			cout << "Maximum rope length is 0." << endl;

		}
		else{
			cout << "Maximum rope length is " << g.dijkstra() << "." << endl;
		}

	}
	return 0;
}

bool Graph_w::read(bool directed){
	nedges = 0; 
	edges.clear();	

	int x,y;
	
	cin >> x >> y;
	
	int matrix[y+2][x+2];
	memset(matrix,-1,(y+2)*(x+2));
		
	int nodes = 0;
	for(int i = 0; i < y; i++) {
		string line;
		
		cin >> line;
		for(unsigned j = 0; j < line.size(); j++){
			if(line[j] == '.'){
				matrix[i+1][j+1] = nodes;
				nodes++;
			}
			else
				matrix[i+1][j+1] = -1;
		}	
		
	}
	
	edges.resize(nodes);
	
	for(int i = 1; i < y + 1; i++){
		for(int j = 1 ; j < x + 1; j++){
			//cout << matrix[i][j] << " ";
			
			if(matrix[i][j] != -1){
				if(matrix[i-1][j] != -1){
					Edge e;
					e.v = matrix[i-1][j];
					e.weight = 1;
					edges[matrix[i][j]].push_back(e);
					
					e.v = matrix[i][j];
					edges[matrix[i-1][j]].push_back(e);
				}
				if(matrix[i][j+1] != -1){
					Edge e;
					e.v = matrix[i][j+1];
					e.weight = 1;
					edges[matrix[i][j]].push_back(e);
					
					e.v = matrix[i][j];
					edges[matrix[i][j+1]].push_back(e);
				}
			}
		}
		

	}
	
	if(edges.size() == 0) return false;
	return true;
}

int Graph_w::dijkstra() {
	int start = 0;
	
	for(unsigned i = 0; i < edges.size(); i++){
		if(edges[i].size() == 1){ //una hoja en el arbol de expansión
			start = i;
			break;			
		}
	}

	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0};
	
	parents.assign(edges.size(), -1);        
	distance.assign(edges.size(),  numeric_limits<int>::max());
	distance[start] = 0;
			
	while(!in_tree[current.v]){
		in_tree[current.v] = true;
		
		for(unsigned i = 0; i < edges[current.v].size(); i++) {
			Edge next = {edges[current.v][i].v, edges[current.v][i].weight};			

			if (distance[next.v] > (distance[current.v] + next.weight)) {
				distance[next.v] = distance[current.v] + next.weight;
				parents[next.v] = current.v;
			}
		}

		current.v = 0;
		current.weight = numeric_limits<int>::max();

		for(unsigned i = 1; i < edges.size(); i++){
			if(!in_tree[i] && current.weight > distance[i]){
				current.weight = distance[i];
				current.v 	   = i;
			}
		}
	}
	int max = 0;
	for(unsigned i = 0; i < distance.size(); i++){
		if(distance[i] > max)
			max = distance[i];
	}
	return max;
}

void Graph_w::print(){
	for (unsigned i = 0; i < edges.size(); i++) {
		cout << i << ": ";

		for (unsigned j = 0; j < edges[i].size(); j++)
			cout << edges[i][j].v << "(" << edges[i][j].weight << ") ";

		cout << endl;
	}
}



