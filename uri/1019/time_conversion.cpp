/*
Title: Time Conversion
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1019
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
    
    cout << m/(60*60) << ":" << (m%(60*60)/60) << ":" << m%60 << endl; 

    return 0;
}
