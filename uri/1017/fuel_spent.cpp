/*
Title: Fuel Spent
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1017
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << fixed << setprecision(3) << a*b/12.0 << endl;
    return 0;
}
