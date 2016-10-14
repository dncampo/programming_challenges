#include <iostream>

using namespace std;

// result is the upper right corner of
// / k-2  k-1 \ ^ n-1
// \  1    0  /
// which is (k-1)^n + (k-1) * (-1)^n
long painting(long long  n, long long k) {
    long long M=1e9+7, r=1, p, t;
    t = n;
    for (p=--k; n; n/=2)
        n%2 ? r = r*p%M : 0,
        p = p*p%M;
    (r += t%2 ? M-k : k) %= M;
    return r;
}
 
int main () {
    long long  n_cases, n, k;
    cin >> n_cases;
    while(n_cases--) {
        cin >> n >> k;
        cout << painting(n, k) << endl;        
    }
    return 0;
}
