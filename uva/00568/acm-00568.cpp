/********************


WRONG APROACH!






***********************/



#include <iostream>
#include <iomanip>

using namespace std;

unsigned fact[10001];

int main () {
	fact[0] = 1;
	
	unsigned temp;
	for (unsigned i = 1; i < 10001; i++) {
		temp = fact[i - 1] * i;
		while (0 == temp % 10) temp /= 10;
		fact[i] = temp % 10;
	}
	unsigned num;
	while (cin >> num) {
		cout << setw(5) << num << " -> " << fact[num] << endl;
	}
	
	return 0;
}