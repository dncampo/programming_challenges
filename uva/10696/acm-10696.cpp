/** 
 * Title: f91
 * URL: http://online-judge.uva.es/p/v106/10696.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + La clave de es descubrir que para todos los números N <= 101, f91(N) = 91; 
	y si N > 101 entonces f91(N) = N - 10.
	
**/


#include <iostream>

using namespace std;

int main() {
  
  unsigned num;
  while (cin >> num) {
	 if (0 == num) return 0;
	 
	 if (101 < num) cout << "f91(" << num << ") = " << num - 10 << endl;
	 else cout << "f91(" << num << ") = 91" << endl;
  }
  
  return 0;
}
