/**
 * Title: 500! factorial
 * URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/6/623.html
 * Resources of interest:
 * Solver group: David-Leo-Yeyo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
	 + El procedimiento es el mismo que en la otra solución, solamente que para optimizar el algoritmo y minimizar las
	 	operaciones realizadas, el arreglo para los dígitos se representa en la base elegida (mediante la constante BASE),
	 	disminuyendo así la cantidad de cifras del número y las multiplicaciones y sumas reiteradas que se deben 		
	 	implementar.
**/

#include <iostream>
#include <cstdio>

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
	while(~scanf("%u", &n)){
		//cout << n << '!' << endl;
		printf("%d!\n", n);
		fact[n].print();
		printf("\n");
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
	//cout << num[i++];
	printf("%u", num[i++]);
	
	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<DIGITS-c; j++) {
			printf("0");
			//cout << '0';
		}
		if(num[i] != 0) {
			//cout << num[i];
			printf("%u", num[i]);
		}
		i++;
	}
}



