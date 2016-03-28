#include <iostream>
#include <cmath>


using namespace std;

bool is_prime(int n) {
	if (2==n) return true;
	if (n%2 == 0 || 1==n) return false;
	
	int l = sqrt(n);
	for (int i=2; i <= l; i++) 
		if (n % i == 0) return false;

	return true;
}

int main(){
	int a, b;
	cin >> a;
	
	while (a--) {
		cin >> b;	
		if (is_prime(b)) cout << "Prime\n";
		else cout << "Not Prime\n";
	}
	
	return 0;
}
