/*
Title: Age in Days
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1020
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

int main() {
    int m;
    cin >> m;
    cout << m/(365) << " ano(s)\n" << (m%(365)/30) << " mes(es)\n" << (m%365)%30 << " dia(s)\n";
    return 0;
}
