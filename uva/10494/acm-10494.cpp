/**
 * Title: If We Were a Child Again
 * URL: http://online-judge.uva.es/p/v104/10494.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utiliza la herramienta de BigInt para resolver el problema.
	+ Sólo se usan la división entera y el módulo, y otros métodos auxiliares a éstos.

**/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define BASE 1000000000 // Base del número
#define DIGITS 9	// Cant. de digitos para cada cifra
#define SIZE 3000	// Cant. de cifras del numero, en base BASE

using namespace std;

typedef long long data_type;

class BigInt{
	public:
		data_type num[SIZE];
		int offset;

		BigInt();
		BigInt(long long );
		BigInt(const BigInt & ); //constructor por copia!!
		BigInt(char *, const int );
		
		BigInt &operator<<=(const int );
		BigInt operator+(BigInt& );
		BigInt operator-(BigInt& );
		BigInt operator/(BigInt& );
		BigInt operator*(BigInt& );
		BigInt operator%(BigInt& );

		bool operator>(const BigInt& );
		bool operator<(const BigInt& );
		bool operator>=(const BigInt& );
		bool operator<=(const BigInt& );
		bool operator==(const BigInt& );
		bool operator!=(const BigInt& );

		BigInt &operator=(const BigInt& );

		void print();
		void zero_justify();
};

int main(){

	char num[SIZE];
	char num2[SIZE];
	char op;

	while(cin >> num >> op >> num2){
		BigInt n1(num,strlen(num));
		BigInt n2(num2, strlen(num2));
		BigInt r;
		if ('/' == op)
			r = n1 / n2;
		else
			r = n1 % n2;

		r.print ();

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
	
	memcpy(this->num, b.num, sizeof(b.num));
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

bool BigInt::operator<(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset)
		return this->offset > b.offset;

	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	if(ds == SIZE) return false; // son iguales

	return this->num[ds] < b.num[ds];
}

bool BigInt::operator>=(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset)
		return this->offset < b.offset;

	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	if(ds == SIZE) return true; // son iguales

	return this->num[ds] > b.num[ds];
}

bool BigInt::operator<=(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset)
		return this->offset > b.offset;

	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	if(ds == SIZE) return true; // son iguales

	return this->num[ds] < b.num[ds];
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

bool BigInt::operator!=(const BigInt &b){
	// preguntar por los offset.
	if(this->offset != b.offset){
		return true;
	}
	// comparar cuando tiene el mismo offset
	int ds = offset;

	while (ds < SIZE && this->num[ds] == b.num[ds]) ds++;

	return ds < SIZE;
}

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;

	memcpy(this->num, b.num, sizeof(b.num));

	return *this;
}

BigInt& BigInt::operator<<=(const int d){
	if(num[offset] == 0) return *this;

	int i = offset - d;
	int limit = SIZE - d;
	for(; i < limit; i++)
		num[i] = num[i + d];
	for(; i < SIZE; i++)
		num[i] = 0;
	offset -= d;

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

BigInt BigInt::operator-(BigInt &b){
	BigInt res;

	if(*this < b){
		// Esto se hace para que el binary_search sepa que res es negativo.
		// No afecta a ningun otro operador.
		res.num[SIZE-1] = -1;
		res.offset = SIZE - 1;
	}
	else{
		int i = SIZE-1;
		data_type temp;
		data_type borrow = 0;

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
	}

	return res;
}

BigInt BigInt::operator/(BigInt &b){
	data_type binary_search(BigInt &row, BigInt &b);

	if(b.offset == SIZE-1 && b.num[SIZE-1] == 0){
		cout << "ERROR: division por cero" << endl;
		return *this;
	}

	BigInt res;

	if(*this < b)
		return res;

	BigInt row;

	for(int i=this->offset; i<SIZE; i++){
		row <<= 1;
		row.num[SIZE-1] = this->num[i];
		res <<= 1;

		if(row >= b)
			res.num[SIZE - 1] = binary_search(row, b);
	}

	return res;
}

data_type binary_search(BigInt &row, BigInt &b){
	BigInt res, mul, zero;
	data_type medio;

	for(data_type desde = 0, hasta = BASE-1; desde <= hasta;) {
		medio = (desde + hasta) / 2;
		BigInt i(medio);
		mul = i * b;
		res =  row - mul;
		if(desde == hasta) { 
			if(zero <= res && res < b){
				row = res;
				return medio;
			}
		}
			
		if(zero <= res && res < b){
			row = res;
			return medio;
		} else if(res < zero)
			hasta = medio - 1;
		else
			desde = medio + 1;
	}
	return -1;
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

BigInt BigInt::operator%(BigInt &b){
	BigInt div = *this / b;
	BigInt mul = b * div;
	return *this - mul;
}

void BigInt::zero_justify(){
	for(; num[offset] == 0 && offset < SIZE-1; offset++) ;
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
	cout << endl;
}

