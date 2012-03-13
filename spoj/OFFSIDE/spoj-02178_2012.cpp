#include <iostream>

using namespace std;

int main () {
  int A, D, a, temp;

  while (cin >> A >> D) {
    a = 10000;
    if (0 == A && 0 == D) return 0;

    for (int i=0; i<A; i++) {
      cin >> temp;
      a = (temp < a) ? temp : a;
    }

    int def = 0;
    for (int i=0; i<D; i++) {
      cin >> temp;

      if (temp <= a)
	def++;

    }
    if (def < 2) {
      cout << "Y\n";
    }
    else {
      cout << "N\n";
    }
  }
}
