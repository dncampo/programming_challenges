#include <iostream>
#include <map>

using namespace std;

int main () {
  unsigned n_cases;
  string s1, s2;

  cin >> n_cases;
  for (unsigned i=0; i<n_cases; i++) {
    cin >> s1 >> s2;

    map<char,unsigned> m1, m2;

    for (string::const_iterator it=s1.begin(); it != s1.end(); it++) {
      m1[*it]++;
    }
    for (string::const_iterator it=s2.begin(); it != s2.end(); it++) {
      m2[*it]++;
    }
    if (m1==m2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
