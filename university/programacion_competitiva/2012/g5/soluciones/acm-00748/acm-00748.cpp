/**
 * Title: Exponentiation
 * URL: http://uva.onlinejudge.org/external/7/748.html
 * Resources of interest:
 * Solver group: Leo
 * Contact e-mail: leonardobortoli at yahoo dot com dot ar
 * Description of solution:
 * 	Se utiliza la clase BigInt para almacenar el resultado, modificando el metodo print() para
 * 	que pueda mostrar el punto decimal. Se utiliza el algoritmo trivial para multiplicar numeros
 * 	con decimales (tratar los numeros como enteros, y luego colocar el punto decimal en el
 * 	resultado, calculando previamente cuantos decimales va a tener).
 */

#include <iostream>
#include <cstring>

#define BASE 10 // Base del número
#define DIGITS 1	// Cant. de digitos para cada cifra
#define SIZE 500	// Cant. de cifras del numero, en base BASE

using namespace std;

typedef short data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(long long );

		BigInt operator*(BigInt& );

		bool operator>(const BigInt& );

		BigInt &operator=(const BigInt& );

		void print(int );
		void zero_justify();
};

BigInt pow(BigInt &, long long );
void print_solution(char*, int );

int main(){
	char r[7];
	int n;
	
	while(cin >> r >> n){
		print_solution(r, n);
		cout << endl;
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

void BigInt::print(int dec){
	int limit = SIZE - 1; // Sirve para quitar los decimales iguales a cero. Por ej.:         45.04350000
	for(; num[limit] == 0; limit--) ; //                                              limit =       *
	
	int size = SIZE - offset;

	if(dec >= size){ // Si la cantidad de decimales supera la cantidad de digitos del numero
		putchar('.');
		for(int i = SIZE - dec; i < offset; i++)
			putchar('0');
		for(int i = offset; i <= limit; i++)
			printf("%d", num[i]);
	}
	else{ // Si la cantidad de decimales no supera la cantidad de digitos del numero
		int i = offset;
		for(; i < SIZE - dec; i++)
			printf("%d", num[i]);
		putchar('.');
		for(; i <= limit; i++)
			printf("%d", num[i]);
	}
}

void print_solution(char* r, int n){
	unsigned size = strlen(r);
	
	int j = size - 1;
	for(; j >= 0 && r[j] == '0'; j--) ; // No se tienen en cuenta los ultimos digitos decimales iguales a cero
	
	int i = j;
	int num = 0; // Numero que quedaria al quitarle el punto decimal
	int b = 1;
	int dec_count = 0; // Cantidad de decimales luego del punto
	for(; r[i] != '.'; i--, b *= 10){
		num += (r[i] - '0') * b;
		dec_count++;
	}
	
	i--;
	for(; i >= 0; i--, b *= 10)
		num += (r[i] - '0') * b;
		
	BigInt int_value(num), res;
	res = pow(int_value, n);
	
	int res_dec_count = dec_count * n; // Cantidad de decimales del resultado
	
	res.print(res_dec_count);
}

