/*
Title: Distance Between Two Points
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1015
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    float x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << fixed << setprecision(4) << sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) << endl;
    return 0;
}
