/*
Title: Selection Test 1
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1035
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b>c && d>a && (c+d)>(a+b) && c>0 && d>0 && a%2==0) {
        cout << "Valores aceitos" << endl;
    }
    else {
        cout << "Valores nao aceitos" << endl;
    }
    return 0;
}
