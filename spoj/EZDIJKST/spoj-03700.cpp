/**
 * Title: Easy Dijkstra Problem
 * URL: http://www.spoj.pl/problems/EZDIJKST/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se utiliza la herramienta de grafos, y se aplica la búsqueda con Dijkstra empezando por el nodo A

**/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

struct Edge{
	int v;   		// nodo vecino
	int weight; 	// peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo
		int src;
		int dest;

	private:		
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 


	public:
		Graph_w():nedges(0){}

		bool read(bool directed);

		int dijkstra(int start);
		void print();
		int last_node();
		int source(){ return src;}
};

int main(){
	int cases;
	
	cin >> cases;
	for (int i = 0; i < cases; i ++){
		Graph_w g;
		g.read(true);
		
		int dist = g.dijkstra(g.source());
		
		if (dist == numeric_limits<int>::max())
			cout << "NO" << endl;
		else
			cout << dist << endl;		
	}
	return 0;
}

bool Graph_w::read(bool directed){
	nedges = 0; 
	edges.clear();	

	int n_nodes, n_edges, x, y; 
	
	cin >> n_nodes;
	if (n_nodes == 0) 
		return false;
		
	cin >> n_edges;
	
	edges.resize(n_nodes);	
	
	for(int i = 0; i < n_edges; i++) {
		Edge e;
		
		cin >> x >> y >> e.weight;
		x--, y--;
		
		e.v = y;
		edges[x].push_back(e); 
		
		++nedges;

  		if(directed == false){ // tener en cuenta si es un arco al mismo nodo, se puede preguntar x != y !
  			if(x != y){
  				e.v = x;
				edges[y].push_back(e); 
			}
		}
	}
	cin >> src >> dest;
	src--;
	dest--;
	return true;
}

int Graph_w::dijkstra(int start) {
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
	return distance[dest];
}

