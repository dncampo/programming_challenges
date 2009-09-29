#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge{
	int v;   		// nodo vecino
	int weight; 	// peso
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// informacion de adyacencia
		int nedges;						   // numero de arcos en el grafo

	private:
		vector<bool> processed;
		vector<bool> discovered;
		vector<vector<int> > parents;				// se utiliza para imprimir alguna solucion de la busqueda
		vector<int> distance;         // distancia optima al inicio despues de aplicar dijkstra 
		bool finished;						// se utiliza como corte de la búsqueda en profundidad

	public:
		Graph_w():nedges(0){}
		Graph_w (const Graph_w& g){
			this->nedges  = g.nedges;
			
			this->edges.resize(g.edges.size());
			for(unsigned i = 0; i < g.edges.size(); i++){
				this->edges[i] = g.edges[i];
			}
			
			this->parents.resize(g.parents.size());
			for(unsigned i = 0; i < g.parents.size(); i++){
				this->parents[i] = g.parents[i];
			}
		
			this->distance = g.distance;
		}

		/*
		 * Lee e inicializa el grafo. El grafo puede ser dirigido 
		 * o no de acuerdo al parametro directed 
		 */ bool read(bool directed);

		void dijkstra(int start);
		void print();
		void delete_path(const vector<int> &, int&);
		int last_node();
		bool check_path(int&);
		void get_alternatives(vector<vector<int> > &);
		void fill(vector<vector<int> > & t, int index);		
};

int main(){
	Graph_w g;
		
	while (g.read(false)){
		g.dijkstra(0);
		int seconds = 0;
		vector<vector<int> > alternatives;
		g.get_alternatives(alternatives);
/*		cout << "alternatives" << endl;
		
		for(int i = 0; i < alternatives.size(); i++){
			cout << "alt: " <<i << endl;
			for(int j = 0; j < alternatives[i].size(); j++){
				cout << " " << alternatives[i][j];
			}
			cout << endl;
		} */
		bool back_to_jail = true;
		
		for(unsigned i = 0; i < alternatives.size(); i++){
			Graph_w tmp(g); 
		//	cout << "copia exitosa: " << i << endl;
			//tmp.print();

			tmp.delete_path(alternatives[i], seconds);
			//cout << "delete ok" << endl;
			tmp.dijkstra(0);
			
			if(tmp.check_path(seconds)){
				back_to_jail = false;
				break;
			}
			
			seconds =  0;
		}
		
		if(back_to_jail) {
			cout << "Back to jail" << endl;		
		} else {
			cout << seconds << endl;
		}	
	}

	return 0;
}

bool Graph_w::read(bool directed){

	// initialize graph
	nedges = 0; 
	edges.clear();	

	int n_nodes, n_edges, x, y; 
	
	cin >> n_nodes;
	
	if (n_nodes == 0) return false;
		
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
	return true;
}

void Graph_w::dijkstra(int start) {
	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0};
	
	parents.clear();
	parents.resize(edges.size());        
	distance.assign(edges.size(),  numeric_limits<int>::max());
	distance[start] = 0;
			
	while(!in_tree[current.v]){
		in_tree[current.v] = true;
		
		for(unsigned i = 0; i < edges[current.v].size(); i++) {
			Edge next = {edges[current.v][i].v, edges[current.v][i].weight};			

			if (distance[next.v] >= (distance[current.v] + next.weight)) {
				distance[next.v] = distance[current.v] + next.weight;
				
				if(parents[next.v].size() == 0 || distance[next.v] == (distance[current.v] + next.weight)){
					parents[next.v].push_back(current.v);
				}
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
}


void Graph_w::print(){
	for (unsigned i = 0; i < edges.size(); i++) {
		cout << i << ": ";

		for (unsigned j = 0; j < edges[i].size(); j++)
			cout << edges[i][j].v << "(" << edges[i][j].weight << ")  ";

		cout << endl;
	}
}


void Graph_w::delete_path(const vector<int >& p, int &seconds){
	seconds = distance[edges.size() - 1];

	for(unsigned i = 0; i < p.size()-1; i++){
		vector<Edge>::iterator it = edges[p[i]].begin();
		while(it->v != p[i+1]) it++;
		edges[p[i]].erase(it);
		
		it = edges[p[i+1]].begin();
		while(it->v != p[i]) it++;
		edges[p[i+1]].erase(it);
	}	
}

int Graph_w::last_node(){
	return edges.size() - 1;
}

bool Graph_w::check_path(int& seconds){
	int node_tmp = edges.size() - 1;
	seconds += distance[edges.size() - 1];
	
	while(parents[node_tmp].size() > 0){		
		node_tmp = parents[node_tmp][0];
	}
	
	return node_tmp == 0;
}

void Graph_w::get_alternatives(vector<vector<int> > & t){
/*	for(int i = 0; i < parents.size(); i++){
		cout << i<< " :" ;
		for(int j = 0; j < parents[i].size(); j++){
			cout << parents[i][j] << " ";
		}
		cout << endl;	
	}*/
	int i = edges.size() - 1;
	
	vector<int> tmp;
	tmp.push_back(i);
	t.push_back(tmp);
	
	fill(t, i);	
}

void Graph_w::fill(vector<vector<int> > & t, int index){
	if(index == 0) return ;
	
	t[t.size()-1].insert(t[t.size()-1].begin(), 0);
	vector<int> tmp = t[t.size()-1];

	for(unsigned i = 0; i < parents[index].size(); i++){
		if(i > 0)
			t.push_back(t[t.size()-1]);
			
		tmp[0] = parents[index][i];
		t[t.size()-1] = tmp;
		fill(t, parents[index][i]);
	}
}
