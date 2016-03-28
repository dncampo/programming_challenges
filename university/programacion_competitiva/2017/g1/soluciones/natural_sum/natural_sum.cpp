#include <iostream>

using namespace std;

int main(){
	unsigned long long a, b;
	
	cin >> a >> b;
	a--;
	cout << (b*(b+1) - a*(a+1))/2 << endl;
}
