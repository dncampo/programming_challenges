/**
 * Title: Factorial Frequencies 
 * URL: http://online-judge.uva.es/p/v3/324.html
 * Resources of interest:
 * Solver group: Yeyo
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
   primero se precalculan todos los factoriales y despues para cada entrada se calcula 
   la cantidad de numeros 1, 2, 3, . y 9 que tiene y se imprime  la salida.
**/

#include <iostream>
#include <iomanip>  
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 10 // Base del número
#define DIGITS 1	// Cant. de digitos para cada cifra
#define SIZE 782	// Cant. de cifras del numero, en base BASE

using namespace std;

class BigInt{
	public:
		int num[SIZE];
		int offset;

		BigInt(long long =0);
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt operator*(BigInt& );
		BigInt &operator=(const BigInt& );

		void zero_justify();
		void print_solution();
};

int main(){
   BigInt list[367];

   list[1] = BigInt(1);

   for(int i = 2; i <= 366; i++){
      BigInt b(i) ;
      list[i] = b * list[i-1];
   }

   int n;
   
   cin >> n;
   
   while(n != 0){
      cout << n << "! --" << endl;
      list[n].print_solution();
      cin >> n;
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

BigInt::BigInt(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(this->num, b.num, sizeof(b.num));
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

	int carry = 0;
	res.offset = -SIZE + pA->offset + pB->offset;

	memset(&res.num[res.offset], 0, sizeof(int[SIZE - res.offset]));
	
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

void BigInt::print_solution(){
   int s[10] = {0};
   for(int i = offset; i< SIZE; i++){
      s[num[i]]++;
   }    

   cout << "   (0)" << setw(5) << s[0] 
        << "    (1)" << setw(5) << s[1] 
        << "    (2)" << setw(5) <<s[2] 
        << "    (3)" << setw(5) <<s[3] 
        << "    (4)" << setw(5) << s[4] << endl
        << "   (5)" << setw(5) << s[5]  
        << "    (6)" << setw(5) << s[6] 
        << "    (7)" << setw(5) << s[7] 
        << "    (8)" << setw(5) << s[8] 
        << "    (9)" << setw(5) << s[9] << endl;
}

void BigInt::zero_justify(){
	for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
}

