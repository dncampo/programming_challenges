/**
   + Se va calculando el coste actual a medida que se carga el grafo (es el peso de cada arco).
	+ Se aplica prim para obtener el MST y se lo modifica para obtener el nuevo coste.
	+ Se resta el coste inicial (actual_cost) menos el optimized cost (despues de aplicar prim)

**/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge{
	int v;   		// nodo vecino
	int weight; 	// peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia

	private:
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 
		bool finished;						// se utiliza como corte de la busqueda en profundidad
		unsigned optimized_cost;		// coste despues de aplicar prim
		unsigned actual_cost;			// coste actual..

	public:
		Graph_w(){}
		bool read();
		unsigned prim(int start);

};

int main(){
	Graph_w g;
	while (g.read()) {
		cout << g.prim(0) << endl;
	}
	return 0;
}

bool Graph_w::read(){
	// initialize graph
	optimized_cost = 0;
	actual_cost = 0;
	edges.clear();

	int m, n, x, y;

	cin >> m >> n;
	if (0 == m + n) return false;
	
	edges.resize(m);
	
	for(int i = 0; i < n; i++) {
		Edge e;
		
		cin >> x >> y >> e.weight;
		actual_cost += e.weight;

		e.v = y;
		edges[x].push_back(e);
		e.v = x;
		edges[y].push_back(e);
	}
	return true;
}


unsigned Graph_w::prim(int start) {
	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0};
	
	parents.assign(edges.size(), -1);
	distance.assign(edges.size(),  numeric_limits<int>::max());
	distance[start] = 0;

			
	while(!in_tree[current.v]){
		in_tree[current.v] = true;
		if (-1 != parents[current.v]) optimized_cost += current.weight;
		
		for(unsigned i = 0; i < edges[current.v].size(); i++) {
			Edge next = {edges[current.v][i].v, edges[current.v][i].weight};

			if (distance[next.v] > next.weight && in_tree[next.v] == false) {
				distance[next.v] = next.weight;
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
	return actual_cost - optimized_cost;
}
