/*
Title: The 3n + 1 problem
Tags: ad-hoc, collatz conjecture, 3n + 1 conjecture
URL: https://uva.onlinejudge.org/external/1/100.pdf
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + The sequence of each number is calculated and stored into an array
    + The input is readed and the longest subsequence in the interval
    + [n1, n2] is searched
*/

#include <iostream>
using namespace std;

unsigned short res[1000001];

int main(int argc, char** argv) {
	// resuelve todas las subsecuencias.
	res[1]=1;

	for(register unsigned i=2; i< 1000001; i++){
		unsigned subsec = i;
		unsigned short count = 0;

		while(subsec >= i){
			count++;

			if(0 == subsec % 2) // even
				subsec = subsec >> 1;
			else // odd
				subsec = 3 * subsec + 1;
		}
		res[i] = count + res[subsec];
	}

	unsigned int n1;
	unsigned int n2;

	while(cin >> n1 >> n2) {
		cout << n1 << " " << n2 << " ";

		if (n1 > n2){
			unsigned temp = n1;
			n1 = n2;
			n2 = temp;
		}
		unsigned int max = 0;

		for(register unsigned i=n1; i<=n2; i++)
			if (res[i] > max) max = res[i];

		cout << max << endl;
	}

	return 0;
}
