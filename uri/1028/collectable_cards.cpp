/*
Title: Collectable Cards
Tags: number theory, adhoc, basic math
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1028
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: GCD.
*/

#include <iostream>

using namespace std;

int gcd (int a, int b) {
    if (b==0) return a;
    else return gcd (b, a%b);
}

int main() {
    int nc, a, b;

    cin >> nc;
    while (nc--) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
