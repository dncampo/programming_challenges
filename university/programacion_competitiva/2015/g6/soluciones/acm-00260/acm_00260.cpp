#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph{
	private:
		unsigned N;
		vector<string> game;
		vector<vector<int> > edges;  	// informacion de adyacencia
		vector<bool> level; //info de niveles visitados
		
		vector<bool> processed;
		vector<bool> discovered;
		vector<int> parents;				// se utiliza para imprimir alguna solucion de la busqueda
		bool finished;						// se utiliza como corte de la búsqueda en profundidad
		
		vector<unsigned> neighbours(int, int);

	public:
		Graph(){}
		
		bool all_levels();
		void read(unsigned size);		
		void print();

		void dfs(int start);	 
		void bfs(int start);
		void process_node(int v);
		void process_edge(int x, int y);
		bool valid_edge(int node, int edge);
		void print_path(int start, int end);
	
};


bool Graph::all_levels() {
	for (unsigned i=0; i<N; i++) {
		if (level[i] == false) return false;
	}
	return true;
}

vector<unsigned> Graph::neighbours(int i, int j) {
	vector<unsigned> ret;
	
	if (i-1>0 && j-1>0 && 'b' == game[i-1][j-1]) ret.push_back((i-1)*N + (j-1));
	if (i-1>0          && 'b' == game[i-1][j]) ret.push_back((i-1)*N + j);
	if (         j-1>0 && 'b' == game[i][j-1]) ret.push_back(i*N + (j-1));
	//ret.push_back(i*N + j);
	if (         j+1<N && 'b' == game[i][j+1]) ret.push_back(i*N + (j+1));
	if (i+1<N          && 'b' == game[i+1][j]) ret.push_back(((i+1)*N + j));
	if (i+1<N && j+1<N && 'b' == game[i+1][j+1]) ret.push_back((i+1)*N + (j+1));
	
	return ret;
}

void Graph::read(unsigned size){
	// initialize graph
	N = size;

	edges.clear();
	game.clear();
	
	game.resize(N);
	edges.resize(N*N);	
	
	for(int i = 0; i < N; i++) {
		cin >> game[i];
	}

	
	for(unsigned i=0; i<N; i++) {
		for(unsigned j=0; j<N; j++) {
			if ('b' == game[i][j]) {
				vector<unsigned> nei = neighbours(i,j);
				
				for (unsigned k=0; k<nei.size(); k++) {
					edges[i*N + j].push_back(nei[k]);
					//edges[k].push_back(nei[i*N + j]);
				}
			}
		}		
	}

}


void Graph::process_node(int v){
	//cout << "node: " << v << endl;
	level[v/N] = true;	
}

void Graph::process_edge(int x, int y){
	//cout << "processed edge (" << x << ", " << y << ")" << endl;
}

bool Graph::valid_edge(int node, int edge){	
	return true;
	//return node==edge;
}

void Graph::print_path(int start, int end){
	if( start == end || end == -1){
		if(end == -1) 
			cout << "error ";
			
		cout << endl << start;
	} else {
		print_path(start, parents[end]);
		cout << " " << end; 
  }
}

// BREADTH FIRST SEARCH
void Graph::bfs(int start){
   queue<int> q;
   
   	level = vector<bool> (N, false);
	
	if (game[0][start] != 'b') return;
   
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
            if (!processed[edges[v][i]])
	            process_edge(v, edges[v][i]);
         }
		}
	}
}


// DEPTH FIRST SEARCH
void Graph::dfs(int start){
	stack<int> s;
	finished = false;
	level = vector<bool> (N, false);
	
	if (game[0][start] != 'b') return;
   
   // inicializar datos	
	processed.assign( edges.size(), false);
	discovered.assign( edges.size(), false);
	parents.assign(edges.size(), -1);
	                         
	s.push(start);   		
    discovered[start] = true; 		// marcar como descubierto
        
	while (!s.empty()) { 			// mientras la pila no este vacia
	  int v = s.top(); 				// obtener un elemento de la pila
	  s.pop();
      
      process_node(v); 				// procesar el vertice
      
      if(finished) return;
                
		for (unsigned i = 0; i < edges[v].size(); i++) {
			if( valid_edge(v, edges[v][i]) ){
				if(!discovered[edges[v][i]]) {
					s.push(edges[v][i]);
					discovered[edges[v][i]] = true;
               parents[edges[v][i]] = v;
            }
            if (!processed[edges[v][i]])
	            process_edge(v, edges[v][i]);
         }
		}
		processed[v] = true; 		// marcar como procesado 
	}
}

void Graph::print(){
	for (unsigned i = 0; i < edges.size(); i++) {
		cout << i << ": ";

		for (unsigned j = 0; j < edges[i].size(); j++)
			cout << edges[i][j] << " ";

		cout << endl;
	}
}




int main(){
	unsigned N, n_case=1; 
	
	while (cin >> N) {
		if (0==N) return 0;
		
		Graph g;
		g.read(N);
		
		//g.print();
		
		char winner = 'W';
		for (unsigned i=0; i<N; i++) {
			g.bfs(i);
			if (g.all_levels()) {
				winner = 'B';
				break;
			}			
		}
		
		cout << n_case++ << " " << winner << endl;

	}
	return 0;
}
