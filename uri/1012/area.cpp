/*
Title: Area
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1012
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
    float a, b, c;
    cin >> a >> b >> c;
    cout << "TRIANGULO: " <<  fixed << setprecision(3) << a*c/2.0 << endl;
    cout << "CIRCULO: " <<  fixed << setprecision(3) << PI*c*c << endl;
    cout << "TRAPEZIO: " <<  fixed << setprecision(3) << (a+b)/2.0*c << endl;
    cout << "QUADRADO: " <<  fixed << setprecision(3) << b*b << endl;
    cout << "RETANGULO: " <<  fixed << setprecision(3) << a*b << endl;
    return 0;
}
