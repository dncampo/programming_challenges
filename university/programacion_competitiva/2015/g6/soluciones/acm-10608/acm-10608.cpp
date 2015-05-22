/**
 * Title: Friends
 * URL: http://online-judge.uva.es/p/v106/10608.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se carga el grafo en una lista de listas de adyacencia.
	+ Se realiza una modificación a la función que devuelve el número de componentes conectadas 
	para que devuelva la cantidad que tiene la componente con más nodes conectados.

**/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	private:
		vector<vector<int> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo
		vector<bool> processed;
		vector<bool> discovered;

	public:
		Graph():nedges(0){}
		void read();
		unsigned max_connected_component();
};

int main(){
	unsigned n_cases;
	scanf ("%u", &n_cases);
	for (unsigned i = 0; i < n_cases; i++) {
		Graph g;
		g.read();
		printf ("%u\n", g.max_connected_component());
	}
	return 0;
}

void Graph::read(){
	// initialize graph
	nedges = 0;
	edges.clear();

	int n_nodes, n_edges, x, y; 

	//cin >> n_nodes >> n_edges;
	scanf ("%d%d", &n_nodes, &n_edges);
	
	edges.resize(n_nodes);
	
	for(int i = 0; i < n_edges; i++) {
		//cin >> x >> y;
		scanf ("%d%d", &x, &y);
		x--, y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
		++nedges;
	}
}

unsigned Graph::max_connected_component (){
	unsigned max_connected = 0;

   discovered.assign(edges.size(), false);

	for(unsigned i = 0; i < discovered.size(); i++){
		unsigned tmp_conn = 0;
		if(discovered[i]) continue;

		// BFS
	   queue<int> q;
		q.push(i); 
		discovered[i] = true; 		// marcar como descubierto
		tmp_conn++;

		while (!q.empty()) { 			// mientras la cola no este vacia
			int v = q.front();     		// obtener un elemento de la cola
			q.pop();

			for (unsigned i = 0; i < edges[v].size(); i++) {
				if(!discovered[edges[v][i]]) {
					q.push(edges[v][i]);
					discovered[edges[v][i]] = true;
					tmp_conn++;
		      }
			}
		}
		if (tmp_conn > max_connected) max_connected = tmp_conn;
	}
	return max_connected;
}
