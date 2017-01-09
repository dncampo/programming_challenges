/*
Title: Salary
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1008
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
    int a, b;
    float c;
    cin >> a >> b >> c;

    cout << "NUMBER = " << a << endl;
    cout << "SALARY = U$ " << fixed << setprecision(2) << b*c << endl;
    return 0;
}
