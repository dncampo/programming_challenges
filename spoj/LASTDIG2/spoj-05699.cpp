/**
 * Title: The last digit re-visited
 * URL: https://www.spoj.pl/problems/LASTDIG2/
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Para resolver el problema de obtener el último dígito de una potencia se revisan los ciclos
	que poseen las bases de dicha expresión. Por ejemplo, cualquier número que finalice en 2 tiene ciclos
	de potencia: 2, 4, 8, 6.
	Un ejemplo concreto sería: last_digit(9872 ^ 9) = 2, last_digit(9872 ^ 10) = 4,last_digit(9872 ^ 11) = 8,
	last_digit(9872 ^ 12) = 6, last_digit(9872 ^ 13) = 2,...

**/

#include <iostream>
using namespace std;

int l2[] = {6,2,4,8};
int l3[] = {1,3,9,7};
int l4[] = {6,4};
int l7[] = {1,7,9,3};
int l8[] = {6,8,4,2};
int l9[] = {1,9};

int main() {
	unsigned long long b;
	int n, i, l;
	string a;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >>a>>b;
		l = a[a.size() - 1] - '0';

		if (0 == b) cout << "1";
		else if (0 == l || 1 == l || 5 == l || 6 == l) cout << l;
		else if (2 == l) cout << l2[b % 4];
		else if (3 == l) cout << l3[b % 4];
		else if (4 == l) cout << l4[b & 1];
		else if (7 == l) cout << l7[b % 4];
		else if (8 == l) cout << l8[b % 4];
		else if (9 == l) cout << l9[b & 1];
		cout << endl;
	}
	return 0;
}
