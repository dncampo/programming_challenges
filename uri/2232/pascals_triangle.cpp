/*
Title: Pascal's Triangle
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/2232
Resources of interest: http://mathworld.wolfram.com/BhaskarasFormula.html
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: Pre-calculate powers of 2 and sum it up according is necessary.
*/

#include <iostream>
#include <numeric>

using namespace std;
unsigned p[32];

int main() {
    p[0] = 1;
    for (int i=1; i<32; i++) {
        p[i] = p[i-1] << 1;
    }

    int n ,a;
    cin >> n;
    while (n--) {
        cin >> a;
        cout << accumulate (p, p+a, 0) << endl;
    }
    return 0;
}
