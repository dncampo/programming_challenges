/**
 * Title: The Tourist Guide
 * URL: http://uva.onlinejudge.org/external/100/10099.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
  Para implementar la solución se modifica el algoritmo de recorrido por anchura de
  un grafo sin peso.
  Se utiliza un vector de mejor flujo para cada nodo.
  El algoritmo en forma general consiste en: para cada nodo realizar una expansión como el
  recorrido por anchura y actualizar el mejor flujo. 
  Una particularidad que hay que tener en cuenta que si el nodo ya se recorrio y se encuentra
  una ruta que tenga mejor flujo, se debe volver a iterar sobre ese nodo ya que los mejores
  flujos a partir de ese nodo pueden cambiar.
**/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;

struct Edge{
	int v;  // nodo vecino
	int w;  // peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo

		vector<int> best_flow;
      int start, destination, tourists;
	public:
		Graph_w(){}
      bool read(bool directed);
      int bfs();
};

int main(){
   int count = 1;
	Graph_w g;
	
	while(g.read(false)){
	   cout << "Scenario #" << count++ << endl
	        << "Minimum Number of Trips = " << g.bfs() 
	        << endl << endl;
	}
     
	return 0;
}

bool Graph_w::read(bool directed){
	edges.clear();

	int n_nodes, n_edges, x, y; 

	cin >> n_nodes >> n_edges;
	
	if(n_nodes == 0 && n_edges == 0) return false;
	
	edges.resize(n_nodes+1);	
		
	for(int i = 0; i < n_edges; i++) {
		Edge e;

		cin >> x >> y >> e.w;

		e.v = y;
		edges[x].push_back(e); 
		
		++nedges;

  		if(directed == false){
  			e.v = x;
			edges[y].push_back(e); 
		}
	}
	
	cin >> start >> destination >> tourists;

	best_flow.assign(n_nodes+1, 0);
	
	return true;
}

int Graph_w::bfs(){
	vector<bool> processed(edges.size(), false);
	vector<bool> discovered(edges.size(), false);
   queue<int> q;
   	                         
	q.push(start);   		
   discovered[start] = true; 		// marcar como descubierto
   best_flow[start] = numeric_limits<int>::max();
   
	while (!q.empty()) { 			// mientras la cola no este vacia
		int v = q.front();     		// obtener un elemento de la cola
		q.pop();
      processed[v] = true; 		// marcar como procesado 
                
		for(unsigned i = 0; i < edges[v].size(); i++) {
			if(!discovered[edges[v][i].v]) {
				q.push(edges[v][i].v);
				discovered[edges[v][i].v] = true;
         }
         
         int m = min(best_flow[v], edges[v][i].w);

         if(best_flow[edges[v][i].v] < m){
            best_flow[edges[v][i].v] = m;
            q.push(edges[v][i].v);
         }
      }
	}

	return (int)ceil((1.0f*tourists) / (best_flow[destination]-1));
}

