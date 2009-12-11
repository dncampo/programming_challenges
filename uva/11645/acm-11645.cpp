/**
 * Title: bits
 * URL: http://uva.onlinejudge.org/external/116/11645.html
 * Resources of interest:
 * Solver group: Yeyo - micke
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
    + Para un numero n dado, se realizan los siguientes pasos:
    + 1) Se calcula el numero t mas grande potencia de dos que
    	sea menor a n.
    +	2) La cantidad de bits adyacentes (BA) de t se la tiene precalculada
    	en el vector bits (se accede por la cantidad de bits que se necesitan 
    	para representar t,	es decir, con un indice i tal que 2^i = t):
				    	BA = bits[i]
    	3) Si se cumple que 3t/2 < n se suma a BA la cantidad de bits adyacentes
    	del numero n-t realizando nuevamente al paso 2).
    + 4) si 3t/2 >= n se realiza 3) y ademas se suma (1 + n-3t/2) a BA.
    + 5) Se imprime BA.
    
    Para el vector precalculado de numeros se realiza el siguiente procedimiento:
    - Se desprecian las posiciones 0 y 1.
    - La posicion 2 se incializa a 1.
    - a partir de 3 hasta 63 se realiza el siguiente calculo:
      bits[i]= 2*bits[i-1] + 2^(i-2)
      
    Se utiliza la clase BigInt para representar la solucion
    ya que el tipo de dato mas grande de c++ no es suficiente
    para representar el peor caso.
    
	
**/
// ################## importante para los desarrolladores #######################
// la solucion subida a acm es con printf() y tarda 0.008 y esta solucion tarda 0.012
// cambie los printf por cout y scanf por cin para mayor elegancia en el codigo


#include <iostream> 
using namespace std;

#define BASE 1000000000 // Base del número
#define DIGITS 9	// Cant. de digitos para cada cifra
#define SIZE 3	// Cant. de cifras del numero, en base BASE

class BigInt{
	private:
		unsigned int num[SIZE];
		int offset;
	public:
		BigInt(){} // PARA QUE COMPILE EL ARREGLO!!
		BigInt(unsigned long long );
		BigInt operator+(BigInt );
		BigInt &operator=(BigInt);
		//imprime el numero en base 10.
		void print();
};

BigInt::BigInt(unsigned long long n){
	int i = SIZE-1;
	
	if(n == 0)
		num[i--] = 0;
	
	while(n > 0){
		num[i--] = n % BASE;
		n /= BASE;
	}
	offset = ++i;
}

BigInt BigInt::operator+(BigInt b){
	BigInt res(0);

	unsigned int c = 0;
	int smaller; // offset del numero mas chico
	int bigger; // offset del numero mas grande
	const unsigned int* whosbigger; // cual es el num mas grande

	(this->offset < b.offset) ? (bigger = this->offset, smaller = b.offset, whosbigger = this->num) :
										 (bigger = b.offset, smaller = this->offset, whosbigger = b.num);
	int i = SIZE-1;

	for(; i >= smaller; i--){
		res.num[i] = (c + this->num[i] + b.num[i]) % BASE;
		c = (c + this->num[i] + b.num[i]) / BASE;
	}
	for(; i >= bigger; i--){
		res.num[i] = (c + whosbigger[i]) % BASE;
		c = (c + whosbigger[i]) / BASE;
	}		
	if(c > 0){
		res.num[i] = c;
		res.offset = i;
	}
	else
		res.offset = bigger;

	return res;
}

BigInt& BigInt::operator=(BigInt b){
	this->offset = b.offset;
	
	for(int i = offset; i < SIZE; i++){
		this->num[i] = b.num[i];
	}
	
	return *this;
}

void BigInt::print(){
	int i = offset;
	int c;
	unsigned int temp;
	
	cout << num[i++];
	
	while(i < SIZE){
		c = 0;
		temp = num[i];
		while(temp > 0){
			c++;
			temp /= 10;
		}
		for(int j=0; j<DIGITS-c; j++)
			cout << "0";
		if(num[i] != 0)
			cout << num[i];
		i++;
	}
}

BigInt bits[64];

void init(){
	bits[2] = BigInt(1);
	
	for(int i = 3; i < 64; i++)
		bits[i] = bits[i-1] + bits[i-1] + BigInt( ((unsigned long long) 1) << (i-2)); // fumada de yeyooo :|

}

//Resuelve el problema y lo retorna en el tipo de dato apropiado.
BigInt solve(long long n){
	if(n < 3) return BigInt(0);
	if(n == 3) return BigInt(1);

	unsigned long long aux = 1;	
	int count = 0;
	
	for(; (aux << 1) <= n; aux <<= 1, count++);

	unsigned long long pot = ((unsigned long long) 1) << count;
	BigInt res = bits[count];
	
	if(pot < n){
		if(n >= (pot/2)*3){
			BigInt b(1 + n-3*(pot/2));
			res = b + res;
		}
		res = res + solve(n-pot);
	}
	return res;
}

int main(){
	init();
	long long n;
	int count = 0;
		
	cin >> n ; 
	
	while (n >= 0){
		cout << "Case " << (++count) << ": " ;
		solve(n).print();
		cout << endl;
		cin >> n ; 
	} 

	return 0;
}

