#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCircleNum(vector<vector<int> > M) {
    vector<int> visited(M.size(), 0);
    int count = 0;
    queue<int> queue;
    for (int i = 0; i < M.size(); i++) {
        if (visited[i] == 0) {
            queue.push(i);
            while (!queue.empty()) {
                int s = queue.front(); queue.pop();
                visited[s] = 1;
                for (int j = 0; j < M.size(); j++) {
                    if (M[s][j] == 1 && visited[j] == 0)
                        queue.push(j);
                }
            }
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int> > d(n);
    for (int k=0; k<n; ++k) {
        vector<int> t(n,0);
        d[k] = t;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> d[i][j];
        }
    }
    cout << findCircleNum(d) << endl;
    return 0;
}
