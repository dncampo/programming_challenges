/**
 * Title: The Fibonacci Primes
 * URL: http://uva.onlinejudge.org/external/102/10236.html
 * Resources of interest:
 * Solver group: Yeyo	
 * Contact e-mail: sergio.jose.delcastillo at gmail dot com
 * Description of solution:
 	Para esta solucion se parte de que los numeros de fibonacci que sonn primos relativos
 	son todos los numeros de fibonacci que se conrresponden con un n primo y además el 4.
 	Por lo tanto se utiliza una criba para calcular los primeros 22000 primos y luego se 
 	calcula los fibonacci primes. Se utiliza un tipo de dato BigInt para guardar los numeros de 
 	fibonacci ya que son muy grandes. Luego para cada numero de fibonacci primes se obtienen los 
 	nueve primeros digitos y se los guarda en un vector para su posterior impresion de acuerdo a la entrada 
 	segun corresponda.
**/
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define BASE 1000000000000000000 // Base del número
#define SIZE 2897	// Cant. de cifras del numero, en base BASE

class BigInt{
	private:
		long long num[SIZE];
		int offset;
	public:
		BigInt(long long = 0);
		BigInt operator+(BigInt& );
		BigInt &operator=(const BigInt& );
		unsigned get_digits();
};

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

BigInt BigInt::operator+(BigInt &b){ 
// siempre  this > b
/*	if(this->offset < b.offset){
		return (b + *this);
	}*/

	BigInt res;
	long long c = 0;
	int i = SIZE-1;
	long long t;
	
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

BigInt& BigInt::operator=(const BigInt &b){
	this->offset = b.offset;
	
	memcpy(&(this->num[offset]), &(b.num[offset]), sizeof(long long [SIZE-offset+1]));
	
	return *this;
}

unsigned BigInt::get_digits(){
	unsigned base = 1000000000;
	long long res = 1;

	if(SIZE - offset  == 1 || num[offset] >= base ){
		res = num[offset];
	} else {
		res = (num[offset] * base) + num[offset+1] / base;
	}
	
	while(res  >= base) res /= 10;
	
	return res;
}
vector<int> primes;
vector<int> fib;

void criba(int limit){
	char list[limit];	
	memset(list, 1, sizeof(list));

	int d_limit = (int) (sqrt(limit));
	
	for(int i=2; i<=d_limit; i++){
		if(list[i]){
			for(int j=2; j*i<=limit; j++){
				list[j*i] = 0;
			}
		}
	}
    primes.push_back(0);
    primes.push_back(3);    
    primes.push_back(4);        
    
    for(int i = 5; i < limit; i++){
    	if(list[i]){
    		primes.push_back(i);		
    	}
    }	
}

void init_fib_primes(){
	BigInt f[3]; 
	int count = 2;
	int tmp = 2;
	fib.resize(22001);

	f[2] = BigInt(1);
	f[1] = BigInt(1);
	f[0] = BigInt(0);

	for(int index = 1; index < primes.size(); index++){
		while(count < primes[index]){
			tmp  = (tmp +1) % 3;
			f[tmp] = f[(tmp +1)%3]+ f[(tmp + 2) % 3];
			count++;
		} 
		
		if(count == primes[index]){
			fib[index] = f[tmp].get_digits();
		} 
	}
}

int main(){
	criba(249440);    
   init_fib_primes();
	int n ;

	while(~scanf("%d", &n)){
		printf("%d\n", fib[n]);
	}

	return 0;
}
