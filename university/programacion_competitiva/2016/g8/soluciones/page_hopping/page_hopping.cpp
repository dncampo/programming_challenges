#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

#define INFINITY 1000

using namespace std;

class Graph{
	private:
		vector<vector<int> > weight;  	// informacion de adyacencia
		int max_node;
		
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
		cout << "Case " << i << ": average length between pages = ";
		g.print();
		i++;
		g = Graph();
	 }
	
	return 0;
}

bool Graph::read(){
	//int n_nodes, n_edges, x, y, w; 
	int x,y;
	
	this->max_node=0;
	this->weight.clear(); 

	cin >> x >> y;
	if (0==x && 0==y) return false;
	
	weight.resize(101);		
	
	for(int i = 0; i < 101; i++){
		weight[i].assign(101, INFINITY);
		//weight[i][i] = 0; 
	}
	
	do {
		if (0==x && 0==y) return true;	
		
		
		if (this->max_node < x) {
			this->max_node = x;
		}
		if (this->max_node < y) {
			this->max_node = y;
		}
		
		x--, y--;
		weight[x][y] = 1;
		
	}while(cin>>x>>y);
		
	return true;
}

void Graph::floyd() {
	int through_k;    // distancia a traves del vertice k 

	for (unsigned k = 0; k < this->max_node; k++){
		for (unsigned i = 0; i < this->max_node; i++){
			for (unsigned j = 0; j < this->max_node; j++){
				through_k = weight[i][k] + weight[k][j];
				
				if (through_k < weight[i][j]){
	         	weight[i][j] = through_k;
	         }
			}
		}
	}
}


void Graph::print(){
	vector<bool> row (this->max_node, false);
	int sum=0;
	int nodes=0;
	for (unsigned i = 0; i < this->max_node; i++) {
		if (weight[i][0] != INFINITY) {
			nodes++;
			row[i] = true;
		}
	}
	
	for (unsigned i = 0; i < this->max_node; i++) {
		if (row[i] == false) continue;
		for (unsigned j = 0; j < this->max_node; j++){
			if (i==j || row[j]== false) continue;
			sum += weight[i][j];
			/*if(INFINITY == weight[i][j])
				cout << "* ";
			else
				cout << weight[i][j] << " ";
				*/
				
		}
		
	}
	
	cout << fixed << setprecision(3) << (float)sum/((nodes-1)*nodes) << " clicks" << endl;
}

