#include <iostream>

using namespace std;


unsigned long rev(unsigned long num) {
  unsigned long ret = 0;
  while (num > 0) {
    unsigned n = num % 10;
cout << n << endl;    
    num = num / 10;
    ret *= 10;
    ret += n;
  } 
  return ret;
}

int main () {
  unsigned long n;
  while (cin >> n) {
    cout << rev(n) << endl;
  }
  
  return 0;
}

