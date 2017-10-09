#include <iostream>
#include <random>

using namespace std;

int minn = 0;
int maxx = 100;
int n = 200;

random_device rd;     // only used once to initialise (seed) engine
mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
uniform_int_distribution<int> uni(minn,maxx); // guaranteed unbiased


int main () {
    vector<vector<int> > d(n);
    for (int k=0; k<n; ++k) {
        vector<int> t(n,0);
        d[k] = t;
    }
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            if (i==j) {
                d[i][j] = 1;
                continue;
            }
            int random_int = uni(rng);
            random_int = random_int ? 0 : 1;
            d[i][j] = random_int;
            d[j][i] = random_int;
        }
    }
    cout << n << endl;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
