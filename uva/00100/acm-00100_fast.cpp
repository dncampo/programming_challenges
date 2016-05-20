/*
Title: The 3n + 1 problem
Tags: ad-hoc, collatz conjecture, 3n + 1 conjecture
URL: https://uva.onlinejudge.org/external/1/100.pdf
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + The sequence of each number is calculated as needed and is stored
    + into an array, just in case
*/


#include <iostream>
#include <vector>
using namespace std;

unsigned short res[1000001];

int size;

void solve(int tope){
	unsigned subsec;
	unsigned short count = 0;

	for(register unsigned i = size; i <= tope; i++){
		subsec = i;
		count = 0;

		while(subsec >= i){
			count++;

			if(subsec & 1) // odd
				subsec = subsec + (subsec << 1) + 1;
			else // even
				subsec = subsec >> 1;

		}
		res[i] = count + res[subsec];
	}
		size = tope+1;
}
int main() {
	res[1]=1;
	size = 2;

	unsigned int n1;
	unsigned int n2;

	while(~scanf("%d%d", &n1, &n2)) {
		printf("%d %d ", n1, n2);

		if (n1 > n2){
			unsigned temp = n1;
			n1 = n2;
			n2 = temp;
		}

		if(n2 >= size)
			solve(n2);

		unsigned int max = 0;

		for(register unsigned i=n1; i<=n2; i++)
			if (res[i] > max) max = res[i];

		printf("%d\n", max);
	}

	return 0;
}
