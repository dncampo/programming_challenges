/*
Title: Average 2
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1006
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // your code goes here
    double a, b, c;
    cin >> a >> b >> c;

    cout << "MEDIA = " << fixed << std::setprecision(1) << (2*a+3*b +5 *c)/10.0 << endl;
    return 0;
}
