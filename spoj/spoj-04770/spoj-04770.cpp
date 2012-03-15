#include <iostream>
#include <vector>

using namespace std;

unsigned reverse (unsigned num) {
  unsigned ret = 0;
  while (num) {
    ret *= 10;
    ret += num%10;
    num /= 10;
  }

  return ret;
}

int main () {
  unsigned cases, num, rev;

  cin >> cases;
  for (unsigned i=0; i<cases; i++) {
    unsigned times=0;

    cin >> num;
    rev = reverse(num);
    do {
      num += rev;
      rev = reverse(num);
      times++;
    } while (rev != num);

    cout << times << " " << num << "\n";
  }
}
