/*
Title: Banknotes
Tags: adhoc, basic math
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1018
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int b[] = {0, 1, 2, 5, 10, 20, 50, 100};
int c[8] = {0};

int main() {
    int m;
    cin >> m;
    cout << m << endl;
    
    for (int i=7; i>0; i--) {
        c[i] = m / b[i];
        m %= b[i];
    }
    for (int i=7; i>0; i--) {
        cout << c[i] << " nota(s) de R$ " << b[i] << ",00" << endl; 
    }
    return 0;
}
