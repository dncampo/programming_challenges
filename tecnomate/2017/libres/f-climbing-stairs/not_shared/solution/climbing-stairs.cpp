#include <iostream>

using namespace std;


unsigned long long climbingStairs(int n) {
    if (n<4) return n;
    unsigned long long s[n+1];
    s[1] = 1;
    s[2] = 2;
    for (int i=3; i<=n;++i) {
        s[i] = s[i-1] + s[i-2];
    }
    return s[n];
}

int main () {
    int a;
    cin >> a;
    cout << climbingStairs(a) << endl;
    return 0;
}
