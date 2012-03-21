/**
 * Title: Pick up sticks
 * URL: http://uva.onlinejudge.org/external/116/11686.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se construye el grafo correspondiente a la configuración dada en la entrada y se realiza 
	un ordenamiento topológico.
	+ Usar scanf y printf en vez de cin y cout, puesto que son muy lentas.

**/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
	private:
		vector<vector<int> > edges;  	// informacion de adyacencia

	public:
		Graph(){}
		unsigned size () {return edges.size(); }
		bool read();
		bool topological_sort(vector<int> &sorted);

};

int main(){
	Graph g;
	while (g.read()) {

		vector <int> sorted (g.size());
		bool test = g.topological_sort(sorted);

		if (test) {
			for (unsigned i = 0; i < sorted.size(); i++) {
				printf("%d\n", sorted[i] + 1);
				//cout << sorted[i] + 1 << endl;
			}

		}
		else {
			//cout << "IMPOSSIBLE" << endl;
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

bool Graph::read(){
	// initialize graph
	edges.clear();

	int n_nodes, m, a, b;
	//cin >> n_nodes >> m;
	scanf ("%d%d", &n_nodes, &m);

	if (n_nodes == 0 && m == 0) return false;
	
	edges.resize(n_nodes);
	
	for(int i = 0; i < m; i++) {
		//cin >> a >> b;
		scanf ("%d%d", &a, &b);
		a--, b--;

		edges[a].push_back(b);
	}
	return true;
}


bool Graph::topological_sort(vector<int> &sorted){
	vector<int> in_degree(edges.size());
	queue<int> zero_in;

	int current, next;

	// Inicializamos el vector de grados entrantes
	in_degree.assign(edges.size(), 0);
	for(unsigned i = 0; i < edges.size(); i++){
		for(unsigned j = 0; j < edges[i].size(); j++){
			in_degree[ edges[i][j] ]++;
		}
	}

	for(unsigned i = 0; i < edges.size(); i++){
	   if (in_degree[i] == 0) 
	   	zero_in.push(i);
	}

	unsigned k = 0;
	while(!zero_in.empty()){
	   current = zero_in.front();
	   zero_in.pop();
		sorted[k++] = current;

	   for(unsigned i = 0; i < edges[current].size(); i++){
		   next = edges[current][i];
		   in_degree[next]--;
		   if(in_degree[next] == 0)
		   	zero_in.push(next);
	   }
	}

	if(k != edges.size()){
		sorted.clear();
		return false;
	}
	return true;
}
