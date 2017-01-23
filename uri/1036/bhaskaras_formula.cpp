/*
Title: Bhaskara's Formula
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1036
Resources of interest: http://mathworld.wolfram.com/BhaskarasFormula.html
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float a, b, c, disc;
    cin >> a >> b >> c;
    disc = b*b - 4*a*c;
    if (a==0 || disc < 0) {
        cout << "Impossivel calcular" << endl;
    }
    else {
        float r1, r2;
        r1 = (-b + sqrt(disc))/(2*a);
        r2 = (-b - sqrt(disc))/(2*a);
        cout << fixed << setprecision(5) << "R1 = " << r1 << \
            endl << "R2 = " << r2 << endl;
    }
    return 0;
}
