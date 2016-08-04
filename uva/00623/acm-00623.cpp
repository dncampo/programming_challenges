/*
Title: 500! factorial
Tags: bigint, factorial, big multiplication, numbers, precalculation
URL: http://icpcres.ecs.baylor.edu/onlinejudge/external/6/623.html
Resources of interest:
Solver: David N. Campo, Sergio Del Castillo, Leonardo Bórtoli
Contact e-mail: dncampo at gmail dot com
Solution's notes:
    + A new class to encapsulate the big integer is created
    + A multiplication method is needed in order to perform the operation
    + All factorials, from 0! to 1000! are precalculated and stored in an array
    + that is queried later on.
*/


#include <iostream>
#include <string>

#define MAX_DIG 2670 //Max qty of digits of 1000!
#define MAX_FAC 1001

using namespace std;

// pre calculate all factorials (from 0! to 1000!)
void init(void);

typedef unsigned short ushort;

class Huge_int {
	friend ostream &operator<< (ostream &, const Huge_int &); 

	private:
		ushort digits[MAX_DIG];
		// the num begins in offset!
		ushort offset;
		// multiplication
		void mul(Huge_int orig, Huge_int &acum, ushort num, ushort ds);

	public:
		Huge_int() {}
		Huge_int(const ushort);
		const Huge_int operator* (ushort);
		const Huge_int& operator= (const Huge_int);
};

// array to store all pre calculated factorials
Huge_int fact[MAX_FAC];

int main(){
	ushort num;
	init();
	while(cin >> num){
		cout << num << "!" << endl;
		cout << fact[num] << endl;
	}
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
	for(ushort a=op.offset; a<MAX_DIG; a++) out << op.digits[a];
	return out;
}
