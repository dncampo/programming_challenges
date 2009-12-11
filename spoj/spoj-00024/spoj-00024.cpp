/**
 * Title: Small factorials
 * URL: https://www.spoj.pl/problems/FCTRL2/
 * Resources of interest:
 * Solver group: David-Leo-Yeyo
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Debido al tamaño de las salidas se debe definir un nuevo tipo de dato entero Huge_int de 159 dígitos
	que alcanza para contener al factorial de 100. 
   + Primero se calcula desde 0! hasta 100! y se lo almacena en un vector donde cada índice 'i' representa
	el factorial de 'i'. Luego se busca en dicho vector el factorial del número ingresado.
**/


#include <iostream>
#include <string>

#define MAX_DIG 159 //cantidad de dígitos de 1000!
#define MAX_FAC 101

using namespace std;
void init(void);
typedef unsigned short us;

class Huge {
	friend ostream &operator<< (ostream &, const Huge &); 

	private:
		us dig[MAX_DIG];
		us off;
		void mul(Huge orig, Huge &ac, us num, us ds);

	public:
		Huge() {}
		Huge(const us);
		const Huge operator* (us);
		const Huge& operator= (const Huge);
};
Huge fact[MAX_FAC];

int main(){
	us num;
	init();
	us times;
	cin >> times;
	for(us a=0; a < times; a++){	
		cin >> num;
		cout << fact[num] << endl;
	}
	return 0;
}
void init(void){
	fact[0] = Huge(1);
	fact[1] = Huge(1);
	for(us i=2; i < MAX_FAC; i++){
		fact[i] = fact[i-1] * i;
	}
}
Huge::Huge(const us tiny){
	dig[MAX_DIG-1] = tiny;
	off = MAX_DIG-1;
}
const Huge& Huge::operator= (const Huge op){
	off = op.off;
	for(us i=op.off; i < MAX_DIG; i++){
		dig[i] = op.dig[i];
	}
	return *this;
}
void Huge::mul(Huge orig, Huge &ac, us num, const us ds){
	us car=0;
	us i=MAX_DIG-1;
	Huge temp = ac;
	for(; i >= orig.off; i--){
		car += num * orig.dig[i];

		if(i-ds < ac.off) {
			ac.off--;
			ac.dig[i-ds] = car % 10;	
		} else{
			ac.dig[i-ds] += car % 10;
			us c=0, idx;
			for(idx = i-ds; c != 0 || idx == i-ds; idx--){
				if(idx < ac.off){
					ac.off--;
					ac.dig[idx]= 0;
				}
				ac.dig[idx] = ac.dig[idx]+c;
				c = ac.dig[idx] / 10;
				ac.dig[idx] %= 10;	
			}
		}
		car /= 10;
	}
	if(car > 0){
		if(i-ds<ac.off){
			ac.off--;
			ac.dig[i-ds] = car;
		} else ac.dig[i-ds] += car;
	}
}
const Huge Huge::operator* (us num){
	Huge ac(0);
	us ds=0;
	while(num > 0){
		mul(*this,ac,num%10,ds++);
		num /= 10;
	}
	return ac;
}

ostream &operator<< (ostream &out, const Huge &op) {
	for(us a=op.off; a<MAX_DIG; a++) out << op.dig[a];
	return out;
}

//EOF
