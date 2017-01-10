/*
Title: Salary with Bonus
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1009
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
    string a;
    float b, c;
    cin >> a >> b >> c;

    cout << "TOTAL = R$ " <<  fixed << setprecision(2) << b + c*0.15 << endl;
    return 0;
}
