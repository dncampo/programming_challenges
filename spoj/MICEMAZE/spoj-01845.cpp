/*
Title: Mice and Maze
Tags: graph, minimum distance, shortest path, dijkstra
URL: https://www.spoj.pl/problems/MICEMAZE/
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Description:
    + A Dijkstra search is performed for every node and the distance to the exit one is returned.
    * If it is smaller of equal to the time limit, that mouse is counted.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

struct Edge{
	int v;   		// neighbour vertex
	int weight; 	// of the edge
};

class Graph_w{
	private:
		vector<vector<Edge> > edges;  	// adyacency info
		int nedges;						   // number of edges
		int time;
		int exit;
		vector<int> parents;    // parent vector to print the resulting tree
		vector<int> distance;   // optimal distance between root vertex and any other


	public:
		Graph_w():nedges(0){}
		bool read(bool directed);
		int dijkstra(int start);
		void print();
		int exit_node() {return exit;}
		int ttime(){ return time;}
		int size(){ return edges.size();}
};

int main(){
	Graph_w g;
	g.read(true);
	int cnt = 0;
	
	for (int i=0; i < g.size(); i++){
		int time = g.dijkstra(i);
		if (time <= g.ttime())
			cnt++;
	}	
	cout << cnt << endl;		
	
	return 0;
}

bool Graph_w::read(bool directed){
    int n_nodes, n_edges, x, y, exit, time; 
    nedges = 0; 
	edges.clear();		
	cin >> n_nodes >> exit >> time >> n_edges;
	
	this->exit = exit - 1;
	this->time = time;	
	if (n_nodes == 0) 
		return false;
		
	edges.resize(n_nodes);		
	for(int i = 0; i < n_edges; i++) {
		Edge e;		
		cin >> x >> y >> e.weight;
		x--, y--;		
		e.v = y;
		edges[x].push_back(e); 		
		++nedges;
	}	
	return true;
}

int Graph_w::dijkstra(int start) {
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
	return distance[exit];
}
