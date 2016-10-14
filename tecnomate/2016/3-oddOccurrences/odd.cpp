#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int a = 0;
    for (int i=0; i<A.size(); i++) {
        a ^= A[i];
    }
    return a;
}

int main () {
    int n_cases, t, n, m;
    cin >> n_cases;
    while (n_cases--) {
        cin >> t;
        n = 0;
        while (t--) {
            cin >> m;
            n ^= m;
        }
        cout << n << endl;
    }
}
