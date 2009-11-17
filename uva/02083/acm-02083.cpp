#include <iostream>
#include <iomanip>

using namespace std;

int main () {

	unsigned fac[10];
	fac[0] = 1;
	
	for (unsigned i = 1; i < 10; i++) {
		fac[i] = fac[i-1] * i;
	}

	cout << "n e" << endl;
	cout << "- -----------" << endl;
	double e = 0;
	
	cout << setprecision(10);
	
	for (unsigned i = 0; i < 10; i++) {
		e += (double)1 / (double)fac[i];
		cout << i << " " << e << endl;
	}
	return 0;
}
