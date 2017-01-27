/*
Title: Snack
Tags: adhoc, basic math
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1038
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const float p[] = {0, 4, 4.5, 5, 2, 1.5};


int main() {
    int a, b;
    cin >> a >> b;
    cout << "Total: R$ " << setprecision(2) << fixed << p[a]*b << endl;
    return 0;
}
