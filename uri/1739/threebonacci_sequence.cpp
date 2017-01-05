/*
Title: Threebonacci Sequence
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1739
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

bool has_3(unsigned long long k) {
    while (k>0) {
        if (3==k%10) return true;
        k /=10;
    }
    return false;
}

int main() {

    unsigned long long th[60];

    th[0] = 3;
    th[1] = 13;

    for (unsigned long long i=8, j=13, k=i+j, m=2; m<62; i=j, j=k, k=i+j) {
        if (0==k%3 || has_3(k)) {
            th[m] = k;
            m++;
        }
    }
    int N;
    while (cin >> N) {
        cout << th[N-1] << endl;
    }
    return 0;
}
