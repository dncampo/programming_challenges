/**
 * Title: Freckles
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/100/10034.html
 * Resources of interest:
	+ http://en.wikipedia.org/wiki/Euclidean_minimum_spanning_tree
	+ http://en.wikipedia.org/wiki/Prim%27s_algorithm
 * Solver group: David-Yeyo-Leo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se construye el grafo completo con los n vertices y todos los arcos como las distancias entre los
	vértices.
	+ Se calcula el Euclidean minimum spanning tree con el algoritmo de Prim, y se calcula el peso de
	recorrer dicho árbol.
	
**/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <limits>
#include <cmath>

using namespace std;

struct Edge{
	int v;   		// nodo vecino
	float weight; 	// peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia
		vector<float> x; 					//coord x del i-esimo nodo
		vector<float> y;					//coord y del i-esimo nodo
		int nedges;						   // numero de arcos en el grafo

	private:		
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<float> distance;         // distancia optima al inicio despues de aplicar dijkstra 

	public:
		Graph_w():nedges(0){}
		bool read(bool directed);
		void make_edges();
		float dijkstra(int start);
		stack<int> prim(int start);
		float dist(int,int);
};

int main(){
	int cases;
	cin >> cases;
	
	for (int i = 0; i < cases; i++){
		Graph_w g;
		g.read(true);		
		
		stack<int> s = g.prim(0); //Obtener el minimum spanning tree
		
		//sumamos los costos del camino del árbol
		float sum = 0.0f;
		for(int k = (s.size() - 1); k >= 0; k--){
			int n1 = s.top();
			s.pop();
			sum += g.dist(k,n1);
		}
		
		cout << fixed;
		cout.precision(2);
		cout << sum << endl; // la solución
		if(i < cases - 1)
			cout << endl;		
	}
	return 0;
}

//obtengo la distancia entre el nodo n1 y n2
float Graph_w::dist(int n1, int n2){
	int i = 0;
	while(edges[n1][i].v != n2) i++;
	return edges[n1][i].weight;	
}

bool Graph_w::read(bool directed){
	nedges = 0; 
	edges.clear();	

	int n_nodes;
	
	cin >> n_nodes;
	
	if (n_nodes == 0) 
		return false;
		
	edges.resize(n_nodes);
	x.resize(n_nodes);
	y.resize(n_nodes);
	
	for(int i = 0; i < n_nodes; i++) {	
		cin >> x[i] >> y[i];	
	}	
	make_edges(); //already directed :P
	
	return true;
}

void Graph_w::make_edges(){
	for(unsigned i = 0; i < edges.size(); i++){		
		for(unsigned j = 0; j < edges.size(); j++){
			if(i==j) continue;
			float dist = (float)sqrt(pow(x[i] - x[j],2.0f) + pow(y[i] - y[j], 2.0f));
			Edge e;
			e.v = j;
			e.weight = dist;
			edges[i].push_back(e);
			++nedges;
		}
	}
}

//Construyo el minimum spanning tree
stack<int> Graph_w::prim(int start) {
	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0};
	
	parents.assign(edges.size(), -1);        
	distance.assign(edges.size(),  numeric_limits<float>::max());
	distance[start] = 0;
			
	while(!in_tree[current.v]){
		in_tree[current.v] = true;
		
		for(unsigned i = 0; i < edges[current.v].size(); i++) {
			Edge next = {edges[current.v][i].v, edges[current.v][i].weight};			

			if ((distance[next.v] > next.weight) && in_tree[next.v]==false){
				distance[next.v] = next.weight;
				parents[next.v] = current.v;
			}
		}

		current.v = 0;
		current.weight = numeric_limits<float>::max();

		for(unsigned i = 1; i < edges.size(); i++){
			if(!in_tree[i] && current.weight > distance[i]){
				current.weight = distance[i];
				current.v 	   = i;
			}
		}
	}
	
	// Armo el camino de regreso para devolver el path solución
	stack<int> path;	
	for(unsigned i=0; i < parents.size(); i++){
		path.push(parents[i]);
	}
	return path;
}

