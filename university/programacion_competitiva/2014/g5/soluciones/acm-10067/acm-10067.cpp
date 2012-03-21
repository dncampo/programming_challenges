/**
 * Title: Playing with Wheels
 * URL: http://uva.onlinejudge.org/external/100/10067.html
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
	+ Inicialmente se utiliza la tecnica de backtracking
	  para inicializar un grafo de 10000 nodos (de 0 a 9999) 
	  y 80000 arcos (8 arcos por nodo). Cada arco de un nodo 
	  representa un posible movimiento.
	+ Luego para cada entrada se inicializa invalids, es decir
	  las configuraciones no válidas y se realiza una búesqueda
	  por anchura a partir de la configuracion inicial.
	+ Luego se cuenta la cantidad de nodos que hay entre
	  la configuracion deseada y la inicial y se imprime ese valor.
**/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// representacion del grafo
class Graph{
	private:
		vector<vector<int> > edges;  	// informacion de adyacencia
		vector<int> parents;				// indispensable para la solucion

	public:
		Graph(){
			edges.resize(10000);	
		}
		void add_edge(int, int);
		bool valid_edge(int node, int edge);
		void solve(int start, int end, int &count);
		void bfs(int start);
};

vector<int> invalids;  // configuraciones inválidas
vector<int> data;		  // estructura de datos para el backtracking
Graph g;	   			  // estructura de datos para representar un grafo.

void process_solution(){
	int source = 1000*data[0]+ 100*data[1]+10*data[2]+data[3];
	
	g.add_edge(source, 1000*((data[0]+1)%10)+ 100*data[1]+10*data[2]+data[3]);
	g.add_edge(source, 1000*((data[0]+9)%10)+ 100*data[1]+10*data[2]+data[3]);
	
	g.add_edge(source, 1000*data[0]+ 100*((data[1]+1)%10)+10*data[2]+data[3]);
	g.add_edge(source, 1000*data[0]+ 100*((data[1]+9)%10)+10*data[2]+data[3]);	
	
	g.add_edge(source, 1000*data[0]+ 100*data[1]+10*((data[2]+1)%10)+data[3]);	
	g.add_edge(source, 1000*data[0]+ 100*data[1]+10*((data[2]+9)%10)+data[3]);		
	
	g.add_edge(source, 1000*data[0]+ 100*data[1]+10*data[2]+(data[3]+1)%10);	
	g.add_edge(source, 1000*data[0]+ 100*data[1]+10*data[2]+(data[3]+9)%10);	
}

void backtracking(){
	if(data.size() == 4){
		process_solution();
	}else{		
		for(unsigned i = 0; i < 10; i++){
			data.push_back(i);
			backtracking();
			data.pop_back();
		}
	}
}
// grafo no difigido
void Graph::add_edge(int a, int b){ 
	edges[a].push_back(b);
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
bool Graph::valid_edge(int node, int edge){
	for(unsigned i = 0; i < invalids.size(); i++)
		if( invalids[i] == edge || invalids[i] == node) return false;
	
	return true;
}
void Graph::solve(int start, int end, int &count){
	if( start == end || end == -1){
		if(end != start) 
			count = -1;
	} else 
		solve(start, parents[end], ++count);
}

int main(){
	backtracking();
		
	int cases;
	
	cin >> cases;

	for(int i = 0; i < cases; i++){
		int s1, s2, s3, s4;
		int t1, t2, t3, t4;
		int n;

		cin >> s1 >> s2 >> s3 >> s4 
			 >> t1 >> t2 >> t3 >> t4 
			 >> n;

		int inicio =  1000*s1+100*s2+10*s3+s4;
		int destino = 1000*t1+100*t2+10*t3+t4;
		int count = 0;
				
		invalids.resize(n);
	
		for(unsigned j = 0; j < invalids.size(); j++){
			cin >> s1 >> s2 >> s3 >> s4;
			invalids[j] = 1000*s1+100*s2+10*s3+s4;
		}

		g.bfs(inicio);
		g.solve(inicio, destino,count);
	
		cout << count << endl;
	}
	return 0;
}


