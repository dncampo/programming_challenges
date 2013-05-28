#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	private:		
		int nedges;	
		vector<int> parents;
		vector<vector<int> > edges;
		bool finished;						

	public:
		
		Graph():nedges(0){}		

		void read(bool directed);
		void bfs(int start);
		void process_node(int v);
		void process_edge(int x, int y);
		int number_nodes() { return edges.size(); }

		bool valid_edge(int node, int edge);
		void print_path(int start, int end);
		void dfs_2(int , vector<bool>&, vector<bool>&, vector<int>&);
};

int main(){
	int ncases;
	cin >> ncases;
	
	for(int i = 0; i < ncases; i++){
		Graph g;
		g.read(true);
		int x,y;
	
		cout << "graph " << i + 1 << endl;
		cin >> x >> y;
		while((x != 0) || (y != 0)){
			if(0 == y){
				// preparamos las variables que usara dfs
				vector<bool> processed(g.number_nodes(), false);
				vector<bool> discovered(g.number_nodes(), false);
				vector<int> parents(g.number_nodes(), -1);
				
				g.dfs_2(x-1, processed, discovered, parents);
			}
			else
				g.bfs(x-1);			
			cout << endl;
			cin >> x >> y;
		}		
	}
	return 0;
}

void Graph::read(bool directed){
	nedges = 0; 
	edges.clear();
	int n_nodes ,n, adj; 
	cin >> n_nodes;	
	edges.resize(n_nodes);	
	
	for(int i = 0; i < n_nodes; i++) {
		cin >> n >> adj;
		for(int j = 0; j < adj; j++){
			int n_adj;
			cin >> n_adj;
			n_adj--;
			edges[n-1].push_back(n_adj);
			++nedges;
			if(directed == false) 
				edges[n_adj].push_back(n-1); 
		}
	} 	
}

void Graph::bfs(int start){
	vector<bool> processed;
	vector<bool> discovered;
   queue<int> q;
   
   // inicializar datos	
	processed.assign( edges.size(), false);
	discovered.assign( edges.size(), false);
	parents.assign(edges.size(), -1);
	                         
	q.push(start);   		
   discovered[start] = true; 		// marcar como descubierto
        
	while (!q.empty()) { 			// mientras la cola no este vacia
		int v = q.front();     		// obtener un elemento de la cola
		q.pop();
      process_node(v);   			// procesar el vertice
      processed[v] = true; 		// marcar como procesado 
                
		for (unsigned i = 0; i < edges[v].size(); i++) {
			if( valid_edge(v, edges[v][i]) ){
				if(!discovered[edges[v][i]]) {
					q.push(edges[v][i]);
					discovered[edges[v][i]] = true;
               parents[edges[v][i]] = v;
            }
         }
		}
	}
}

void Graph::process_node(int v){
	cout << v + 1 << " ";
}


bool Graph::valid_edge(int node, int edge){
	return true;
}



void Graph::dfs_2(int start, vector<bool>& processed, vector<bool>& discovered, vector<int>& parent ){
//	if (finished) return; 			// allow for search termination

	discovered[start] = true;
	process_node(start);
	
	for (unsigned i = 0; i < edges[start].size(); i++) {
		int successor = edges[start][i];		// successor vertex
		if (valid_edge(start, edges[start][i])) {
			if (discovered[successor] == false) {
				parent[successor] = start;
				dfs_2(successor, processed, discovered, parent);
			} 
//			else
//				if (processed[successor] == false)
//					process_edge(start,successor);
		}
//		if (finished) return;
	}
	processed[start] = true;
	return;
}


