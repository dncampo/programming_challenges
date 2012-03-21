/**
 * Title: Bicoloring
 * URL: http://uva.onlinejudge.org/external/100/10004.html
 * Solver group: Yeyo-Leo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	Se utiliza una version modificada del BFS, intercambiando los
	dos colores (-1 y 1) en cada expansion de un nodo.
	Aclaración: un nodo que tiene color 0, significa que todavía 
	no se expandio (no se coloreo).
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	private:
		vector<vector<int> > edges;  	// informacion de adyacencia

	public:
		Graph(){}

		/*
		 * Lee e inicializa el grafo. El grafo puede ser dirigido 
		 * o no de acuerdo al parametro directed 
		 */ bool read();

		/*
		 * Busqueda en amplitud
		 */ bool bfs(int start);

		/*
		 * Decidir si un arco es válido
		 * Para la busqueda dfs, modificar finished segun el problema
		 */ bool valid_edge(int node, int edge);
		
		void print();
};

int main(){
	Graph g;
	
	while(g.read()){
		if(g.bfs(0))
			cout << "BICOLORABLE." << endl;		
		else
			cout << "NOT BICOLORABLE." << endl;		
	}
	
	return 0;
}

bool Graph::read(){
	// initialize graph
	edges.clear();

	int n_nodes, n_edges, x, y; 

	cin >> n_nodes;
	if(n_nodes == 0)
		return false;
		
	cin >> n_edges;
	edges.resize(n_nodes);	
	
	for(int i = 0; i < n_edges; i++) {
		cin >> x >> y;

		edges[x].push_back(y); 
		edges[y].push_back(x); 
	}
	
	return true;
}

// BREADTH FIRST SEARCH
bool Graph::bfs(int start){
	vector<int> painted;
   queue<int> q;
   int color = -1;
   
   // inicializar datos	
	painted.assign( edges.size(), 0);
	                         
	q.push(start);   		
   painted[start] = color;
   
	while(!q.empty()) { 				// mientras la cola no este vacia
		int v = q.front();     		// obtener un elemento de la cola
		color = (-1) * painted[v];
		q.pop();

		for(unsigned i = 0; i < edges[v].size(); i++){
			if( valid_edge(painted[v], painted[ edges[v][i] ]) ){
				if(painted[ edges[v][i] ] == 0){
					q.push(edges[v][i]);
					painted[edges[v][i]] = color;
            }
         }
         else{
         	return false;
         }
		}
	}
	
	return true;
}

bool Graph::valid_edge(int node_color, int edge_color){
	return node_color != edge_color;
}

