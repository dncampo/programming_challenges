/*
Title: Sphere
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1011
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>
#define PI 3.14159

using namespace std;

int main() {
    float r;
    cin >> r;
    cout << "VOLUME = " <<  fixed << setprecision(3) << 4/3.0*PI*r*r*r << endl;
    return 0;
}
