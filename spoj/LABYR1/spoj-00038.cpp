/**
 * Title: Labyrinth
 * URL: http://www.spoj.pl/problems/LABYR1/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ 
	
**/

//#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

char c_tmp[255];
const int INF = numeric_limits<int>::max();


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

		bool read(bool directed);

		int dijkstra();
		void print();

};

int main(){
	
	int n_cases;
	scanf ("%d",&n_cases);

	for(int i = 0; i < n_cases; i++){
		Graph_w g;
		if(!g.read(true)){
			printf("Maximum rope length is 0.\n");

		}
		else{
			int res = g.dijkstra();
			printf("Maximum rope length is %d.\n",res);
		}
		
/*		cout << endl;
		cout << "print" << endl;
		g.print();*/
		
	}
	return 0;
}

bool Graph_w::read(bool directed){
	nedges = 0; 
	edges.clear();	

	int x,y;
	
	scanf("%d %d",&x,&y);
	
	int matrix[y][x];
	memset(matrix,-1,y*x);

	
	int nodes = 0;

	edges.resize(x*y);
	
	for(int i = 0; i < y; i++) {
		scanf("%s",&c_tmp);
		for(int j = 0; j < x; j++){
			nodes++;
			matrix[i][j] = c_tmp[j];
			
			if(c_tmp[j] == '.'){
				if(j > 0){
					if(matrix[i][j-1] == '.'){
					Edge e;
					e.v = nodes - 1;
					e.weight = 1;
//					edges[matrix[i][j]].push_back(e);
					edges[nodes].push_back(e);
					
		/*			e.v = nodes;
					edges[nodes-1].push_back(e);	*/
				
					}
				}
				if(i > 0){
					if(matrix[i-1][j] == '.'){
					Edge e;
					e.v = nodes - x;
					e.weight = 1;
//					edges[matrix[i][j]].push_back(e);
					edges[nodes].push_back(e);
					
				/*	e.v = nodes;
					edges[nodes-x].push_back(e);	*/
				
					}
				}
			}
		}	
	}

	if(edges.size() == 0) return false;
	return true;
}

int Graph_w::dijkstra() {
	int start = 0;
	
	for(unsigned i = 0; i < edges.size(); i++){
		if(edges[i].size() > 0){ //una hoja en el arbol de expansión
			start = i;
			break;			
		}
	}

	vector<bool> in_tree(edges.size(), false); 
	Edge current = {start, 0};
	
	parents.assign(edges.size(), -1);        
	distance.assign(edges.size(),  INF);
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
		current.weight = INF;

		for(unsigned i = 1; i < edges.size(); i++){
			if(!in_tree[i] && current.weight > distance[i]){
				current.weight = distance[i];
				current.v 	   = i;
			}
		}
	}
	int max = 0;
	for(unsigned i = 0; i < distance.size(); i++){
		if((distance[i] != INF) && (distance[i] > max) )
			max = distance[i];
	}
	return max;
}

void Graph_w::print(){
	for (unsigned i = 0; i < edges.size(); i++) {
		printf("%d: ",i);
		for (unsigned j = 0; j < edges[i].size(); j++)
			printf("%d(%d) ",edges[i][j].v,edges[i][j].weight);			
//		cout << endl;
		printf("\n");
	}
}



