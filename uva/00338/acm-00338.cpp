/**
 * Title: Long Multiplication
 * URL: http://online-judge.uva.es/p/v3/338.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   Cada par de numeros se lee como enteros, de esta forma
   se evita el problema de los ceros a la izquierda y los 
   espacios en blanco.
   Luego para cada par de numeros se realiza la mulplicacion
   en numeros largos ya que dos numeros de 10 digitos
   superan el tipo de dato primitivo mas grande.
   Luego para imprimir el formato que requiere el problema
   se utilizan solamente los numeros enteros y se va 
   realizando el producto de cada digito del segundo
   numero por el primero y se imprime como corresponde.
**/

#include <iostream>
#include <istream>  
#include <iomanip> 
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 10 // Base del número
#define SIZE 21	// Cant. de cifras del numero, en base BASE

using namespace std;

typedef int data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;
		
		BigInt(long long = 0);
		BigInt operator*(BigInt& );
		BigInt &operator=(const BigInt& );

		void print(int size);
		void zero_justify();
		int size(){
		   return (SIZE-offset);
		}
};

int get_digits(long long n){
   int  count = 0;
   
   if(n == 0) return 1;
   
   while( n > 0){
      count++;
      n /= 10;
   }
   return count;
}

bool single(long long n){
   while( n % 10 == 0 && n >= 10) 
      n /= 10;

   return (n < 10);
}

int main(){
   long long x, y;

   while(scanf("%llu%llu", &x, &y) == 2){
      BigInt a(x), b(y), res = a * b;
      int y_digits = get_digits(y);   
      int x_digits = get_digits(x);   
      int max_digits = max(x_digits, y_digits);
      int size = max(max_digits, res.size());
      
      cout << setw(size) << x << endl;
      cout << setw(size) << y << endl;

      string line = "-";
      
      for(int i = 0; i < max_digits; i++){
         line += "-";
      }
      
      cout << setw(size) << line << endl;
      
      if(x != 0 && !single(y)){
         int count = 1;      
         for(int i = 0; i < y_digits; i += count){
            count = 1;
            
            while( y % 10 == 0 ){
               count ++;
               y /= 10;
            }
            
            cout << setw(size-i-count+1) << x* (y % 10)  << endl;
            y /= 10;
         }
         
         for(int i =max_digits; i < size; i++){
            line += "-";
         }   
         
         cout << setw(size) << line << endl;   
      }
      
      res.print(size);
      cout << endl << endl;
   }
   return 0;
}

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

void BigInt::print(int size){
   if(size > this->size()){
      for(int i = size-this->size(); i > 0; i--){
         cout << " ";
      }
   }
	
	for(int i = offset; i < SIZE; i++){
   	cout << num[i];
   }
}

