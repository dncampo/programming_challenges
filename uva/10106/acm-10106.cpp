/**
 * Title: Product 
 * URL: http://online-judge.uva.es/p/v101/10106.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
	+ Se realiza el producto entre dos enteros grandes utilizando la clase BigInt.

**/


#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000 
#define DIGITS 9	
#define SIZE 509	

using namespace std;

typedef long long data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(char *, const int );
		

		BigInt operator*(BigInt& );


		bool operator>(const BigInt& );

		BigInt &operator=(const BigInt& );

		void print();
		void zero_justify();
};


int main(){

	char num[SIZE];
	char num2[SIZE];


	while(cin >> num >> num2){
		BigInt n1(num,strlen(num));	
		BigInt n2(num2, strlen(num2));
		BigInt r;

		r = n1 * n2;
			
		r.print();
		cout << endl;
	}
	
	return 0;
}

BigInt::BigInt(){
	num[SIZE-1] = 0;
	offset = SIZE-1;
}

BigInt::BigInt(char* n, int size){
	int it = size; //itera sobre el char*	
	int end = 0;
	char temp = '\0';
	int i = SIZE - 1; //itera sobre el num

	if(strcmp(n,"0") == 0) {
		num[i] = 0;
	} else {
		while(it > end + DIGITS) {
			it -= DIGITS;
			num[i--] = atol(&n[it]);
			
			if(it+DIGITS != size)
				n[it+DIGITS] = temp;
				
			temp = n[it];
			n[it] = '\0';
		}
		
		num[i] = atol(&n[end]);
		n[strlen(n)] = temp;
	}
	
	offset = i;
}

bool BigInt::operator>(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset)
		return this->offset < b.offset;

	// comparar cuando tiene el mismo offset
	int ds = offset;
	
	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;
	
	if(ds == SIZE) return false; // son iguales
	
	return this->num[ds] > b.num[ds];
}


BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	for(int i = offset; i < SIZE; i++){
		this->num[i] = b.num[i];
	}
	
	return *this;
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

