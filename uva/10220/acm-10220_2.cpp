/** 
 * Title: I Love Big Numbers!
 * URL: http://online-judge.uva.es/p/v102/10220.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se calculan los factoriales hasta el número 1000 y se los almacena en un arreglo.
   + Sea N la entrada, se consulta el arreglo en el índice N, se suman los dígitos de
   dicho valor y se imprime el resultado.
	
**/


#include <iostream>
#include <string>

#define MAX_DIG 2670 //cantidad de dígitos de 1000!
#define MAX_FAC 1001

using namespace std;

// crea todos los factoriales (de 0! a 1000!)
void init(void);

typedef unsigned short ushort;

class Huge_int {
	friend ostream &operator<< (ostream &, const Huge_int &); 

	private:
		// arreglo de digitos!!
		ushort digits[MAX_DIG];
		// a partir de offset comienzan los numeros!
		ushort offset;
		// operacion auxiliar para realizar la multiplicación!
		void mul(Huge_int orig, Huge_int &acum, ushort num, ushort ds);

	public:
		Huge_int() {}
		Huge_int(const ushort);
		const Huge_int operator* (ushort);
		//const Huge_int& operator+ (const Huge_int);
		const Huge_int& operator= (const Huge_int);
};

// arreglo numeros largos que guarda los factoriales de 1! a 1000!
Huge_int fact[MAX_FAC];

int main(){
	ushort num;
	init();
	while(cin >> num)
		cout << fact[num] << endl;

	return 0;
}

void init(void){
	fact[0] = Huge_int(1);
	fact[1] = Huge_int(1);
	for(ushort i=2; i < MAX_FAC; i++){
		fact[i] = fact[i-1] * i;
	}
}

Huge_int::Huge_int(const ushort tiny){
	digits[MAX_DIG-1] = tiny;
	offset = MAX_DIG-1;
}


const Huge_int& Huge_int::operator= (const Huge_int op){
	offset = op.offset;
	for(ushort i=op.offset; i < MAX_DIG; i++){
		digits[i] = op.digits[i];
	}
	return *this;
}


void Huge_int::mul(Huge_int orig, Huge_int &acum, ushort num, const ushort ds){
	ushort carry=0;
	ushort i=MAX_DIG-1;
	Huge_int temp = acum;
	for(; i >= orig.offset; i--){
		carry += num * orig.digits[i];

		if(i-ds < acum.offset) {
			acum.offset--;
			acum.digits[i-ds] = carry % 10;	
		} else{
			acum.digits[i-ds] += carry % 10;

			ushort c=0, index;
			for(index = i-ds; c != 0 || index == i-ds; index--){
				if(index < acum.offset){
					acum.offset--;
					acum.digits[index]= 0;
				}
				acum.digits[index] = acum.digits[index]+c;
				c = acum.digits[index] / 10;
				acum.digits[index] %= 10;	
			}
		}

		carry /= 10;
	}

	if(carry > 0){
		if(i-ds<acum.offset){
			acum.offset--;
			acum.digits[i-ds] = carry;
		} else acum.digits[i-ds] += carry;
	}
}

const Huge_int Huge_int::operator* (ushort num){
	Huge_int acum(0);
	ushort ds=0;
	while(num > 0){
		mul(*this,acum,num%10,ds++);
		num /= 10;
	}
	return acum;
}

ostream &operator<< (ostream &out, const Huge_int &op){
	unsigned sum = 0;
	for(ushort a=op.offset; a<MAX_DIG; a++)
		sum += op.digits[a];
	
	out << sum;
	return out;
}

//EOF

