#include <cstdio>
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
		
		vector<bool> processed;
		vector<bool> discovered;
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 
		bool finished;						// se utiliza como corte de la busqueda en profundidad

	public:
		Graph_w():nedges(0){}
		int start, end;
		void read();

		int dijkstra(int start);

};

int main(){
	
	int n_cases, dist;
	//cin >> n_cases;
	scanf("%d", &n_cases);
	
	for (unsigned i=0; i<n_cases; i++) {
		Graph_w g;	
		g.read();
		dist = g.dijkstra(g.start);
		
		printf("Case #%d: ", i+1);
		//cout << "Case #" << i+1 << ": ";
		
		if (dist == numeric_limits<int>::max()) {printf("unreachable\n");}//cout << "unreachable";}
		else { printf ("%d\n", dist); }//cout << dist;}
		
//		cout << endl;
	}

	return 0;
}

void Graph_w::read(){
	// initialize graph
	nedges = 0; 
	edges.clear();

	int n_nodes, n_edges, x, y; 
	
	scanf("%d%d%d%d", &n_nodes, &n_edges, &this->start, &this->end);

	//cin >> n_nodes >> n_edges >> this->start >> this->end;
	
	edges.resize(n_nodes);	
	
	for(int i = 0; i < n_edges; i++) {
		Edge e1, e2;
		
		scanf("%d%d%d", &x, &y, &e1.weight);
		
		//cin >> x >> y >> e.weight;
		
		e1.v = y;
		edges[x].push_back(e1); 
		
		++nedges;

  		//not directed
  		e2.v = x;
        e2.weight = e1.weight;
		edges[y].push_back(e2); 
		
	}		
}

int Graph_w::dijkstra(int start) {
	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0}
    ;
	
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
	return distance[this->end];
}


