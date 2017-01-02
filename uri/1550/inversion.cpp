/*
Title: Inversion
Tags: dag, bfs, shortest path
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1550
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define NODES 10000

using namespace std;

class Graph{
    private:
        vector<vector<int> > edges;
        int nedges;

    private:
        vector<bool> processed;
        vector<bool> discovered;
        vector<int> parents;
        bool finished;

    public:
        Graph():nedges(0){}
        void read();
        int reverse(int);
        int bfs(int, int);
        int count_path(int start, int end);
        void print();
};

int main(){
    Graph g;
    g.read();
    int n_cases, a, b;

    cin >> n_cases;
    while(n_cases--) {
        cin >> a >> b;
        cout << g.bfs(a, b) << endl;
    }
    return 0;
}

int Graph::reverse(int a) {
    int r = 0;
    while (a%10==0) a/=10;
    while (a) {
        r = (r*10 + a%10);
        a /= 10;
    }
    return r;
}

void Graph::read(){
    edges.clear();
    int x1, x2;
    edges.resize(NODES+1);
    for(int i = 1; i < NODES; i++) {
        x1 = i+1;
        x2 = reverse(i);
        edges[i].push_back(x1);
        if (i != x2) {
            edges[i].push_back(x2);
        }
    }
}

// BREADTH FIRST SEARCH
int Graph::bfs(int start, int end){
    queue<int> q;
    processed.assign( edges.size(), false);
    discovered.assign( edges.size(), false);
    parents.assign(edges.size(), -1);

    q.push(start);
    discovered[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        processed[v] = true;

        for (unsigned i = 0; i < edges[v].size(); i++) {
            if(!discovered[edges[v][i]]) {
                q.push(edges[v][i]);
                discovered[edges[v][i]] = true;
                parents[edges[v][i]] = v;
                if (edges[v][i] == end) {
                    return count_path(start, end);
                }
            }
        }
    }
}


int Graph::count_path(int start, int end){
    if( start == end || end == -1){
        return 0;
    } else {
        return 1 + count_path(start, parents[end]);
    }
}
