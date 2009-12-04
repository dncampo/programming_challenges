/**
 * Title: Longest path in a tree
 * URL: http://www.spoj.pl/problems/PT07Z/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se utiliza la herramienta de grafos, y se aplica la búsqueda Dijkstra un nodo hoja (nodo del cual
	su grado es 1) y se obtiene el árbol de expansión con dicho nodo (un nodo hoja) como raíz.
	
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
		int time;
		int exit;

	private:		
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 


	public:
		Graph_w():nedges(0){}

		bool read();

		int dijkstra();
};

int main(){

	Graph_w g;
	g.read();

	cout << g.dijkstra() << endl;
	
	return 0;
}

bool Graph_w::read(){
	edges.clear();
	
	int n_nodes, x, y;
	
	cin >> n_nodes;

	edges.resize(n_nodes);
	
	while(cin >> x >> y) {
		Edge e;
		x--, y--;
		
		e.v = y;
		e.weight = 1;
		edges[x].push_back(e);
		++nedges;

		e.v = x;
		edges[y].push_back(e); 

	}
	return true;
}

int Graph_w::dijkstra() {
	int start = 0;
	int max = 0;
	
	for(unsigned i = 0; i < edges.size(); i++){
		if(edges[i].size() == 1){ //una hoja en el arbol de expansión
			start = i;

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
			for(unsigned i = 0; i < distance.size(); i++){
			if((distance[i] > max) && distance[i] != numeric_limits<int>::max())
				max = distance[i];
			}
		}
	}
	return max;
}


