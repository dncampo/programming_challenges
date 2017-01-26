/*
Title: Banknotes and Coins
Tags: adhoc, basic math
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1021
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int b[] = {0, 100, 200, 500, 1000, 2000, 5000, 10000};
const int m[] = {0, 1, 5, 10, 25, 50, 100};
int c[8] = {0};
int d[7] = {0};

int main() {
    double a;
    cin >> a;
    int aaa = a*100.0;

    for (int i=7; i>1; i--) {
        c[i] = aaa / b[i];
        aaa %= b[i];
    }
    for (int i=6; i>0; i--) {
        d[i] = aaa / m[i];
        aaa %= m[i];
    }
    cout << "NOTAS:" << endl;
    for (int i=7; i>1; i--) {
        cout << c[i] << " nota(s) de R$ " << b[i]/100 << ".00" << endl; 
    }
    cout << "MOEDAS:" << endl;
    for (int i=6; i>0; i--) {
        cout << d[i] << " moeda(s) de R$ " << setprecision(2) << fixed << m[i]/100.0 << endl; 
    }    
    return 0;
}
