/*
Title: The Greatest
Tags: adhoc
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1013
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a = max(max(a, b), c);
    cout << a << " eh o maior" << endl;
    return 0;
}
