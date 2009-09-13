/**
 * Title: The Shortest Path
 * URL: https://www.spoj.pl/problems/SHPATH/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ 
	
**/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <map>

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

		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 


	public:
		map<string,int> names_to_index;
		map<int,string> index_to_names;
	
		Graph_w():nedges(0){}
		bool read(bool directed);
		vector<int> dijkstra(int);
		void print();
};

int main(){
	int ncases;
	cin >> ncases;
	
	for (int a = 0; a < ncases; a++){
		map<string,int> res;
		Graph_w g;
		g.read(true);

		int queries;
		cin >> queries;
		
		for(int b = 0; b < queries; b++){
			string query_a, query_b;
			cin >> query_a >> query_b;
			
			string q = query_a + "-" + query_b;
			map<string,int>::iterator iter = res.find(q);
			if(iter == res.end()){
				q = query_b + "-" + query_a;
				if(iter == res.end()){
					
					
					int src, dest;
					vector<int> dist;
					src = g.names_to_index[query_a];
					dest = g.names_to_index[query_b];
					dist = g.dijkstra(src);
					
					for(unsigned k = 0; k < dist.size(); k++){
						int tmp = dist[k];
						res[g.index_to_names[k] + "-" + g.index_to_names[src]] = tmp;
						res[g.index_to_names[src] + "-" + g.index_to_names[k]] = tmp;
					}
					
					
//			cout << "worse case: ";
//					res[query_b + "-" + query_a] = dist;
//					res[query_a + "-" + query_b] = dist;
					cout << res[query_b + "-" + query_a] << endl;
				}
				else{
//			cout << "mid case: ";
					cout << res[q] << endl;
				}
			}
			else{
//			cout << "best case: ";
				cout << res[q] << endl;			
			}			
		}
	}
	return 0;
}

bool Graph_w::read(bool directed){
	nedges = 0; 
	edges.clear();	

	int ncities, nneighbours, src, dest;
	
	cin >> ncities;	
	if (ncities == 0) 
		return false;
		
	edges.resize(ncities);
	
	for(int i = 0; i < ncities; i++) {		
		string city_name;
		cin >> city_name;
		
		index_to_names[i] = city_name;
		names_to_index[city_name] = i;
		
		cin >> nneighbours;
		for (int j = 0; j < nneighbours; j++){
			src = i;
			Edge e;
			cin >> dest >> e.weight;
			dest--;			
			e.v = dest;
			edges[src].push_back(e);			
			++nedges;
		}
	}	
	return true;
}

vector<int> Graph_w::dijkstra(int start) {
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
	return distance;
}



