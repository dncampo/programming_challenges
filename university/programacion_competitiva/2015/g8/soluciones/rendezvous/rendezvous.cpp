#include <iostream>
#include <vector>
#include <limits>
#include <map>

#define INFINITY 10000

using namespace std;

class Graph{
	private:
		vector<vector<int> > weight;  	// informacion de adyacencia
		int max_node;
		map<unsigned, string> names;
		
	public:
		Graph(){}
		bool read();
		void floyd();
		void print();
};

int main(){
	Graph g;
	int i=1;
	while(g.read()){		
		g.floyd();
		cout << "Case #" << i << " : ";
		g.print();
		i++;
		g = Graph();
	 }
	
	return 0;
}

bool Graph::read(){
	//int n_nodes, n_edges, x, y, w; 
	int x,y, a,b,k;
	string nn;
	
	this->weight.clear(); 

	cin >> x >> y;
	if (0==x && 0==y) return false;
	
	weight.resize(x);		
	
	for(int i = 0; i < x; i++){
		weight[i].assign(x, INFINITY);
	}
	
	this->names = map<unsigned, string>();
	for (unsigned i=0; i<x; i++){
		cin >> nn;
		this->names[i] = nn;
	}
	for (unsigned i=0; i<y; i++) {
		cin >> a >> b >> k;
		a--, b--;
		weight[a][b] = k;
		weight[b][a] = k;
	}
	
	
	return true;
}

void Graph::floyd() {
	int through_k;    // distancia a traves del vertice k 

	for (unsigned k = 0; k < weight.size(); k++){
		for (unsigned i = 0; i < weight.size(); i++){
			for (unsigned j = 0; j < weight.size(); j++){
				through_k = weight[i][k] + weight[k][j];
				
				if (through_k < weight[i][j]){
	         	weight[i][j] = through_k;
	         }
			}
		}
	}
}



void Graph::print(){
	vector<unsigned> distances(weight.size());
	for (unsigned i = 0; i < weight.size(); i++) {
		unsigned ssum=0;
		for (unsigned j = 0; j < weight[i].size(); j++){
			if (i==j) continue;
			ssum += weight[i][j];
			/*if(INFINITY == weight[i][j])
				cout << "* ";
			else
				cout << weight[i][j] << " ";*/
		}
		//cout << endl;
	}
	
	int minn = INFINITY, pos=0;
	for (unsigned i=0; i<weight.size(); i++){
		if (distances[i] < minn) {
			minn = distances[i];
			pos = i;			
		}
	}
	cout << this->names[pos] << endl;
}


