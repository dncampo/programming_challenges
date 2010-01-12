/** 
 * Title: Fast Multiplication(optimizado)
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
#define SIZE 2225	// Cant. de cifras del numero, en base BASE

using namespace std;

class BigInt{
	public:
		int num[SIZE];
		int offset;

		BigInt();
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt(char *, const int );
		
		void operator+=(const BigInt& );
		void operator-=(const BigInt&);
		BigInt operator*(const BigInt& );
		BigInt operator=(const BigInt& );
		bool operator==(const BigInt& );

		void print();
		inline int size();
		void zero_justify();
		BigInt karatsuba(BigInt &x, BigInt &y);
		//métodos usados por karatsuba
		BigInt truncate(int n);
		BigInt shift_right(int n);
		BigInt shift_left(int ds);
};

BigInt::BigInt(){
   memset(this->num, 0, sizeof(num));  
	this->offset = SIZE-1;
}

BigInt::BigInt(char* n, int size){
   memset(this->num, 0, sizeof(num));
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
bool BigInt::operator==(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset){
		return false;
	}
	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	return ds == SIZE;
}

BigInt::BigInt(const BigInt &b){
	memcpy(this->num, b.num, sizeof(this->num));	
	this->offset = b.offset;
}

BigInt BigInt::operator=(const BigInt &b){
	if(b.offset <= offset) //SIZEB >= SIZEA
	  	memcpy(&(this->num[b.offset]), &(b.num[b.offset]), sizeof(int [SIZE - b.offset]));
	else{ //SIZEB < SIZEA
	  	memcpy(&(this->num[this->offset]), 0, sizeof(int [b.offset - this->offset]));
	  	memcpy(&(this->num[b.offset]), &(b.num[b.offset]), sizeof(int [SIZE - b.offset]));	
   }

	this->offset = b.offset;
	return *this;
}

void BigInt::operator+=(const BigInt &b){ 
	int c = 0, t = 1;
   int m = min(this->offset, b.offset)-1;
   if(m < 0)
      m = 0;
     
	int *this_num = &num[SIZE - 1];
	const int *b_num = &b.num[SIZE - 1];

   for (; this_num >= &num[m]; this_num--, b_num--) {
		t =  c + *this_num + *b_num;
		c = t / BASE;
		*this_num = t - c * BASE;	
	}

   offset = (m > 1) ? m-1 : 0;
   zero_justify();
}

void BigInt::operator-=(const BigInt &b){
	int temp;
	int borrow = 0;
	int *this_num = &num[SIZE - 1];
	const int *b_num = &b.num[SIZE - 1];
		
	for(; this_num >= &(this->num[this->offset]); this_num--, b_num--){
		temp = (b_num >= &(b.num[b.offset]) ) ? (*this_num - borrow - *b_num) : (*this_num - borrow);
		if(*this_num > 0)
			borrow = 0;
		if(temp < 0){
			temp += BASE;
			borrow = 1;
		}
		*this_num = temp;
	}

	this->zero_justify();
}	

BigInt BigInt::operator*(const BigInt &b){
	BigInt res;
	const BigInt* pA = this;
	const BigInt* pB = &b;

	if(this->offset > b.offset){
		pA = &b;
		pB = this;
	}
	
	unsigned delta = 1;
	unsigned  carry = 0;
	res.offset = -SIZE + pA->offset + pB->offset;
	int *ppos;
	unsigned long long ppos_tmp;
   const int *i, *j;
	
	for( i = &(pA->num[SIZE - 1]); i >= &(pA->num[pA->offset]);  i--, delta++) {
		ppos = &res.num[SIZE - delta];
		carry = 0;

		for( j = &(pB->num[SIZE - 1]); j >= &(pB->num[pB->offset]);  j--, ppos--) {
			ppos_tmp = ((unsigned  long long)*ppos)  + carry + ((unsigned long long)*j) * ((unsigned  long long)*i);
			carry = ppos_tmp / BASE;
			(*ppos) = ppos_tmp - carry * BASE;
		}
		(*ppos) = carry;
	}
	(*ppos) = carry;

	res.zero_justify(); 
	
	return res;
}

void BigInt::zero_justify(){
	for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
}

int BigInt::size(){
   return SIZE - offset;
}

BigInt BigInt::truncate(int n){
   BigInt r;
   r.offset = this->offset + n;
   
   if (0 >= r.size()) {
      return r;
   }   
   memcpy(&(r.num[r.offset]), &(this->num[r.offset]), sizeof(int[r.size()]));   
   r.zero_justify();
   return r;
}

BigInt BigInt::shift_right(int ds){
   BigInt r;
   r.offset = this->offset + ds;
   if (0 >= r.size()) {
      return r;
   }
 
   memcpy(&(r.num[r.offset]), &(this->num[this->offset]), sizeof(int[r.size()]));
   r.zero_justify();
   return r;
}

BigInt BigInt::shift_left(int ds) {
	int old_offset = this->offset;
	int old_size = this->size();

   this->offset -= ds;
   memcpy(&(this->num[this->offset]), &(this->num[old_offset]), sizeof(int[old_size]));
	memset(&(this->num[SIZE-ds]), 0, ds * sizeof(int));
   return *this;
}


BigInt BigInt::karatsuba(BigInt &x, BigInt &y){
   int tope = 50;
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

   x1 += x0;
   y1 += y0;

   BigInt z1 = karatsuba(x1, y1);
	z1 -= z0;
	z1 -= z2;   
   
	z2.shift_left(m << 1);
	z1.shift_left(m);
	z2 += z1;
	z2 += z0;

   return z2;   
}


void BigInt::print(){
	char n[9*this->size()+1];
	int *it = &(this->num[SIZE-1]);
	int tmp1, tmp2, count, i = 9*this->size();	
	n[i--] = '\0';

	for(; it >= &(this->num[this->offset]);it--){
		tmp1 = *it;
		count = 0;

		while(tmp1 > 0 ){
			count++;
			tmp2 = tmp1 / 10;
			n[i--] = (tmp1 - tmp2*10) +'0';
			tmp1 = tmp2;			
		}

		while(count++ < DIGITS)
			n[i--] = '0';
	}
	while(n[++i] == '0');

	printf("%s\n", &n[i]);
}

int main () {
   int cases; 
	char num[10001], num2[10001];

   scanf("%d", &cases);
	   
   for(int i = 0; i < cases; i++){
   	scanf("%s%s", num, num2);
			
      BigInt n1(num,strlen(num)), n2(num2, strlen(num2));

   	n2.karatsuba(n1,n2).print();
   }
   return 0;
}


