/*
Title: 500! factorial
Tags: bigint, factorial, big multiplication, numbers, precalculation
URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/6/623.html
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo, Leonardo Bórtoli
Contact e-mail: dncampo at gmail dot com
Notes:
    + A new class to encapsulate the big integer is created
    + A multiplication method is needed in order to perform the operation
    + All factorials, from 0! to 1000! are precalculated and stored in an array
    + that is queried later on.
    + Each position in the array holds a number in BASE 10000. Given this, the representation
    + of the number will have a factor of 4 times less operations and space usage.
*/

#include <iostream>

#define BASE 10000
#define DIGITS 4
#define SIZE 650
#define MAX_N 1001

using namespace std;

typedef unsigned int uint;

class BigInt{
	public:
		uint num[SIZE];
		int offset;

		void operator*(uint );
		void print();
};

BigInt fact[MAX_N];

void init();

int main(){
	init();

	uint n;
	while(cin >> n){
		cout << n << '!' << endl;
		fact[n].print();
		cout << endl;
	}
	return 0;
}

void init(){
	fact[0].num[SIZE-1] = 1;
	fact[0].offset = SIZE - 1;

	for(uint i=1; i<MAX_N; i++)
		fact[i-1] * i;
}

void BigInt::operator*(uint n){
	uint c = 0;

	int i = SIZE-1;
	for(; i>=offset; i--){
		c += n * num[i];
		fact[n].num[i] = c % BASE;
		c /= BASE; 
	}

	if(c > 0){
		fact[n].num[i] = c;
		fact[n].offset = i;
	}
	else
		fact[n].offset = ++i;
}

void BigInt::print(){
	int i = offset;
	int c;
	uint temp;
	cout << num[i++];

	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<DIGITS-c; j++)
			cout << '0';
		if(num[i] != 0)
			cout << num[i];
		i++;
	}
}
