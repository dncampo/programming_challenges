/*
Title: Simple Calculate
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1010
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
    float c, v;
    cin >> a >> b >> c;
    v = b*c;
    cin >> a >> b >> c;
    cout << "VALOR A PAGAR: R$ " <<  fixed << setprecision(2) << v + b*c << endl;
    return 0;
}
