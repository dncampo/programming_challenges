#include <iostream>

using namespace std;

int main(){
	for(unsigned i = 0; i <= 100; i++){
		if ( (i % 2 ==0) || (i % 5 ==0) ) continue;
		
		cout << i << ": ";
		
		unsigned long long div = 11, num = i;
		for(unsigned j = 0; j < 18; j++){
			if (div % num == 0) {
				cout << div << endl;
				break;
			}
			else {
				div *= 10;
				div += 1;
			
			}
		}
	}

	return 0;
}

