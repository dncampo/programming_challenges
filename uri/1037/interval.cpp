/*
Title: Interval
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1037
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks:
*/

#include <iostream>
#include <string>

using namespace std;

string interval(float a){
    int b = a;
    string r = "Intervalo ";
    if (0.00000 <= a && a <= 25.00000) {
        r += "[0,25]";
    }
    else if (25.00001 < a && a <= 50.0000000) {
        r += "(25,50]";
    }
    else if (50.0000000 < a && a <= 75.0000000) {
        r += "(50,75]";
    }
    else if (75.0000000 < a && a <= 100.0000000) {
        r += "(75,100]";
    }
    else r = "Fora de intervalo";
    return r;
}

int main() {
    float a;
    cin >> a;
    cout << interval(a) << endl;
    return 0;
}
