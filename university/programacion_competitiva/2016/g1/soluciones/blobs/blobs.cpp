#include <iostream>
#include <cmath>

#define LNe2 0.69314718 //log2(e)

using namespace std;

int main(){
	int a;
	float b;
	cin >> a;
	
	while (a--) {
		cin >> b;
		if (b==1.0 || b==2.0) {
			cout << b-1.0 << " dias\n";
			continue;
		}
		b -= 1.0;
		cout << ceil(log(b) / LNe2) << " dias\n";
	}
	
	return 0;
}
