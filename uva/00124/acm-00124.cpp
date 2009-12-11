/**
 * Title: Following Orders
 * URL: http://uva.onlinejudge.org/external/1/124.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza un grafo (implementado con matriz de adyacencia) y se realiza su ordenamiento
	topológico.
	+ Se obtienen luego todos los posibles órdenes de planificación, teniendo en cuenta que los
	nodos aislados pueden ir en "cualquier lugar". Por ello se los trata de una forma un poco
	separada de los demás nodos.

**/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

/**
Estructura del grafo. Se utiliza una matriz de adyacencia.
**/
struct Graph {
	unsigned edges;
	bool directed;

	map <char,unsigned> convertion; //los maps se usan para convertir los nombres (letras) de los nodos a números
	map <unsigned, char> reverse_convertion;
	vector<vector<bool> > adjacency;

	Graph (bool dir = false) { directed = dir; }
	Graph (unsigned n) {
		adjacency = vector<vector<bool> > (n);
		for (unsigned i = 0; i < n; i++) adjacency[i] = vector<bool> (n, false);
	}

	unsigned size() { return adjacency.size(); }
	bool read ();
	vector<string> topological_sort ();
	void get_in_degrees (vector<int> &);
};


/**
Lectura del grafo. Se convierten los caracteres a números.
Se ordena la entrada.
**/
bool Graph::read () {
	string line1, line2;

	if (! getline (cin, line1)) return false;
	getline (cin, line2);

	size_t pos;
	while ((pos = line1.find_first_of (' ')) != string::npos) {
		line1.erase (pos,1);
	}
	while ((pos = line2.find_first_of (' ')) != string::npos) {
		line2.erase (pos,1);
	}

	for (unsigned i = 0; i < line1.size(); i++) {
		convertion[line1[i]] = i;
		reverse_convertion[i] = line1[i];
	}

	adjacency = vector<vector<bool> > (line1.size());
	sort (line1.begin(), line1.end());
	
	for (unsigned i = 0; i < line1.size(); i++) {
		adjacency[i].assign(line1.size(),false);
	}

	unsigned i = 0, src, dst;
	while (i < line2.size()) {
		src = line2[i], dst = line2[i + 1];
		i += 2;
		adjacency[convertion[src]][convertion[dst]] = true;
	}
	return true;
}


/**
Setea el vector in-degree para cada nodo. Si un nodo es aislado se le coloca un in-degree
equivalente a -1. De otra forma se le coloca el in-degree correspondiente.
**/
void Graph::get_in_degrees (vector<int> &in_degree) {
	for (unsigned i = 0; i < size (); i++) {
		for (unsigned j = 0; j < size (); j++) {
			if (adjacency[i][j]) {
				in_degree[j]++;
			}
		}
	}

	// para los que tienen 0-in ver si tambien tienen 0-out => son isolated nodes
	vector <unsigned> possible_isolated;
	for (unsigned i = 0; i < in_degree.size(); i++) {
		if (0 == in_degree[i]) {
			possible_isolated.push_back(i);
		}
	}

	for (unsigned i = 0; i < possible_isolated.size(); i++) {
		bool isolated_node = true;
		for (unsigned j = 0; j < size(); j++) {
			if (adjacency[possible_isolated[i]][j]) isolated_node = false;
		}
		if (isolated_node) {
			in_degree[possible_isolated[i]] = -1; //es isolated
		}
	}
}


/**
Devuelve	un vector de string en donde en la primera posición están todos los
nodos "aislados" (no conectados con el grafo, es decir con 0-in y 0-out).
Luego en cada posición están ordenados los nodos que se fueron convirtiendo en nodos
0-in. Es decir en la posición 1 del vector están los nodos que inicialmente tenían
0-in pero no eran "aislados", en la posición 2 están los que se convierten en 0-in despues
de "desconectar" los 0-in de la primer posición. Así con cada posición hasta desconectar todos
los nodos.
Los nodos se nomenclan como aparecen en la entrada (con letras, se vuelven a convertir
a su forma original).
**/
vector <string> Graph::topological_sort () {
	vector<vector<unsigned> > sorted;
	vector<int> in_degree (size(),0);
	get_in_degrees(in_degree);

	vector<unsigned> isolated;
	for (unsigned i = 0; i < in_degree.size(); i++) {
		if (-1 == in_degree[i]) isolated.push_back(i);
	}
	sorted.push_back(isolated); //sorted[0] contiene los isolated nodes

	bool cont = true;
	while (cont) {
		//a todos los nodos con 0-in los agrupamos
		vector<unsigned> zero_in;
		for (unsigned i = 0; i < size(); i++) {
			if (0 == in_degree[i]) {
				zero_in.push_back(i);
				in_degree[i]--;
			}
		}
		if (zero_in.empty()) {
			cont = false; //no más 0-in => salimos
		}
		else {
			sorted.push_back (zero_in); //se agregan los 0-in
		}

		//Se "desconectan" (sólo en el vector in-degree) los nodos que son 0-in en
		//esta iteración decrementando el valor in-degree de sus nodos adyacentes
		for (unsigned i = 0; i < zero_in.size(); i++) {
			for (unsigned j = 0; j < size(); j++) {
				if (true == adjacency[zero_in[i]][j]) {
					in_degree[j]--;
				}
			}
		}
	}

	//Se vuelven a nombrar los nodos con sus letras originales
	vector<string> res;
	for (unsigned i = 0; i < sorted.size (); i++) {
		string str = "";
		for (unsigned j = 0; j < sorted[i].size(); j++) {
			str += reverse_convertion[ (sorted[i][j]) ];
		}
		res.push_back (str);
	}
	return res;
}


