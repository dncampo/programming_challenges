/** 
 * Title: Fast Multiplication
 * URL: https://www.spoj.pl/problems/MUL/
 * Resources of interest: http://en.wikipedia.org/wiki/Karatsuba_algorithm
 * Solver group: David - Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la herramienta BigInt para realizar la multiplicación de enteros largos, como así
   también se utiliza una implementación del algoritmo de Karatsuba. Este algoritmo (~O(n^1,585)) 
   hace que la multiplicación sea un poco más eficiente que la multiplicación común (O(n^2)) para 
   cierto tamaño de números.
	
**/

#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000 // Base del número
#define DIGITS 9	// Cant. de digitos para cada cifra
#define SIZE 2223	// Cant. de cifras del numero, en base BASE

using namespace std;

class BigInt{
	public:
		long long num[SIZE];
		int offset;

		BigInt(long long = 0);
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt(char *, const int );
		
		BigInt operator+(BigInt& );
		BigInt operator-(BigInt& );
		BigInt operator*(BigInt& );
		BigInt &operator=(const BigInt& );

		void print();
		inline int size();
		void zero_justify();
		BigInt karatsuba(BigInt &x, BigInt &y);
		//métodos usados por karatsuba
		BigInt truncate(int n);
		BigInt shift_right(int n);
		BigInt shift_left (int ds);
};


BigInt::BigInt(long long n){
   memset(this->num, 0, sizeof(num));
   
	int i = SIZE-1;
	
	if(n == 0)
		num[i--] = 0;
	
	while(n > 0){
		num[i--] = n % BASE;
		n /= BASE;
	}
	offset = ++i;
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

BigInt::BigInt(const BigInt &b){
	this->offset = b.offset;
	memcpy(&(this->num[offset]), &(b.num[offset]), sizeof(long long [SIZE-offset+1]));
}



BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	memcpy(&(this->num[offset]), &(b.num[offset]), sizeof(long long [SIZE-offset+1]));
	return *this;
}


BigInt BigInt::operator+(BigInt &b){ 
	if(this->offset < b.offset){
		return (b + *this);
	}

	BigInt res;
	long long c = 0, t;
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

BigInt BigInt::operator-(BigInt &b){
	BigInt res;
	int i = SIZE-1;
	long long temp;
	long long borrow = 0;

	for(; i >= this->offset; i--){
		temp = (i >= b.offset) ? (this->num[i] - borrow - b.num[i]) : (this->num[i] - borrow);
		if(this->num[i] > 0)
			borrow = 0;
		if(temp < 0){
			temp += BASE;
			borrow = 1;
		}
		res.num[i] = temp;
	}

	res.offset = this->offset;
	res.zero_justify();
	
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
	long long carry = 0;
	res.offset = -SIZE + pA->offset + pB->offset;

	memset(&res.num[res.offset], 0, sizeof(long long[SIZE - res.offset]));
	
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
   printf("\n");
}

int BigInt::size(){
   return SIZE - offset;
}

BigInt BigInt::truncate(int n){
   BigInt r(0);
   r.offset = this->offset + n;
   
   if (0 >= r.size()) {
      return BigInt(0);
   }   
   memcpy(&(r.num[r.offset]), &(this->num[r.offset]), sizeof(long long[r.size()]));   
   r.zero_justify();
   return r;
}

BigInt BigInt::shift_right(int ds){
   BigInt r(0);
   r.offset = this->offset + ds;
   if (0 >= r.size()) {
      return BigInt(0);
   }
 
   memcpy(&(r.num[r.offset]), &(this->num[this->offset]), sizeof(long long[r.size()]));
   r.zero_justify();
   return r;
}

BigInt BigInt::shift_left (int ds) {
   BigInt r(0);
   r.offset = this->offset - ds;
   memcpy(&(r.num[r.offset]), &(this->num[this->offset]), sizeof(long long[this->size()]));
   return r;
}

BigInt BigInt::karatsuba(BigInt &x, BigInt &y){
   int tope = 260;
   if(x.size() < tope || y.size() < tope){
      BigInt ret = x*y;
      return ret;
   }

   int m = (max(x.size(), y.size()) + 1) >> 1;
   
   BigInt x0 = x.truncate(x.size()-m);
   BigInt x1 = x.shift_right(m);


   BigInt y0 = y.truncate(y.size()-m);
   BigInt y1 = y.shift_right(m);

   BigInt z0 = karatsuba(x0, y0);
   BigInt z2 = karatsuba(x1, y1);
   
   BigInt x1_plus_x0 = x1 + x0;
   BigInt y1_plus_y0 = y1 + y0;
   BigInt z1 = karatsuba(x1_plus_x0, y1_plus_y0) - z0 - z2;   
   
   
   BigInt z2_shift = z2.shift_left(2*m);
   BigInt z1_shift = z1.shift_left(m);
   BigInt ret = z2_shift + z1_shift; 
   return ret + z0;   
}

int main () {
   int cases; 

	char num[10001];
   char num2[10001];
	
   scanf("%d", &cases);
   
   for(int i = 0; i < cases; i++){
      scanf("%s%s", num, num2);
      BigInt n1(num,strlen(num)), n2(num2, strlen(num2));
   	n2 = n2.karatsuba(n1,n2);
	   n2.print();
   }
   
   return 0;
}

