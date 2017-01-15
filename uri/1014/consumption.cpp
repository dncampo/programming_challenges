/*
Title: Consumption
Tags: adhoc
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1014
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int a;
    float b;
    cin >> a >> b;
    cout <<  fixed << setprecision(3) << a/b << " km/l" << endl;
    return 0;
}
