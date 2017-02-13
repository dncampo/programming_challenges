/*
Title: Encryption
Tags: string, adhoc
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1024
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;


int main() {
    int nc;
    string a, b;

    cin >> nc;
    while (nc--) {
        cin >> a;
        b=a;
        for (int i=0; i<a.size(); i++)
            a[i] += 2;
        for (int i=0, j=a.size()-1; i<a.size(); i++, j--)
            b[i] = a[j];            
  /*      for (int i=a.size()/2 + a.size()%2; i<a.size(); i++)
            a[i] -= 1;*/
        cout << b << endl;
    }
    return 0;
}
