#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// c < d ?
// A a true
// A b true
// A A false
// a A false
// b A false
bool compare (char c, char d) {
	if (c == d) return false;
	if (toupper(c) == toupper(d)) return c < d;

	return toupper(c) < toupper(d);
}

int main () {
	unsigned n_cases;
	string l;

	cin >> n_cases;

	while (cin >> l) {
		sort(l.begin(), l.end(), compare);
		cout << l;

	}
}


