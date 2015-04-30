#include<iostream>
#include<map>

using namespace std;

map<string, unsigned> index;
unsigned counter = 0;

int main () {
	string w1, w2, w3, w4, w5;
	for (char a = 'a'; a<= 'z'; a++) {
		w1 = a;
		index[w1] = ++counter;
cout << w1 << ": " << counter << endl;					
	}
	
	for (char a = 'a'; a< 'z'; a++) {
		w1 = a;
		for (char ab = a+1; ab<= 'z'; ab++) {
			if (a == ab) continue;
			w2 = w1 + ab;
			index[w2] = ++counter;
cout << w2 << ": " << counter << endl;			
		}
	}
	cout << counter << endl;
	
	return 0;
}
