/**
 * Title: Fibonacci Freeze
 * URL: http://acm.uva.es/p/v4/495.html
 * Resources of interest:
 * Solver group: Yeyo	
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Primero se calculos los primeros 5000 factoriales y se guardan en un vector.
   Luego para cada entrada se imprime el resultado.
**/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#define BASE 1000000000000000000 // Base del número
#define SIZE 59	// Cant. de cifras del numero, en base BASE
#define DIGITS 18

class BigInt{
	private:
		long long num[SIZE];
	public:
		int offset;
	public:
		BigInt(long long = 0);
		BigInt operator+(BigInt& );
		BigInt &operator=(const BigInt& );
		void print();
};

BigInt::BigInt(long long n ){
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
// siempre  this > b
	if(this->offset < b.offset){
		return (b + *this);
	}

	BigInt res;
	long long c = 0;
	int i = SIZE-1;
	long long t;
	
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

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(&(this->num[offset]), &(b.num[offset]), sizeof(long long [SIZE-offset+1]));
	
	return *this;
}

void BigInt::print(){
	int i = offset;
	int c;
	long long temp;
	
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
}

int main(){
	BigInt fib[5001] = {BigInt(0) , BigInt(1)}; 

	for(int i = 2; i < 5001; i++){
      fib[i] = fib[i-1] + fib[i-2];
	}

   int n;
   
	while(~scanf("%d", &n)){
	   printf("The Fibonacci number for %d is ", n);
		fib[n].print();
	   printf("\n");		
	}

	return 0;
}
