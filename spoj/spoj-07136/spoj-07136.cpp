#include <iostream>
#include <vector>

using namespace std;

int main () {
  unsigned n_case=0, n, m, c;

  while (cin >> n >> m >> c) {
    if (n == 0 &&  m == 0 && c == 0) return 0;

    int sum = 0, max = 0;
    vector<int> cap(n);
    for (unsigned i=0; i<n; i++) {
      cin >> cap[i];
    }
    unsigned temp;
    for (unsigned i=0; i<m; i++) {
      cin >> temp;
      sum += cap[temp - 1];
      cap[temp - 1] = -cap[temp - 1];
      max = (sum > max) ? sum : max;
    }

    cout << "Sequence " << ++n_case << "\n";
    if (max > c) {
      cout << "Fuse was blown.\n";
    }
    else {
      cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n";
    }
    cout << "\n";
  }
  return 0;
}
