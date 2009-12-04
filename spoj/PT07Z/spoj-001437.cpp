#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
	private:
		vector<vector<int> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo
	private:
		vector<bool> processed;
		vector<bool> discovered;
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		bool finished;						// se utiliza como corte de la búsqueda en profundidad

	public:
		vector<unsigned> leaves;
		Graph():nedges(0){}

		void read();
		void bfs(int start);
		 
		 unsigned get_largest_path (unsigned );
		 unsigned get_path_size(const unsigned , unsigned);
};


unsigned Graph::get_path_size(const unsigned start, unsigned end) {
	unsigned path_size = 0;
	unsigned actual = end;
	while (actual != start) {
		path_size++;
		actual = parents[actual];
	}
	return path_size;
}

unsigned Graph::get_largest_path (unsigned start) {

	bfs(start);
	
	unsigned max = 0, tmp;
	for (unsigned i = 0; i < leaves.size (); i++) {
		for (unsigned j = i + 1; j < leaves.size (); j++) {
			tmp = get_path_size (i, j);
			if (tmp > max) max = tmp;
		}
	}
	return max;
/*

	unsigned largest_path = 0;
	bfs (start);
	for (unsigned i = 0; i < edges.size (); i++) {
		unsigned tmp = get_path_size (start, i);
		if (tmp > largest_path) largest_path = tmp;
	}
	return largest_path;*/
}


int main(){
	Graph g;
	g.read();

	unsigned max_path = 0;
/*x	for (unsigned i = 0; i < g.leaves.size(); i++) {
		unsigned tmp = g.get_largest_path(g.leaves[i]);
		if (tmp > max_path) {
			max_path = tmp;
		}
	}*/
	max_path = g.get_largest_path(g.leaves[0]);
	cout << max_path << endl;
	return 0;
}

void Graph::read(){
	// initialize graph
	edges.clear();
	int n_nodes, x, y;

	cin >> n_nodes;
	edges.resize(n_nodes);
	
	vector <unsigned> degree(n_nodes, 0);
	while (cin >> x >> y){
		x--, y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
	for (unsigned i = 0; i < degree.size(); i++) {
			if (1 == degree[i]) leaves.push_back(i);
	}
}


// BREADTH FIRST SEARCH
void Graph::bfs(int start){
   queue<int> q;
   // inicializar datos	
	processed.assign( edges.size(), false);
	discovered.assign( edges.size(), false);
	parents.assign(edges.size(), -1);

	q.push(start);
   discovered[start] = true; 		// marcar como descubierto

	while (!q.empty()) { 			// mientras la cola no este vacia
		int v = q.front();     		// obtener un elemento de la cola
		q.pop();
      processed[v] = true; 		// marcar como procesado 

		for (unsigned i = 0; i < edges[v].size(); i++) {
			if(!discovered[edges[v][i]]) {
				q.push(edges[v][i]);
				discovered[edges[v][i]] = true;
				parents[edges[v][i]] = v;
			}
		}
	}
}

