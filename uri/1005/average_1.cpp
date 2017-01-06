/*
Title: Average 1
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1005
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
    double a, b;
    cin >> a >> b;

    cout << "MEDIA = " << fixed << std::setprecision(5) << (3.5*a+7.5*b)/11.0 << endl;
    return 0;
}
