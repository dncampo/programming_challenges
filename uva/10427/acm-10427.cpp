#include <iostream>

using namespace std;

unsigned digits[2893];

int main () {

	unsigned pos = 2892;
	for (unsigned i = 1000; i > 0; i--) {
		unsigned val = i;
		while (val > 9) {
			digits[pos--] = val % 10;
			val /= 10;
		}
		digits[pos--] = val;
	}
	
	for (unsigned i = 0; i < 2893; i++)
		cout << digits[i] << endl;
	
	unsigned num;
	while (cin >> num)
		cout << digits[ (num - 1) % 2893 ] << endl;

	return 0;
}
