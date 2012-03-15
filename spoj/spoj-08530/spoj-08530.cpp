#include <iostream>
#include <cmath>

using namespace std;

int main () {
  string num;

  while (cin >> num) {
    if ("0" == num) return 0;

    unsigned sum = 0;
    for (int i=num.size()-1, k = 0; i >= 0; i--, k++) {
      sum = (num[i] - '0')*(pow(2.0, (double)(k + 1)) - 1) + sum;
    }
    cout << sum << "\n";

  }
  return 0;
}
