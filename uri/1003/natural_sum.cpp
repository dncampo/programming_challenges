/*
Title: Natural Sum
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1003
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>

using namespace std;

int main(){
	unsigned long long a, b;

	cin >> a >> b;
	a--;
	cout << (b*(b+1) - a*(a+1))/2 << endl;
}
