/**
 * Title: Bicoloring
 * URL: http://online-judge.uva.es/p/v100/10004.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza una matriz de adyacencia para representar el grafo. Es decir para representar el arco 
	A1 que une los vértices V4 y V1 se establece como CONNECTED la posición [V1][V4] de la matriz.
	+ Sólo se utiliza la parte triangular superior de la matriz para simplificar los cálculos. Por ejemplo
	si necesitase insertar el arco que une los nodos Nj y Ni, donde Nj > Ni, en la matriz se establece como
	CONNECTED la posición [Ni][Nj] para que quede en la parte superior de la misma.
	+ Para resolver el problema se recorre la matriz diagonal superior y para cada vértice que aparezca conectado
	al actual se lo colorea si no lo está (con el color distinto al del actual).
	+ Si el vértice conectado al actual ya está coloreado sólo continuamos si su color es distinto al del
	actual. Caso contrario se determina el grafo como NOT BICOLORABLE.
	+ Si se pudo terminar de colorear todos los véctices (se pudo recorrer la matriz diagonal superior
	completamente) entonces se determina el grafo como BICOLORABLE.

**/

#include <iostream>
#include <vector>

using namespace std;

enum Edge { DISCONNECTED, CONNECTED };
enum Color { NO_COLOR, RED, WHITE }; // dos posibles colores

struct Graph {
	vector <vector<Edge> > adjacency;
	vector <Color> color;
};

void solve_graph (Graph &g) {
	g.color[0] = RED;
	for (unsigned i = 0; i < g.adjacency.size(); i++) {
		
		for (unsigned j = i + 1; j < g.adjacency.size(); j++) { //solo chequeo la matriz diagonal superior
			if (DISCONNECTED == g.adjacency[i][j]) continue; // no hay arco
			
			if (NO_COLOR == g.color[j]) { //si no esta coloreado
				g.color[j] = (RED == g.color[i]) ? WHITE: RED; //el inverso del color del nodo 'padre'
			}
			else {
				if (g.color[j] == g.color[i]) {
					cout << "NOT BICOLORABLE." << endl;
					return;
				}
			}
		}
	}
	cout << "BICOLORABLE." << endl;
	return;
}

int main () {
	unsigned nodes, edges;

	while (cin >> nodes) {

		if (0 == nodes) return 0;
		
		Graph g;
		g.adjacency = vector<vector<Edge> > (nodes);
		for (unsigned j = 0; j < nodes; j++) {
				g.adjacency[j] = vector <Edge>(nodes, DISCONNECTED);
		}
		
		g.color = vector<Color> (nodes, NO_COLOR);
		
		cin >> edges;
		unsigned n1, n2;
		for (unsigned i = 0; i < edges; i++) {
			cin >> n1 >> n2;
			if (n1 > n2) {
				n1 ^= n2; //swap values
				n2 ^= n1;
				n1 ^= n2;
			}
			g.adjacency[n1][n2] = CONNECTED;
		}
		solve_graph(g);
	}
	return 0;
}
