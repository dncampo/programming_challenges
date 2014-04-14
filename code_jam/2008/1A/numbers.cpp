#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long double powers[30];
//const long double base = 3 + sqrt(5);

const long double base = 5.23606797749978969640917366873127623544061835961152572427089724541052092563780489941441440837878227496950817615077378350425326772444707386358636012153345270886677817319187916581127664532263985658053576135041753378500342339241406444208643253909725259262722887629951740244068161177590890949849237139072972889848208864154268989409913169357701974867888442508975413295618317692149997742480153043411L;


long double calculate (unsigned n){
	long double ret = 1.0L;
	
	while (n) {
		unsigned f = floor (log2f((float)n));
		ret = fmod(ret * powers[f], 1000.0L);
		n -= f;
		if (1==n) {
			return fmod(ret * powers[1], 1000.0L);
		}
	}
	return ret;
}

int main () {
	powers[0] = 1;
	powers[1] = base;

	for (int i=2; i <=30; i++) {
		powers[i] = fmod(powers[i-1] * powers[i-1], 1000.0L); // :)
	}
	
// 	for (int i=1; i <=30; i++) {
// 		cout << base << "^" << i << " % 1000 = " << powers[i] << endl;
// 	}
	
	unsigned n_cases, n;
	cin >> n_cases;
	for (int i=0; i<n_cases; i++){
		cin >> n;
		
		int ret = static_cast<int>(calculate(n));
		
		cout << "Case #" << i+1 << ": ";
		
		if (ret < 10) cout << "00" << ret;
		else if (ret < 100) cout << "0" << ret;
		else cout << ret;
		
		cout << endl;
	}
	
	
	return 0;
}