/**
Dada una potencial solución (vector de strings) se le añaden los nodos aislados 
en todas las posiciones de cada string (recordar que un nodo aislado no posee 
restricción y puede ir en cualquier lugar).
Al terminar esta función se tiene la correspondiente solución del problema
de forma "casi" ordenada (la inserción de los nodos aislados la termina
desordenando).
**/
vector <string> merge_isolated_nodes (vector<string> &a, char &b) {
	vector<string> res;
	string BB = "";
	BB = BB + b;
	for (unsigned i = 0; i < a.size(); i++) {
		for (int k = a[i].size(); k >= 0; k--) {
			string tmp = a[i];
			res.push_back (tmp.insert(k,BB));
		}
	}
	return res;
}


/**
Producto cartesiano de dos conjuntos de strings
**/
vector <string> cartesian_product (vector<string> &a, vector<string> &b) {
	vector <string> prod;

	for (unsigned i = 0; i < a.size (); i++) {
		for (unsigned j = 0; j < b.size (); j++) {
			prod.push_back (a[i] + b[j]);
		}
	}
	return prod;
}


/**
A partir de todas las permutaciones (sin considerar los nodos aislados) se van armando las
factibles planificaciones, es decir se van creando planificaciones a partir del resultado
que se obtuvo en el vector de topological_sort. (concatenar los string correspondientes
a cada nivel de "in-degree")
**/
vector <string> all_combinations (vector<vector<string> > &perm) {
	vector<string> all;
	for (unsigned i = 0; i < perm[0].size(); i++) {
		all.push_back (perm[0][i]);
	}
	for (unsigned i = 1; i < perm.size (); i ++) {
		all = cartesian_product (all, perm[i]);
	}
	return all;
}


/**
Dado un string de entrada, se devuelve en un vector de string todas las permutaciones
posibles para dicha entrada.
**/
vector<string> get_permutations (string in) {
	vector<string> res;
	if (in.size() > 0) {
		res.push_back(in);
	}
	while (next_permutation (in.begin(), in.end())) {
		res.push_back (in);
	}
	return res;
}


/**
Uso del grafo para alcanzar la solución.
**/
int main () {
	bool first = true;
	Graph g(true);


	while (g.read()) { //mientras hay casos de prueba...
	
		vector <string> ts = g.topological_sort(); //se obtiene una planificación posible

		//para cada nodo del mismo "nivel" (se convirtieron en 0-in al mismo tiempo)
		//se obtiene la permutación
		vector<vector<string> > permutations;
		for (unsigned i = 1; i < ts.size(); i++) {
			permutations.push_back (get_permutations (ts[i]));
		}

		//combinaciones posibles para al grafo actual, sin contar los nodos
		//aislado ya que pueden ir en "cualquier lugar"
		vector <string> comb = all_combinations (permutations);


		vector <string> result = comb;

		if (ts[0].size() > 0) {
			for (unsigned i = 0; i < ts[0].size(); i++) {
				//Ahora sí se colocan los nodos aislados en cada posible posición
				result = merge_isolated_nodes (result, ts[0][i]);
			}
			//se ordena la lista, ya que probablemente al acoplar
			//los nodos aislados quedo algo desordenada
			sort (result.begin(), result.end());
		}
		else {
			//en este caso no hubo nodos "aislados", entonces en comb ya tenemos la solución
			result = comb;
		}


		if (first) { //primer caso de prueba
			first = false;
		}
		else { //despues del primer caso se imprime una línea en blanco
			cout << endl;
		}
		for (unsigned i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
}

