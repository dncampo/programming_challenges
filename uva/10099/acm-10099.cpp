/// TLE :@


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

unsigned max_total;

struct Edge {
	unsigned connected;
	unsigned flow;
};

struct Graph {
	vector<vector<Edge> > adjacency;
	Graph (unsigned n) {
		adjacency = vector<vector<Edge> >(n);
		for (unsigned i = 0; i < n; i++) {
			adjacency[i] = vector<Edge>();
		}
	}
};

unsigned best_flow (Graph &g, vector<bool>& procesed, vector<bool>& visited, unsigned start, unsigned const end, unsigned max_acum) {
	if (end == start) return max_acum;
	int tmp = -1;

	for (unsigned k = 0; k < g.adjacency[start].size(); k++) {
		if (true == procesed[k]) continue;
		if (false == visited[g.adjacency[start][k].connected]) {
			visited[ g.adjacency[start][k].connected ] = true;
			max_acum = (g.adjacency[start][k].flow < max_acum)? g.adjacency[start][k].flow: max_acum;
			tmp = best_flow (g, procesed,visited, g.adjacency[start][k].connected, end, max_acum);
			visited[g.adjacency[start][k].connected] = false;
			max_total = (tmp > (int)max_total)? tmp: max_total;
		}
	}
	procesed[start] = true;
	if (-1 == tmp) return 0;

	return max_total;
}

int main () {

	unsigned N, R, C1, C2, P, S, D, T, n_case = 1;
	
	while (cin >> N >> R) {
		if (0 == N && 0 == R) return 0;
		
		Graph g(N);
		for (unsigned i = 0; i < R; i++) {
			cin >> C1 >> C2 >> P;
			C1--, C2--;
			
			Edge e;
			e.connected = C2;
			e.flow = P;
			g.adjacency[C1].push_back(e);
			e.connected = C1;
			g.adjacency[C2].push_back(e);
		}
		cin >> S >> D >> T;
		S--, D--;
		vector<bool> visited (N, false);
		vector<bool> procesed (N, false);
		visited[S] = true;
		max_total = 0;
		unsigned max_possible_flow = best_flow (g, procesed,visited, S, D, numeric_limits<int>::max());
		unsigned trips;
		if (numeric_limits<int>::max() == (int)max_possible_flow) {
			trips = 0;
		}
		else {
			trips = T / (max_possible_flow - 1);
			if (0 != T % max_possible_flow) trips++;
		}
		cout << "Scenario #" << n_case++ << endl;
		cout << "Minimum Number of Trips = " << trips << endl << endl;
	}
	return 0;
}

