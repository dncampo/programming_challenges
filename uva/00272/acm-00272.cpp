#include <iostream>

using namespace std;

int main () {
  char c;
  bool first = true;

  while (cin >> noskipws >> c) {
    if ('"' == c) {
      if (first)
	cout << "``";
      else
	cout << "''";

      first = !first;
    }
    else {
      cout << c;
    }
  }
  return 0;
}
