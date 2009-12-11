/**
 * Title:  I Love Big Numbers !
 * URL: http://uva.onlinejudge.org/external/102/10220.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   - Se pre calculan los 1000! primero y se almacenan en un vector
   - Se calcula la suma de cada factorial y se guarda en un vector
   - Para cada salida se imprime el resultado accediendo al vector
**/

#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 10 // Base del número
#define DIGITS 1	// Cant. de digitos para cada cifra
#define SIZE 2569	// Cant. de cifras del numero, en base BASE

using namespace std;

typedef char data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;


		BigInt(long long =0);
		BigInt operator*(BigInt& );
		BigInt &operator=(const BigInt& );

		void print();
		void zero_justify();
		int get_count();
};

int main(){
   BigInt res[1002] = {BigInt(1), BigInt(1)};
   int count[1002], n;

   for(int i = 2; i <=  1000; i++){
      BigInt tmp (i);
      res[i] = res[i-1] * tmp;
   }
   
   for(int i = 1; i <= 1000; i++){
      count [i] = res[i].get_count();
   }

   while (~scanf("%d", &n)){
      printf("%d\n", count[n]);
   }
   
 	return 0;
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
	
	memcpy(this->num, b.num, sizeof(b.num));
	
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
	for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
}
int BigInt::get_count(){
   int res = 0;
   for(int i = offset; i < SIZE; i++){
      res += num[i];
   }
   return res;
}
