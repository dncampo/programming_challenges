/**
 * Title: Ray Through Glasses
 * URL: http://acm.uva.es/problemset/v103/10334.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
 	+ Notar que se debe modificar levemente la definición base de Fibonicci, siendo fib(0) = 1 y
	fib(1) = 2 (a diferencia de la verdadera defición que es fib(0) = 0 y fib(1) = 1 ).
   + Se calculan los números de Fibonacci hasta el Fib(1000) y se los almacena en un vector.
	(se debe definir un número grande en un arreglo y definirle la suma, dado que los tipos de datos 
	incorporados no pueden almacenar tal valor).
	Por último, para imprimir la salida correspondiente se busca en el vector el número de
	Fibonacci que se require en entrada.
**/

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>

#define BASE 1000000000 // Base del número
#define DIGITS 9	// Cant. de digitos para cada cifra
#define SIZE 24	// Cant. de cifras del numero, en base BASE
#define MAX_FIBS 1001 // fib(4787) es el máximo núm de fib con hasta 1000 dígitos

using namespace std;

typedef long long data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(long long );

		BigInt operator+(BigInt& );
		BigInt operator-(BigInt& );

		void print();

};


int main(){
	unsigned num;

	vector<BigInt> fibs(MAX_FIBS);
	BigInt f0(1);
	BigInt f1(2);
	fibs[0] = f0;
	fibs[1] = f1;
	
	for(int i = 2; i < MAX_FIBS; i++) //calc all fibs up to fib(4786)
		fibs[i] = fibs[i-1] + fibs[i-2];	
	

	while(1){
		if(scanf("%u",&num) == EOF) return 0;
		
		fibs[num].print();
		printf("\n");
	}

	return 0;
}

BigInt::BigInt(){
	num[SIZE-1] = 0;
	offset = SIZE-1;
}

BigInt::BigInt(long long n){
	int i = SIZE-1;
	
	if(n == 0)
		num[i--] = 0;
	
	while(n > 0){
		num[i--] = n % BASE;
		n /= BASE;
	}
	offset = ++i;
}


BigInt BigInt::operator+(BigInt &b){
	BigInt res;

	data_type c = 0;
	int smaller; // offset del numero mas chico
	int bigger; // offset del numero mas grande
	const data_type* whosbigger; // cual es el num mas grande

	(this->offset < b.offset) ? (bigger = this->offset, smaller = b.offset, whosbigger = this->num) :
										 (bigger = b.offset, smaller = this->offset, whosbigger = b.num);
	int i = SIZE-1;

	for(; i >= smaller; i--){
		res.num[i] = (c + this->num[i] + b.num[i]) % BASE;
		c = (c + this->num[i] + b.num[i]) / BASE;
	}
	for(; i >= bigger; i--){
		res.num[i] = (c + whosbigger[i]) % BASE;
		c = (c + whosbigger[i]) / BASE;
	}		
	if(c > 0){
		res.num[i] = c;
		res.offset = i;
	}
	else
		res.offset = bigger;

	return res;
}

void BigInt::print(){
	int i = offset;
	int c;
	data_type temp;

	printf("%lld",num[i++]);
	
	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<DIGITS-c; j++)
			printf("0");
		if(num[i] != 0)
			printf("%lld",num[i]);

		i++;
	}
}

