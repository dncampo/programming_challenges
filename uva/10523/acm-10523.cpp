/**
 * Title:  VERY EASY !!!
 * URL: http://uva.onlinejudge.org/external/105/10523.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
	La solucion a este problema es trivial (usando por supuesto la clase BigInt :-) )
**/

#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000 // Base del número
#define DIGITS 9	// Cant. de digitos para cada cifra
#define SIZE 3000	// Cant. de cifras del numero, en base BASE

using namespace std;

typedef long long data_type;/* data_type depende de la base (elegir el menor tipo de dato que se ajuste)
									 	 no tiene que ser unsigned !!
											 bases que se podrian usar:
											 short       -->   10 - 10000
											 int         -->   10 - 1000000000
											 long long   -->   10 - 1000000000000000000
									 */
class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(long long );
		
		BigInt &operator<<=(const int );
		BigInt operator+(BigInt& );
		BigInt operator*(BigInt& );

		BigInt &operator=(const BigInt& );

		void print();
		void zero_justify();
};

BigInt pow(BigInt &a, long long p);

int main(){
	int n, a;
	
	while(cin >> n >> a){
		BigInt res, mul, p, bigA(a);
		
		for(int i=1; i<=n; i++){
			BigInt bigI(i);
			p = pow(bigA,i);
			mul = bigI * p;
			res = res + mul;
		}
		res.print(); cout << endl;
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

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	for(int i = offset; i < SIZE; i++){
		this->num[i] = b.num[i];
	}
	
	return *this;
}

/*

- -	==>	- (A + B)
- +	==>	- (A - B)
+ -	==>	   A - B
+ +	==>	   A + B

*/
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
	
BigInt BigInt::operator*(BigInt &b){
	BigInt res;
	BigInt* pA = this;
	BigInt* pB = &b;

	if(this->offset > b.offset){
		pA = &b;
		pB = this;
	}
	
	unsigned delta = 1, pos;

	data_type carry = 0;
	res.offset = -SIZE + pA->offset + pB->offset;

	memset(&res.num[res.offset], 0, sizeof(data_type[SIZE - res.offset]));
	
	for (int i = SIZE - 1; i >= pA->offset;  i--, delta++) {
		pos = SIZE - delta;
		carry = 0;

		for (int j = SIZE - 1; j >= pB->offset;  j--, pos--) {
			res.num[pos] += carry + pB->num[j] * pA->num[i];
			carry = res.num[pos] / BASE;
			res.num[pos] -= carry * BASE;
		}
		res.num[pos] = carry;
	}
	res.num[pos] = carry;

	while (res.num[res.offset] == 0 && res.offset < SIZE-1)
		res.offset++;

	res.zero_justify(); 
	
	return res;
}

void BigInt::zero_justify(){
	for(; num[offset] == 0 && offset < SIZE-1; offset++);
}

BigInt pow(BigInt &a, long long p){
	if(p < 0){
		cout << "ERROR: potencia negativa" << endl;
		return a;
	}
	
	BigInt r(1), sq;
	
	if(p == 0)
		return r;
	if(p == 1)
		return a;
	
	if(p & 1){ // potencia impar
		r = pow(a, p-1);
		return r * a;
	}
	else{ // potencia par
		r = pow(a, p/2);
		return r * r;
	}
}

void BigInt::print(){
	int i = offset;
	int c;
	data_type temp;
	
	cout << num[i++];
	
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
			cout << num[i];
		i++;
	}
}
