/**
 * Title: Fibonacci Numbers 
 * URL: http://online-judge.uva.es/p/v105/10579.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   primero se calculan los primero n numeros de fibonacci que tengan menos de 1000 digitos 
   luego se imprime para cada entrada la solucion.
   
**/
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000000000000 // Base del número
#define DIGITS 18	// Cant. de digitos para cada cifra
#define SIZE 56	// Cant. de cifras del numero, en base BASE


typedef long long data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(long long );
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt operator+(BigInt& );
   	BigInt &operator=(const BigInt& );

		void print();

};

int main(){
   const int max = 4825;
   BigInt b[max];
   b[1] = BigInt(1);
   b[2] = BigInt(1);
   
   for(int i = 3; i < max; i++){
      b[i] = b[i-1] + b[i-2];
   }
   
   int n;
   
	while(~scanf("%d", &n)){
	   b[n].print();
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

BigInt::BigInt(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(this->num, b.num, sizeof(b.num));
}

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(this->num, b.num, sizeof(b.num));
	
	return *this;
}

BigInt BigInt::operator+(BigInt &b){ 
	if(this->offset < b.offset){
		return (b + *this);
	}

	BigInt res;
	data_type c = 0, t;
	int i = SIZE-1;
	
	for(; i >= offset; i--){
		t =  c + num[i] + b.num[i];
		c = t / BASE;
		res.num[i] = t - c * BASE;
	}
			
	for(; i >= b.offset; i--){
		t = c + b.num[i];
		c = t / BASE;
		res.num[i] = t - c * BASE;
	}		
	if(c > 0){
		res.num[i] = c;
		res.offset = i;
	} else 
		res.offset = b.offset;

	return res;
}

void BigInt::print(){
	int i = offset;
	int c;
	data_type temp;
	
	printf("%llu", num[i++]);
	
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
			printf("%llu", num[i]);
		i++;
	}
	printf("\n");
}

