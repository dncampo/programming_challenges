/*
Title: Area of a Circle
Tags: adhoc, basic
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1002
Resources of interest:
Solver: David N. Campo
Contact e-mail: dncampo at gmail dot com
Solution remarks: none.
*/

#include <iostream>
using namespace std;

int main() {
	double a, b, pi;
	pi = 3.14159;
	cin >> a;
	b = pi * (a*a);
	std::cout.precision(4);
	cout << "A=" << fixed  << b << endl;
	return 0;
}
